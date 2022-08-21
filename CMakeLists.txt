cmake_minimum_required(VERSION 3.5)

project(canvas-downloader LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

link_libraries (-lfmt)
link_libraries (-lcpr)

 add_executable(canvas-downloader src/main.cpp src/File.cpp src/Folder.cpp
    src/Course.cpp src/Courses.cpp src/Web.cpp src/Config.cpp)

