cmake_minimum_required(VERSION 4.1)
project(http_server C)

set(CMAKE_C_STANDARD 11)

add_executable(http_server main.c
        include/request_line_parser.h
        src/request_line_parser.c)
