#include "CropTransformer.hpp"

CropTransformer::CropTransformer(const cv::Rect &rect) : IndividualTransformer("Crop"), rect(rect)
{

}

void CropTransformer::doTransform(cv::Mat &frame)
{
    cv::Mat cropped;
    frame(rect).copyTo(cropped);
    frame = cropped;
}


