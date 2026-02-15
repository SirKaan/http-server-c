//
// Created by dontknow on 2/9/26.
//

#include <stdio.h>

#include "../include/global_parser.h"
#include "../include/parse_headers.h"
#include "../include/parse_request_line.h"
#include "../include/utils.h"

int parse_full_request(char *buffer, struct http_request *req) {
    char *currentLine = buffer;
    char *next = NULL;
    split_line(currentLine, &next);

    //Request Line
    int req_line = parse_request_line(currentLine, req);
    if (req_line < 0) {
        fprintf(stderr, "Parsing request line failed.");
        return -1;
    }

    //Headers

    return 1;
}