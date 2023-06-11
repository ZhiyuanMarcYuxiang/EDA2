cmake_minimum_required(VERSION 3.24)
project(Xarxa_Social C)

set(CMAKE_C_STANDARD 11)

add_executable(Xarxa_Social Sources/0.main.c Sources/0.menu.c Headers/0.menu.h Sources/option_utils.c Headers/option_utils.h Sources/sort_utils.c Headers/sort_utils.h Sources/search_utils.c Headers/search_utils.h Sources/network_file_control.c Headers/network_file_control.h Sources/1.new_user.c Headers/1.new_user.h Sources/2.list_users.c Headers/2.list_users.h Sources/network_data_control.c Headers/network_data_control.h Sources/3.operate_user.c Headers/3.operate_user.h Headers/3.operate_user.h Sources/31.manage_requests.c Headers/31.manage_requests.h Sources/33.manage_posts.c Headers/33.manage_posts.h Headers/33.manage_posts.h Sources/32.manage_friends.c Headers/32.manage_friends.h Sources/dictionary_utils.c Sources/30.ceo_utils.c Sources/30.ceo_utils.c Sources/30.ceo_utils.c Sources/32.manage_friends.c Sources/32.manage_friends.c Sources/32.manage_friends.c Sources/33.manage_posts.c)
