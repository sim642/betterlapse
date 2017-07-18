#ifndef BETTERLAPSE_CROPTRANSFORMER_HPP
#define BETTERLAPSE_CROPTRANSFORMER_HPP

#include "IndividualTransformer.hpp"

class CropTransformer : public IndividualTransformer
{
public:
    CropTransformer(const cv::Rect &rect);

protected:
    void doTransform(cv::Mat &frame) override;

private:
    cv::Rect rect;
};


#endif //BETTERLAPSE_CROPTRANSFORMER_HPP
