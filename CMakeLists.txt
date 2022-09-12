cmake_minimum_required(VERSION 3.15)

project(canvas-downloader
    LANGUAGES CXX
    VERSION 1.0
    )

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} src/main.cpp src/File.cpp src/Folder.cpp
    src/Course.cpp src/Courses.cpp src/Web.cpp src/Config.cpp)


include(FetchContent)

FetchContent_Declare(cpr
    GIT_REPOSITORY https://github.com/libcpr/cpr.git
    GIT_TAG 871ed52d350214a034f6ef8a3b8f51c5ce1bd400
    )

FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG c4ee726532178e556d923372f29163bd206d7732 # release-9.0.0
    )


FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_PROGRESS TRUE
    GIT_SHALLOW TRUE
    GIT_TAG bc889afb4c5bf1c0d8ee29ef35eaaf4c8bef8a5d # release-3.11.2
    )

FetchContent_MakeAvailable(cpr fmt json)

target_link_libraries(${PROJECT_NAME}
    PUBLIC cpr::cpr
    PUBLIC fmt
    PUBLIC nlohmann_json::nlohmann_json
    )


