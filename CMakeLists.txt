cmake_minimum_required(VERSION 3.24)
project(Xarxa_Social C)

set(CMAKE_C_STANDARD 11)

add_executable(Xarxa_Social Sources/0_main.c Sources/1_menu.c Headers/1_menu.h Sources/utils.c Headers/utils.h Sources/3_user.c Headers/3_user.h Sources/2_network.c Headers/2_network.h Headers/4_hobbies.h Sources/4_hobbies.c)
