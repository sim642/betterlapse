#include <iostream>
#include <boost/filesystem.hpp>
#include <vector>
#include <algorithm>
#include <iterator>
#include <opencv2/opencv.hpp>
#include <cmath>

using namespace std;
namespace fs = boost::filesystem;

int main()
{
    const double seconds = 15.0;
    const double fps = 30.0;
    const size_t frameCount = round(seconds * fps);

    const fs::path imagesPath("./tl2/");
    const fs::path framesPath("./frames/");
    const fs::path videoPath("./out.avi");
    const int videoFourCC = cv::VideoWriter::fourcc('H', '2', '6', '4');
    fs::create_directories(framesPath);

    vector<fs::path> imagePaths;
    copy(fs::directory_iterator(imagesPath), fs::directory_iterator(), back_inserter(imagePaths));
    sort(imagePaths.begin(), imagePaths.end());
    const size_t imageCount = imagePaths.size();
    
    vector<size_t> frameImages(frameCount);
    for (size_t frame = 0; frame < frameCount; frame++)
    {
        frameImages[frame] = (static_cast<double>(imageCount - 1) / (frameCount - 1)) * frame;
    }

    
    const cv::Size size = cv::imread(imagePaths.front().string()).size();

    cv::VideoWriter videoWriter(videoPath.string(), videoFourCC, fps, size);

    cv::Mat prevSum(size, CV_32SC3, cv::Scalar::all(0));
    size_t prevCount = 0;
    for (size_t frameI = 0; frameI < frameCount; frameI++)
    {
        const size_t frameImage = frameImages[frameI];
        const size_t nextFrameImage = frameI < frameCount - 1 ? frameImages[frameI + 1] : imageCount;

        cout << "Frame " << frameI << ", Image: " << frameImage << endl;

        cv::Mat image = cv::imread(imagePaths[frameImage].string());

        cv::Mat nextSum(size, CV_32SC3, cv::Scalar::all(0));
        size_t nextCount = 0;
        for (size_t imageI = frameImage + 1; imageI < nextFrameImage; imageI++)
        {
            cout << "  " << "Next image: " << imageI << endl;
            cv::Mat nextImage = cv::imread(imagePaths[imageI].string());
            cv::add(nextSum, nextImage, nextSum, cv::noArray(), CV_32SC3);
            nextCount++;
        }

        cv::Mat frameSum = prevSum;
        cv::add(frameSum, image, frameSum, cv::noArray(), CV_32SC3);
        frameSum += nextSum;

        cv::Mat frame;
        frameSum.convertTo(frame, CV_8UC3, 1.0 / (prevCount + 1 + nextCount));
        fs::path framePath = framesPath / (to_string(frameI) + ".jpg");
        cv::imwrite(framePath.string(), frame);
        videoWriter << frame;

        prevSum = nextSum;
        prevCount = nextCount;
    }

    return 0;
}