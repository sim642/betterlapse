#ifndef BETTERLAPSE_WHITEBALANCETRANSFORMER_HPP
#define BETTERLAPSE_WHITEBALANCETRANSFORMER_HPP

#include "IndividualTransformer.hpp"

class WhiteBalanceTransformer : public IndividualTransformer
{
public:
    WhiteBalanceTransformer();

protected:
    void doTransform(cv::Mat &frame) override;
};


#endif //BETTERLAPSE_WHITEBALANCETRANSFORMER_HPP
