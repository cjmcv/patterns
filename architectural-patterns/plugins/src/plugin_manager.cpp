#include <plugin_manager.hpp>
#include <loader.hpp>
#include <creator_selector.hpp>
#include <cstdio>

namespace pm{

PluginManager::PluginManager() {
  plugin_loader_ = new PluginLoader;
  creator_selector_ = new CreatorSelector;
}

PluginManager::~PluginManager() {
  delete plugin_loader_;
  delete creator_selector_;
}

bool PluginManager::Load(const std::string& path) {
  std::vector<pm::ICreator*> *pvec;
  if (!plugin_loader_->Load(path, &pvec)) {
    return false;
  }

  int num = 0;
  for (int i = 0; i < (*pvec).size(); i++) {
    if (creator_selector_->Add((*pvec)[i]))
      num++;
  }
  if (num == 0) {
    plugin_loader_->RestLoad();
    return false;
  }

  plugin_loader_->AddLoad();
  return true;
}

bool PluginManager::Unload(const std::string& plugin_name) {
  const std::vector<ICreator*>* iv = plugin_loader_->GetRelatedProviders(plugin_name);
  creator_selector_->Delete(iv);
  return plugin_loader_->Unload(plugin_name);
}

void PluginManager::UnloadAll() {
  creator_selector_->ClearAll();
  plugin_loader_->UnloadAll();
}

bool PluginManager::AddCreator(ICreator* provider) {
  return creator_selector_->Add(provider);
}

void PluginManager::GetLoadedPlugins(std::vector<const std::string*>& plugin_names) {
  plugin_loader_->GetLoadedPlugins(plugin_names);
}

bool PluginManager::IsLoaded(const std::string& plugin_name) {
  return plugin_loader_->IsLoaded(plugin_name);
}

void PluginManager::RegisterType(const int type_flag, int lowest_version, int highest_version) {
  creator_selector_->RegisterType(type_flag, lowest_version, highest_version);
}

const std::list<ICreator*>* PluginManager::GetCreator(const int type) {
  return creator_selector_->GetCreator(type);
}
}