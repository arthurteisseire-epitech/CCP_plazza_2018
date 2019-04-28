cmake_minimum_required(VERSION 3.12)
project(plazza)

add_compile_options(-Wall -Wextra)
set(CMAKE_CXX_STANDARD 14)

include_directories(src/pizza/pizzas src/kitchen src/pizza src/parse src .)

file(GLOB_RECURSE main main.cpp)
file(GLOB_RECURSE sources src/*.cpp src/*.hpp)
file(GLOB_RECURSE tests tests/*.cpp)
add_executable(${CMAKE_PROJECT_NAME} ${sources} ${main})
target_link_libraries(${CMAKE_PROJECT_NAME})

add_executable(tests ${sources} ${tests})
target_link_libraries(tests gtest gtest_main pthread)
