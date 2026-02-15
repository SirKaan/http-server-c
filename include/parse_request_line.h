//
// Created by dontknow on 1/30/26.
//

#ifndef HTTP_SERVER_PARSE_REQUEST_LINE_H
#define HTTP_SERVER_PARSE_REQUEST_LINE_H



#include <stdbool.h>
#include "http_types.h"


int parse_request_line(char *str, struct http_request *req);

bool check_method(char *str);

bool check_uri(char *str);

bool check_version(char *str);

#endif //HTTP_SERVER_PARSE_REQUEST_LINE_H