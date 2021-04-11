#ifndef PM_DYNAMIC_LIBRARY_HPP
#define PM_DYNAMIC_LIBRARY_HPP

#include <config.hpp>
#include <string>

// include OS dependent support for DLL
#ifdef PM_SYS_WINDOWS
    #include <Windows.h>
#else
    #include <dlfcn.h>
#endif

namespace pm{

/// Manages a Dynamic Linking Library.
class DLibrary{

public:
  ////////////////////////////////////////////////////////////
  /// \brief Load a library.
  ///
  /// \param path Path to the library.
  /// \return Pointer to the loaded library, or NULL if failed.
  ///
  ////////////////////////////////////////////////////////////
  static DLibrary* Load(const std::string& path);

  /// Close and free the opened library (if any).
  ~DLibrary();

  ////////////////////////////////////////////////////////////
  /// \brief Get a symbol from the library.
  ///
  /// \return Pointer to what the symbol refers to, or NULL if
  /// the symbol is not found.
  ////////////////////////////////////////////////////////////
  void* GetSymbol(const std::string& symbol);

private:
  ////////////////////////////////////////////////////////////
  /// \brief Default constructor.
  /// Library instances cannot be created, use Load instead.
  ////////////////////////////////////////////////////////////
  DLibrary();

  ////////////////////////////////////////////////////////////
  /// \brief Constructor via library handle.
  /// Used on Load function.
  ////////////////////////////////////////////////////////////
  DLibrary(void* handle);

private:
  void* handle_; ///< Library handle.
};

}   // namespace pm


#endif // PM_DYNAMIC_LIBRARY_HPP