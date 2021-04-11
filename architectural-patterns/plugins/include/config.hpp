#ifndef PM_CONFIG_HPP
#define PM_CONFIG_HPP

#ifdef __cplusplus
  #define EXTERN_C extern "C"
#else
  #define EXTERN_C
#endif

#ifdef PM_EXPORTS
  // From DLL side, we must export
  #define DECLSPEC_DLL __declspec(dllexport)
#else
  // From client application side, we must import
  #define DECLSPEC_DLL __declspec(dllimport)
#endif

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
  // Windows
  #define PM_SYS_WINDOWS
  #define PM_LIB_EXTENSION "dll"

  #define PM_API DECLSPEC_DLL
  #define PM_CONNECTOR EXTERN_C DECLSPEC_DLL

#elif defined(linux) || defined(__linux)
  // Linux
  #define PM_SYS_LINUX
  #define PM_LIB_EXTENSION "so"

  // Needn't to define anything for API.
  #define PM_API
  #define PM_CONNECTOR EXTERN_C

#else
    // Unsupported system
  #error This operating system is not supported by this library

#endif

#endif // PM_CONFIG_HPP