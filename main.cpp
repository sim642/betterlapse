#include <iostream>
#include <boost/filesystem.hpp>
#include <vector>
#include <algorithm>
#include <iterator>
#include <opencv2/opencv.hpp>

using namespace std;
namespace fs = boost::filesystem;

int main()
{
    vector<fs::path> imagePaths;
    copy(fs::directory_iterator("./tl2/"), fs::directory_iterator(), back_inserter(imagePaths));
    sort(imagePaths.begin(), imagePaths.end());

    const cv::Size frameSize = cv::imread(imagePaths.front().string()).size();

    cv::Mat sum(frameSize, CV_32SC3, cv::Scalar::all(0));

    for (auto &p : imagePaths)
    {
        cout << p << endl;
        cv::Mat image = cv::imread(p.string());
        //sum += image;
        cv::add(sum, image, sum, cv::noArray(), CV_32SC3);
    }

    sum /= imagePaths.size();
    cv::Mat avg;
    sum.convertTo(avg, CV_8UC3);
    cv::imwrite("./out.jpg", avg);

    return 0;
}