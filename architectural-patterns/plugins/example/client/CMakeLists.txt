cmake_minimum_required(VERSION 2.8)

# Define project name
project(Client)
set(PROJECT_NAME Client)

if(WIN32)
  # MSVC  
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2") # -DPM_STATIC
else(WIN32)
  
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3") # -DPM_STATIC
endif(WIN32)

# Include
SET(INCLUDE_DIR
  ${MANAGER_INCLUDE_DIR}
  "${PROJECT_SOURCE_DIR}"
  "${PROJECT_SOURCE_DIR}/.."
)
message(STATUS "include: ${INCLUDE_DIR}")
include_directories(${INCLUDE_DIR})

# Source
file(GLOB_RECURSE SRC_LIST
  "${PROJECT_SOURCE_DIR}/*.cpp"
  # Include
  "${PROJECT_SOURCE_DIR}/*.hpp"
  "${PROJECT_SOURCE_DIR}/../interface.hpp"
  "${MANAGER_INCLUDE_DIR}/config.hpp"
  "${MANAGER_INCLUDE_DIR}/icreator.hpp"
  "${MANAGER_INCLUDE_DIR}/plugin_manager.hpp"
)
message(STATUS "src: ${SRC_LIST}")

add_executable(${PROJECT_NAME} ${SRC_LIST})

target_link_libraries(${PROJECT_NAME} PluginManager)

# Set output path
set(EXECUTABLE_OUTPUT_PATH ${OUTPUT_DIR})