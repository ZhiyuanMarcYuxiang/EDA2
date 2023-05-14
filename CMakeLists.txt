cmake_minimum_required(VERSION 3.24)
project(Xarxa_Social C)

set(CMAKE_C_STANDARD 11)

add_executable(Xarxa_Social Sources/0_main.c Sources/1_menu.c Headers/1_menu.h Sources/utils.c Headers/utils.h Sources/sort_utils.c Headers/sort_utils.h Sources/search_utils.c Headers/search_utils.h Sources/file_control.c Headers/file_control.h Sources/new_user.c Headers/new_user.h Sources/print_network.c Headers/print_network.h Sources/data_structures.c Headers/data_structures.h)
