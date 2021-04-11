#ifndef PLUGIN2_HPP
#define PLUGIN2_HPP

#include "interface.hpp"

class TF : public IInference {
public:
  std::string description() {
    return "TF IInference";
  }
};

CREATOR_INHERIT(TF, IInference, 3, "TF");

#endif // PLUGIN2_HPP