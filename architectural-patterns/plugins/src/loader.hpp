#ifndef PM_PLUGIN_LOADER_HPP
#define PM_PLUGIN_LOADER_HPP

#include <config.hpp>
#include <icreator.hpp>

#include <vector>
#include <string>
#include <map>

namespace pm{
class DLibrary;

// Manages loaded plugins.
class PluginLoader{

public:
  PluginLoader();
  ~PluginLoader();

  void AddLoad();
  void RestLoad();
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
  bool Load(const std::string& path, std::vector<pm::ICreator*> **pvec);

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

  ////////////////////////////////////////////////////////////
  /// \brief Get the name of all loaded plugins.
  /// \param plugin_names A vector to fill with the plugins names.
  void GetLoadedPlugins(std::vector<const std::string*>& plugin_names) const;

  const std::vector<ICreator*>* GetRelatedProviders(const std::string& plugin_name);

  // Check if a plug-in is loaded.
  bool IsLoaded(const std::string& plugin_name) const;

private:
  ////////////////////////////////////////////////////////////
  /// \brief Get the plugin name (without extension) from its path
  ///
  /// \param path Plugin path.
  /// \return Name of the plugin.
  ////////////////////////////////////////////////////////////
  static std::string GetPluginName(const std::string& path);

  ////////////////////////////////////////////////////////////
  /// \brief If the plugin path omits it's extension, this method returns
  /// the path plus the OS specific dll extension.
  /// Return a copy of the path otherwise.
  ///
  /// \param path Plugin path.
  /// \return Path with extension.
  ////////////////////////////////////////////////////////////
  static std::string ResolvePathExtension(const std::string& path);

private:
  /// Signature for the plugin's registration function
  typedef void FnPluginConnector(std::vector<ICreator*> *);
  typedef std::map<std::string, DLibrary*> LibMap;
  LibMap libraries_;   // Map containing the loaded libraries

  /// 绑定插件名和对应的所有provider，方便后面指定清除。
  /// 这里providers可能会有部分因版本号不符合，未被加入CreatorSelector中。
  typedef std::map<std::string, std::vector<ICreator*> > CreatorMap;
  CreatorMap creators_;

  /// 临时保存当前读取的插件信息
  DLibrary *temp_lib_;
  std::string temp_name_;
  std::vector<ICreator*> temp_pvec_;
};

}   // namespace pm

#endif // PM_PLUGIN_LOADER_HPP