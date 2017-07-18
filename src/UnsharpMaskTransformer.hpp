#ifndef BETTERLAPSE_UNSHARPMASKTRANSFORMER_HPP
#define BETTERLAPSE_UNSHARPMASKTRANSFORMER_HPP

#include "IndividualTransformer.hpp"

class UnsharpMaskTransformer : public IndividualTransformer
{
public:
    UnsharpMaskTransformer();

protected:
    void doTransform(cv::Mat &frame) override;

    double sigma = 5;
    double threshold = 3;
    double amount = 1;
};


#endif //BETTERLAPSE_UNSHARPMASKTRANSFORMER_HPP
