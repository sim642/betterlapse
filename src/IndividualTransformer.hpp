#ifndef BETTERLAPSE_INDIVIDUALTRANSFORMER_HPP
#define BETTERLAPSE_INDIVIDUALTRANSFORMER_HPP

#include "Transformer.hpp"

class IndividualTransformer : public Transformer
{
public:
    IndividualTransformer(const std::string &name);

protected:
    void doTransform(std::vector<cv::Mat> &frames) override;
    virtual void doTransform(cv::Mat &frame) = 0;
};


#endif //BETTERLAPSE_INDIVIDUALTRANSFORMER_HPP
