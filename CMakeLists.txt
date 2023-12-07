cmake_minimum_required(VERSION 3.25)
project(Cpp_Study)

set(CMAKE_CXX_STANDARD 14)

add_executable(Cpp_Study
        Base/base.cpp)

add_executable(LineLen "APCS Teach/LineLen.cpp")
add_executable(Test AtCoder/Test.cpp)
add_executable(NestedRangesCheck "APCS Teach/NestedRangesCheck.cpp")
add_executable(TasksAndDeadlines "APCS Teach/TasksAndDeadlines.cpp")
add_executable(2023-10_Q1 APCS/2023-10_Q1.cpp)
add_executable(2023-10_Q3 APCS/2023-10_Q3.cpp)