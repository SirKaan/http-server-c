//
// Created by dontknow on 1/30/26.
//

#ifndef HTTP_SERVER_REQUEST_LINE_PARSING_H
#define HTTP_SERVER_REQUEST_LINE_PARSING_H

#endif //HTTP_SERVER_REQUEST_LINE_PARSING_H

#include <string.h>
#include <stdbool.h>

struct http_request {
    char *method;
    char *uri;
    char *version;
};

void split_at_char(char *str, char c, char **second_part);

int parse_request_line(char *str, struct http_request *req);

bool check_method(char *str);

bool check_uri(char *str);

bool check_version(char *str);