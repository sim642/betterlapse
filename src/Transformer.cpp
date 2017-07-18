#include <iostream>
#include "Transformer.hpp"

Transformer::Transformer(const std::string &name) : name(name)
{

}

void Transformer::transform(std::vector<cv::Mat> &frames)
{
    std::cout << name << ":" << std::endl;
    doTransform(frames);
}
