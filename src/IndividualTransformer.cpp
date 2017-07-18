#include <iostream>
#include "IndividualTransformer.hpp"

IndividualTransformer::IndividualTransformer(const std::string &name) : Transformer(name)
{

}

void IndividualTransformer::doTransform(std::vector<cv::Mat> &frames)
{
    for (size_t frameI = 0; frameI < frames.size(); frameI++)
    {
        std::cout << name << ", Frame: " << frameI << std::endl;
        doTransform(frames[frameI]);
    }
}
