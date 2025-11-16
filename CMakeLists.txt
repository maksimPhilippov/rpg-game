cmake_minimum_required(VERSION 3.10)

# Project name and language
project(HelloWorld LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# To link SDL statically
# set(BUILD_SHARED_LIBS OFF)

# This assumes the SDL source is available in vendored/SDL
add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)

# Add the executable target
add_executable(hello)
target_sources(hello 
PRIVATE src/frontend/main.cxx)
target_link_libraries(hello PRIVATE SDL3::SDL3)
