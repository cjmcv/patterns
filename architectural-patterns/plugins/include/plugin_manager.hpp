#ifndef PM_PLUGIN_MANAGER_HPP
#define PM_PLUGIN_MANAGER_HPP

#include <config.hpp>

#include <string>
#include <vector>
#include <map>
#include <list>

namespace pm{

class PluginLoader;

class ICreator;
class CreatorSelector;

class PM_API PluginManager {
public:
  PluginManager();
  ~PluginManager();

  ////////////////////////////////////////////////////////////
  /// \brief Load a plugin given it's path
  ///
  /// \param path Path for the plugin, including plugin name. File extension
  /// may be included, but is discouraged for better cross platform code.
  /// If file extension isn't present on the path, Pluma will deduce it
  /// from the operating system.
  ///
  /// \return True if the plugin is successfully loaded.
  ////////////////////////////////////////////////////////////
  bool Load(const std::string& path);

  ////////////////////////////////////////////////////////////
  /// \brief Unload a plugin.
  ///
  /// \param plugin_name Name or path of the plugin.
  /// \return True if the plugin is successfully unloaded,
  /// false if no such plugin exists on the manager.
  ////////////////////////////////////////////////////////////
  bool Unload(const std::string& plugin_name);

  // Unload all loaded plugins.
  void UnloadAll();

  // Directly add a new provider.
  bool AddCreator(ICreator* provider);

  ////////////////////////////////////////////////////////////
  /// \brief Get the name of all loaded plugins.
  /// \param plugin_names A vector to fill with the plugins names.
  void GetLoadedPlugins(std::vector<const std::string*>& plugin_names);

  // Check if a plug-in is loaded.
  bool IsLoaded(const std::string& plugin_name);

  ////////////////////////////////////////////////////////////
  /// \brief Register a provider type
  ///
  /// \param type ICreator type.
  /// \param version Current version of that provider type.
  /// \param lowestVersion Lowest compatible version of that provider type.
  ///
  /// \see CreatorSelector::RegisterType
  ///
  ////////////////////////////////////////////////////////////
  void RegisterType(const int type_flag, int lowest_version, int highest_version);

  ////////////////////////////////////////////////////////////
  /// \brief Get the stored providers of a certain type.
  ////////////////////////////////////////////////////////////
  template<typename CreatorType>
  void GetCreator(std::vector<CreatorType*>& providers, const int type) {
    const std::list<ICreator*>* lst = GetCreator(type);
    if (!lst) return;

    providers.clear();
    std::list<ICreator*>::const_iterator it;
    for (it = lst->begin(); it != lst->end(); ++it)
      providers.push_back(static_cast<CreatorType*>(*it));
  }

private:
  const std::list<ICreator*>* GetCreator(const int type);

  PluginLoader *plugin_loader_;
  CreatorSelector *creator_selector_;
};

}   // namespace pm

#endif // PM_PLUGIN_MANAGER_HPP