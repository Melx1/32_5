cmake_minimum_required(VERSION 3.21)
project(32_5)

set(CMAKE_CXX_STANDARD 20)

set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(nlohmann_json)

add_executable(32_5 32.5.cpp)
target_link_libraries(32_5 PRIVATE nlohmann_json::nlohmann_json)
