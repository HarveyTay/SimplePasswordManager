cmake_minimum_required(VERSION 3.31)
project(SimplePasswordManager)

set(CMAKE_CXX_STANDARD 20)

add_executable(SimplePasswordManager main.cpp
        credential.h
        vault.h
        vault.cpp)
