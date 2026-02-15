//
// Created by dontknow on 2/14/26.
//

#include <stdio.h>

void split_line(char *current, char **next) {
    while (*current != '\r') {
        current = current + 1;
    }
    *current = '\0';
    *next = current+2;
}

void split_at_char(char *str, char c, char **second_part) {
    while (*str != '\0') {
        if (*str == c) {
            *str = '\0';
            *second_part = str + 1;
            return;
        }
        str++;
    }
    *second_part = NULL;
}
