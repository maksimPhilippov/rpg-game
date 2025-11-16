cmake_minimum_required(VERSION 3.10)

# Project name and language
project(HelloWorld LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable target
add_executable(hello)
target_sources(hello 
PRIVATE main.cxx)
