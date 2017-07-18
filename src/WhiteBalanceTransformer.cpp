#include <opencv2/xphoto.hpp>
#include "WhiteBalanceTransformer.hpp"

WhiteBalanceTransformer::WhiteBalanceTransformer() : IndividualTransformer("White balance")
{

}

void WhiteBalanceTransformer::doTransform(cv::Mat &frame)
{
    cv::Ptr<cv::xphoto::SimpleWB> whiteBalance = cv::xphoto::createSimpleWB();
    whiteBalance->balanceWhite(frame, frame);
}
