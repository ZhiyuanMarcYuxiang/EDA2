cmake_minimum_required(VERSION 3.24)
project(Xarxa_Social C)

set(CMAKE_C_STANDARD 11)

add_executable(Xarxa_Social Sources/0.main.c Sources/0.menu.c Headers/0.menu.h Sources/option_utils.c Headers/option_utils.h Sources/sort_utils.c Headers/sort_utils.h Sources/search_utils.c Headers/search_utils.h Sources/network_file_control.c Headers/network_file_control.h Sources/1.new_user.c Headers/1.new_user.h Sources/2.list_users.c Headers/2.list_users.h Sources/network_data_control.c Headers/network_data_control.h Sources/3.operate_user.c Headers/3.operate_user.h Headers/3.operate_user.h Sources/31.send_request.c Headers/31.send_request.h Sources/32.manage_requests.c Headers/32.manage_requests.h Sources/33.new_post.c Headers/33.new_post.h Headers/33.new_post.h Sources/34.list_posts.c Headers/34.list_posts.h Sources/decorations.c Headers/decorations.h Headers/decorations.h)
