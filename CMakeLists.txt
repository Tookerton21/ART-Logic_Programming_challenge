cmake_minimum_required(VERSION 3.13)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp Encode.cpp Encode.h decode.cpp decode.h Code.cpp Code.h)