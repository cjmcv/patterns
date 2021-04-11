#include <loader.hpp>
#include <dlibrary.hpp>
#include <cstdio>

namespace pm{

////////////////////////////////////////////////////////////
PluginLoader::PluginLoader(){
    // Nothing to do
}

////////////////////////////////////////////////////////////
PluginLoader::~PluginLoader(){
    UnloadAll();
}

////////////////////////////////////////////////////////////
bool PluginLoader::Load(const std::string& path, std::vector<pm::ICreator*> **pvec) {
  temp_name_ = GetPluginName(path);
  std::string realPath = ResolvePathExtension(path);
  temp_lib_ = DLibrary::Load(realPath);
  if (!temp_lib_) return false;

  FnPluginConnector* registerFunction;
  registerFunction = reinterpret_cast<FnPluginConnector*>(temp_lib_->GetSymbol("connect"));

  if (!registerFunction) {
    fprintf(stderr, "Failed to initialize plugin \"%s\": connect function not found\n", temp_name_.c_str());
    delete temp_lib_;
    return false;
  }

  // try to initialize plugin
  temp_pvec_.clear();
  registerFunction(&temp_pvec_);
  *pvec = &temp_pvec_;
  return true;
}

void PluginLoader::RestLoad() {
  fprintf(stderr, "Self registry failed on plugin \"%s\".\n", temp_name_.c_str());

  delete temp_lib_;

  temp_lib_ = nullptr;
  temp_name_ = "";
  temp_pvec_.clear();
}

void PluginLoader::AddLoad() {
  libraries_[temp_name_] = temp_lib_;

  std::vector<ICreator*> p(temp_pvec_);
  creators_[temp_name_] = p;
}

////////////////////////////////////////////////////////////
bool PluginLoader::Unload(const std::string& plugin_name) {
  std::string name = GetPluginName(plugin_name);
  LibMap::iterator it = libraries_.find(name);
  if (it != libraries_.end()) {
    delete it->second;
    libraries_.erase(it);
    return true;
  }
  return false;
}

////////////////////////////////////////////////////////////
void PluginLoader::UnloadAll() {
  LibMap::iterator it;
  for (it = libraries_.begin(); it != libraries_.end(); ++it) {
    delete it->second;
  }
  libraries_.clear();
}

////////////////////////////////////////////////////////////
std::string PluginLoader::GetPluginName(const std::string& path) {
  size_t last_dash = path.find_last_of("/\\");
  size_t last_dot = path.find_last_of('.');
  if (last_dash == std::string::npos) last_dash = 0;
  else ++last_dash;
  if (last_dot < last_dash || last_dot == std::string::npos) {
    // path without extension
    last_dot = path.length();
  }
  return path.substr(last_dash, last_dot - last_dash);
}

////////////////////////////////////////////////////////////
std::string PluginLoader::ResolvePathExtension(const std::string& path) {
  size_t last_dash = path.find_last_of("/\\");
  size_t last_dot = path.find_last_of('.');
  if (last_dash == std::string::npos) last_dash = 0;
  else ++last_dash;
  if (last_dot < last_dash || last_dot == std::string::npos) {
    // path without extension, add it
    return path + "." + PM_LIB_EXTENSION;
  }
  return path;
}

////////////////////////////////////////////////////////////
void PluginLoader::GetLoadedPlugins(std::vector<const std::string*>& plugin_names) const {
  plugin_names.reserve(plugin_names.size() + libraries_.size());
  LibMap::const_iterator it;
  for (it = libraries_.begin(); it != libraries_.end(); ++it) {
    plugin_names.push_back(&(it->first));
  }
}

////////////////////////////////////////////////////////////
const std::vector<ICreator*>* PluginLoader::GetRelatedProviders(const std::string& plugin_name) {
  std::string name = GetPluginName(plugin_name);
  CreatorMap::const_iterator it = creators_.find(name);
  if (it != creators_.end()) {
    return &it->second;
  }
  return nullptr;
}

////////////////////////////////////////////////////////////
bool PluginLoader::IsLoaded(const std::string& plugin_name) const {
  return libraries_.find(GetPluginName(plugin_name)) != libraries_.end();
}

}   // namespace pm