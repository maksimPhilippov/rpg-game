cmake_minimum_required(VERSION 3.10)

# Project name and language
project(RpgGame LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#### SDL includsion
# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# To link SDL statically
# set(BUILD_SHARED_LIBS OFF)

# This assumes the SDL source is available in vendored/SDL
add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)
####

#### vk bootstrap inclusion
add_subdirectory(vendored/vk-bootstrap EXCLUDE_FROM_ALL)
####

# Add the executable target
add_executable(frontend)
target_sources(frontend 
PRIVATE 
    src/frontend/main.cxx
    src/frontend/vulkanEngine.cxx
)
target_include_directories(frontend
PRIVATE
    include/frontend
)
target_link_libraries(frontend PRIVATE SDL3::SDL3 vk-bootstrap::vk-bootstrap)
