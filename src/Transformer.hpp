#ifndef BETTERLAPSE_TRANSFORMER_HPP
#define BETTERLAPSE_TRANSFORMER_HPP

#include <vector>
#include <opencv2/core/mat.hpp>

class Transformer
{
public:
    Transformer(const std::string &name);

    void transform(std::vector<cv::Mat> &frames);

protected:
    virtual void doTransform(std::vector<cv::Mat> &frames) = 0;

    std::string name;
};

#endif //BETTERLAPSE_TRANSFORMER_HPP
