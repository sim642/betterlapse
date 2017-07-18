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
    double threshold = 5;
    double amount = 0.5;
};


#endif //BETTERLAPSE_UNSHARPMASKTRANSFORMER_HPP
