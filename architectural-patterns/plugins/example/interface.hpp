#ifndef PLUGIN_INTERFACE_HPP
#define PLUGIN_INTERFACE_HPP

#include <icreator.hpp>

enum CreatorFlag {
  INFERENCE = 0,
  PREPROCESS = 1,
  POSTPROCESS = 2
};

/////////////////////////////////////////////////////////
/// interface
/// That's the kind of objects that plugins will provide.
/////////////////////////////////////////////////////////
class IInference{
public:
  virtual std::string description() = 0;
};

CREATOR_INTERFACE(IInference, CreatorFlag::INFERENCE);

class IPreprocess {
public:
  virtual std::string description() = 0;
  // (...)
};

CREATOR_INTERFACE(IPreprocess, CreatorFlag::PREPROCESS);

class IPostprocess {
public:
  virtual std::string description() = 0;
  // (...)
};

CREATOR_INTERFACE(IPostprocess, CreatorFlag::POSTPROCESS);

#endif // PLUGIN_INTERFACE_HPP