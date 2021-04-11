cmake_minimum_required(VERSION 2.8)

# Define project name
project(PluginManager)
set(PROJECT_NAME PluginManager)

if(WIN32)
  # MSVC  
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -DPM_EXPORTS") # -DPM_STATIC
else(WIN32)
  
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -DPM_EXPORTS") # -DPM_STATIC
endif(WIN32)

# Include
SET(INCLUDE_DIR
  ${MANAGER_INCLUDE_DIR}
  ${PROJECT_SOURCE_DIR}
)
message(STATUS "include: ${INCLUDE_DIR}")
include_directories(${INCLUDE_DIR})

# Source
file(GLOB_RECURSE SRC_LIST
  "${PROJECT_SOURCE_DIR}/*.cpp"
  # Include
  "${PROJECT_SOURCE_DIR}/*.hpp"
  "${MANAGER_INCLUDE_DIR}/*.hpp"
)
message(STATUS "src: ${SRC_LIST}")

add_library(${PROJECT_NAME} SHARED ${SRC_LIST})  #SHARED

#set_target_properties(${PROJECT_NAME} PROPERTIES output_name "utils")
#target_link_libraries(${PROJECT_NAME})

# Set output path
set(LIBRARY_OUTPUT_PATH ${OUTPUT_DIR})