cmake_minimum_required(VERSION 4.3)
project(play-with-opencv CXX)

find_package(OpenCV REQUIRED)
if(NOT DEFINED env{OpenCV_DIR})
    message("OpenCV_DIR is not set, searching in default location(s)")
endif()

find_package(OpenCV REQUIRED)

add_subdirectory(01-hello-world)
add_subdirectory(02-videoio)
