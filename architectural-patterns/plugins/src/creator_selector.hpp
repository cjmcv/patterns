#ifndef PM_CREATOR_SELECTOR_HPP
#define PM_CREATOR_SELECTOR_HPP

#include <config.hpp>
#include <icreator.hpp>

#include <vector>
#include <list>
#include <map>

namespace pm {

class CreatorSelector {

public:
  /// New CreatorSelector instances are not publicly allowed.
  CreatorSelector();

  /// Clears all hosted providers
  ~CreatorSelector();

  ////////////////////////////////////////////////////////////
  /// \brief Add provider.
    /// ICreator type and version are checked. Only known and
    /// valid provider types are accepted.
    ///
    /// \param provider ICreator to be added.
    /// \return True if the provider is accepted.
    ///
    ////////////////////////////////////////////////////////////
  bool Add(ICreator* provider);
  void Delete(const std::vector<ICreator*>* providers);
  ////////////////////////////////////////////////////////////
  /// \brief Ckeck if a provider type is registered.
  /// \param type ICreator type id.
  /// \return True if the type is registered
  ////////////////////////////////////////////////////////////
  bool Knows(const int type_flag) const;

  ////////////////////////////////////////////////////////////
  /// \brief Register a type of providers.
  ///
  /// \param type ICreator type.
  /// \param version Current version of that provider type.
  /// \param lowestVersion Lowest compatible version of that provider type.
  ////////////////////////////////////////////////////////////
  void RegisterType(const int type_flag, int lowest_version, int highest_version);

  ////////////////////////////////////////////////////////////
  /// \brief Get providers of a certain type.
  /// \param type ICreator type.
  /// \return Pointer to the list of providers of that \a type,
  /// or NULL if \a type is not registered.
  ////////////////////////////////////////////////////////////
  const std::list<ICreator*>* GetCreator(const int type) const;

  ////////////////////////////////////////////////////////////
  /// \brief Clears all Added providers.
  ////////////////////////////////////////////////////////////
  void ClearAll();

  ////////////////////////////////////////////////////////////
  /// \brief Validate provider type and version.
  /// \return True if the provider is acceptable.
  ////////////////////////////////////////////////////////////
  bool Validate(ICreator* provider) const;

private:
  const std::tuple<int, int>* GetVersion(const int type) const;

private:
  ////////////////////////////////////////////////////////////
  /// \brief Structure with information about a provider type.
  ////////////////////////////////////////////////////////////
  typedef std::map<int, std::list<ICreator*> > CreatorsMap;
  CreatorsMap known_types_;        ///< Map of registered types.

  /// type对应虚基类，注册时需要提供版本限制。
  /// type派生下的实现类，在加入是会有自己的版本号。
  /// 多个实现类各自开发可以归属同一个type，各版本可以不一致。
  /// 通过对虚基类中设定的版本限制来对各自开发的实现类进行约束。
  typedef std::map<int, std::tuple<int, int> > TypeVersionLimit;
  TypeVersionLimit version_limit_;
};

}   // namespace pm

#endif // PM_CREATOR_SELECTOR_HPP