#include <creator_selector.hpp>
#include <cstdio>

namespace pm{

CreatorSelector::CreatorSelector() {}

CreatorSelector::~CreatorSelector() {
  ClearAll();
  // map frees itself
}

bool CreatorSelector::Add(ICreator* provider) {
  if (provider == NULL) {
    fprintf(stderr, "Trying to add a null provider.\n");
    return false;
  }
  if (!Validate(provider)) {
    return false;
  }
  known_types_[provider->type()].push_back(provider);
  return true;
}

void CreatorSelector::Delete(const std::vector<ICreator*>* providers) {
  if (providers == nullptr) {
    fprintf(stderr, "Trying to delete a nullptr providers vector.\n");
    return;
  }

  // 遍历找到对应插件库锁提供的provider，将其一一删除。
  std::vector<ICreator*> wait_delete_providers;
  CreatorsMap::iterator it;
  for (it = known_types_.begin(); it != known_types_.end(); it++) {
    std::list<ICreator*> *know_providers = &it->second;
    std::list<ICreator*>::iterator it2;
    for (it2 = (*know_providers).begin(); it2 != (*know_providers).end(); it2++) {
      for (int i = 0; i < (*providers).size(); i++) {
        if ((*it2) == (*providers)[i]) {
          wait_delete_providers.push_back((*it2));
        }
      }
    }

    for (int i = 0; i < wait_delete_providers.size(); i++) {
      //printf("defore = %d.\n", (*know_providers).size());
      (*know_providers).remove(wait_delete_providers[i]);
      delete wait_delete_providers[i];
      //printf("after = %d.\n", (*know_providers).size());
    }
    wait_delete_providers.clear();
  }
}


void CreatorSelector::ClearAll() {
  CreatorsMap::iterator it;
  for (it = known_types_.begin(); it != known_types_.end(); ++it) {
    std::list<ICreator*>& providers = it->second;
    std::list<ICreator*>::iterator prov_it;
    for (prov_it = providers.begin(); prov_it != providers.end(); ++prov_it) {
      delete *prov_it;
    }
    std::list<ICreator*>().swap(providers);
  }
}

////////////////////////////////////////////////////////////
bool CreatorSelector::Knows(const int type_flag) const {
  return known_types_.find(type_flag) != known_types_.end();
}

/// 一个type会对应多个实际的provider，type本身对应的是包含虚函数的父类.
void CreatorSelector::RegisterType(const int type_flag, int lowest_version, int highest_version) {
  if (!Knows(type_flag)) {
    std::list<ICreator*> pi;
    known_types_[type_flag] = pi;

    std::tuple<int, int> v(lowest_version, highest_version);
    version_limit_[type_flag] = v;
  }
}

////////////////////////////////////////////////////////////
const std::list<ICreator*>* CreatorSelector::GetCreator(const int type) const {
  CreatorsMap::const_iterator it = known_types_.find(type);
  if (it != known_types_.end())
    return &it->second;
  return NULL;
}

const std::tuple<int, int>* CreatorSelector::GetVersion(const int type) const {
  TypeVersionLimit::const_iterator it = version_limit_.find(type);
  if (it != version_limit_.end())
    return &it->second;
  return NULL;
}

////////////////////////////////////////////////////////////
bool CreatorSelector::Validate(ICreator* provider) const {
  const int type = provider->type();
  if (!Knows(type)) {
    fprintf(stderr, "<%d> provider type isn't registered.\n", type);
    return false;
  }
  //printf("version: %d.\n", provider->version());

  const std::tuple<int, int> *versions = GetVersion(type);
  int lowest = std::get<0>(*versions);
  int highest = std::get<1>(*versions);
  int target = provider->version();

  if (target > highest || target < lowest) {
    fprintf(stderr, "Incompatible <%d> provider version: (%d) != (%d - %d)\n",
      type, target, lowest, highest);
    return false;
  }
  return true;
}

} //namespace pm