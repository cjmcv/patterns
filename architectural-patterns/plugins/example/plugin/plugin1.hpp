#ifndef PLUGIN1_HPP
#define PLUGIN1_HPP

#include "interface.hpp"

class Caffe : public IInference {
public:
  std::string description() {
    return "Caffe IInference";
  }
};

CREATOR_INHERIT(Caffe, IInference, 5, "Caffe");

#endif // PLUGIN1_HPP