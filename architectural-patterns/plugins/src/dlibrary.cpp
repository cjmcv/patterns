#include <dlibrary.hpp>
#include <cstdio>
#include <string>

namespace pm{

DLibrary* DLibrary::Load(const std::string& path){
  if (path.empty()) {
    fprintf(stderr, "Failed to Load library: Empty path\n");
    return nullptr;
  }
  void* handle = nullptr;

  // Load library - OS dependent operation
#ifdef PM_SYS_WINDOWS
  handle = ::LoadLibraryA(path.c_str());
  if (!handle) {
    fprintf(stderr, "Failed to Load library \"%s\".\n", path.c_str());
    return nullptr;
  }
#else
  handle = ::dlopen(path.c_str(), RTLD_NOW);
  if (!handle) {
    const char* errorString = ::dlerror();
    fprintf(stderr, "Failed to Load library \"%s\".", path.c_str());
    if (errorString) fprintf(stderr, " OS returned error: \"%s\".", errorString);
    fprintf(stderr, "\n");
    return nullptr;
  }
#endif
  // return a DLibrary with the DLL handle
  return new DLibrary(handle);
}

DLibrary::~DLibrary() {
  if (handle_) {
#ifdef PM_SYS_WINDOWS
    ::FreeLibrary((HMODULE)handle_);
#else
    ::dlclose(handle_);
#endif
  }
}

void* DLibrary::GetSymbol(const std::string& symbol) {
  if (!handle_) {
    fprintf(stderr, "Cannot inspect library symbols, library isn't loaded.\n");
    return nullptr;
  }
  void* res;
#ifdef PM_SYS_WINDOWS
  res = (void*)(::GetProcAddress((HMODULE)handle_, symbol.c_str()));
#else
  res = (void*)(::dlsym(handle_, symbol.c_str()));
#endif
  if (!res) {
    fprintf(stderr, "Library symbol \"%s\" not found.\n", symbol.c_str());
    return nullptr;
  }
  return res;
}

DLibrary::DLibrary(void* handle) :
  handle_(handle)
{
  // Nothing to do
}

}   // namespace pm
