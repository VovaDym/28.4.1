# CMakeList.txt : CMake project for 28.4.1new, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("28.4.1new")

# Add source to this project's executable.
add_executable (28.4.1new "main.cpp" "swimmer.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 28.4.1new PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
