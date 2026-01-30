//
// Created by dontknow on 1/30/26.
//

#include "../include/request_line_parser.h"
#include <stdio.h>

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

int parse_request_line(char *str, struct http_request *req) {
    char *current = str;
    char *next = NULL;

    char *temp_method;
    char *temp_uri;

    //METHOD
    split_at_char(current, ' ', &next);
    if (next == NULL) {
        perror("Request line is missing elements or is corrupted");
        return -1;
    }
    if (!check_method(current)) {
        perror("Method is not valid");
        return -1;
    }
    temp_method = current;
    current = next;

    //URI
    split_at_char(current, ' ', &next);
    if (next == NULL) {
        perror("Request line is missing elements or is corrupted");
        return -1;
    }
    if (!check_uri(current)) {
        fprintf(stderr, "Url is not valid");
        return -1;
    }
    current = next;
    temp_uri = current;

    //VERSION
    split_at_char(current, ' ', &next);
    if (next != NULL) {
        fprintf(stderr, "Request line has more elements than expected");
        return -1;
    }
    if (!check_version(current)) {
        fprintf(stderr,"Version is not valid");
        return -1;
    }

    req->method = temp_method;
    req->uri = temp_uri;
    req->version = current;

    return 1;
}

bool check_method(char *str) {
    static const char methods[][30] = {"GET", "POST", "PATCH", "PUT", "DELETE"};

    for (size_t i = 0; i < sizeof(methods)/sizeof(methods[0]); i++) {
        if (strcmp(str, methods[i]) == 0) {
            return true;
        }
    }
    return false;
}

bool check_uri(char *str) {
    //URI ontbreekt -> NULL -> false
    if (str == NULL) return false;
    //URI begint niet met '/'
    if (*str != '/') return false;
    //hacker kan trachten de map uit te gaan en systeembestanden op te vragen bv. /../../etc/passwd -> checken op ".."
    if (strstr(str, "..") != NULL) return false;
    //uri mag geen spaties en onleesbara karakters bevatten en moet kleiner zijn dan 2048
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ' || (unsigned char)str[i] < 32) return false; //ascii < 32 -> onleesbare karakters
        i++;
        if (i > 2048) return false;
    }
    return true;
}

bool check_version(char *str) {
    if (str == NULL) {
        return false;
    }

    if (!strcmp(str, "HTTP/1.1") || !strcmp(str, "HTTP/1.0")) {
        return true;
    }
    return false;
}
