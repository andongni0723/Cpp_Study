cmake_minimum_required(VERSION 3.25)
project(Cpp_Study)

set(CMAKE_CXX_STANDARD 14)

add_executable(Cpp_Study
        Base/base.cpp "APCS Teach/lcs.cpp")


add_executable(p72 CLHS_OJ/P72_Exam/p72.cpp)
add_executable(p73 CLHS_OJ/P73_Draw/p73.cpp)
add_executable(scratch "/Users/andongni/Library/Application Support/JetBrains/CLion2023.1/scratches/scratch.cpp")