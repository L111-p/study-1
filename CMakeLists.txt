cmake_minimum_required(VERSION 3.10)
project(study)

set(CMAKE_CXX_STANDARD 17)

add_executable(study main.cpp)
add_executable(s_step1 src/step1_basic.cpp)
add_executable(s_step2 src/step2_static.cpp)
add_executable(s_step3 src/step3_vector.cpp)
add_executable(s_step4 src/step4_class.cpp)

