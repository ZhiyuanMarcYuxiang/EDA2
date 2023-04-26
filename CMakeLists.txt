cmake_minimum_required(VERSION 3.24)
project(Xarxa_Social C)

set(CMAKE_C_STANDARD 11)

add_executable(Xarxa_Social Sources/main.c Sources/menu.c Headers/menu.h Sources/utils.c Headers/utils.h Sources/user.c Headers/user.h)
