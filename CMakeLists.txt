cmake_minimum_required(VERSION 4.1)
project(http_server C)

set(CMAKE_C_STANDARD 11)

add_executable(http_server main.c
        src/parse_request_line.c
        src/global_parser.c
        include/parse_headers.h
        src/parse_headers.c
        include/utils.h
        src/utils.c)
