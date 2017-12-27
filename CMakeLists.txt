cmake_minimum_required(VERSION 3.9)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

add_executable(push_swap main.c
                        checker.c
                        pushswap.c)
target_link_libraries(push_swap ${CMAKE_SOURCE_DIR}/libft/libft.a)