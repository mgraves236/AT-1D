cmake_minimum_required(VERSION 3.17)
project(model_private_public_all_C__11)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11 -O3")
set(CMAKE_EXE_LINKER_FLAGS "-static")


add_executable(model_private_public_all_C__11-1 main.cpp functions.cpp functions.h lib.h statFunctions.cpp statFunctions.h energy.cpp energy.h)