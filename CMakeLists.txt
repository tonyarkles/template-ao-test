cmake_minimum_required(VERSION 3.5)

project(ao-prototype LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ao-test
  main.cpp activeobject.cpp)
