#include <opencv2/opencv.hpp>
#include "UnsharpMaskTransformer.hpp"

UnsharpMaskTransformer::UnsharpMaskTransformer() : IndividualTransformer("Unsharp mask")
{

}

void UnsharpMaskTransformer::doTransform(cv::Mat &frame)
{
    cv::Mat blurred;
    cv::GaussianBlur(frame, blurred, cv::Size(), sigma, sigma);
    cv::Mat highContrastMask = cv::abs(frame - blurred) >= threshold;
    cv::Mat sharpened = frame * (1 + amount) - blurred * amount;
    sharpened.copyTo(frame, highContrastMask);
}
