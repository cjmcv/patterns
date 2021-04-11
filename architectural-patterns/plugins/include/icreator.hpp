#ifndef PM_CREATOR_HPP
#define PM_CREATOR_HPP

#include <config.hpp>
#include <string>

namespace pm {

// interface to provide applications with objects from plugins.
class PM_API ICreator{

public:
  virtual ~ICreator() {}
  /// \brief Get provider type.
  virtual int type() const = 0;
  virtual unsigned int version() const = 0;
};

#define CREATOR_INTERFACE(INTERFACE, TYPE) \
class INTERFACE##Creator : public pm::ICreator { \
private:    \
  int type() const { return TYPE; } \
public: \
  virtual INTERFACE* create() const = 0; \
  virtual unsigned int version() const = 0;\
  virtual std::string key() const = 0; \
}; \
\
template<typename DType> \
struct CreatorType; \
template<> \
struct CreatorType<INTERFACE##Creator> { \
  static const int kFlag = TYPE; \
};

#define CREATOR_TYPE(type) CreatorType<type>::kFlag

#define CREATOR_INHERIT(REAL, VIRTUAL, VERSION, KEY) \
class REAL##Creator : public VIRTUAL##Creator { \
public: \
  VIRTUAL *create() const { return new REAL(); } \
  unsigned int version() const { return VERSION; } \
  std::string key() const { return KEY; } \
};

}   // namespace pm

#endif // PM_CREATOR_HPP