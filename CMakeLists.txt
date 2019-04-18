cmake_minimum_required(VERSION 3.12)
project(plazza)

add_compile_options(-Wall -Wextra)
set(CMAKE_CXX_STANDARD 20)

include_directories(. src)

file(GLOB_RECURSE sources src/*.cpp)
file(GLOB_RECURSE tests tests/src/*.cpp)
add_executable(${CMAKE_PROJECT_NAME} ${sources} ${tests})
target_link_libraries(${CMAKE_PROJECT_NAME} pthread)
