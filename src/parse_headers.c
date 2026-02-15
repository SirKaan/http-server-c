//
// Created by dontknow on 2/13/26.
//

#include "../include/utils.h"
#include "../include/parse_headers.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>


int parse_header(char *str, struct http_header *header) {
    if (strlen(str) > MAX_HEADER_LINE_LENGTH) {
        fprintf(stderr, "Header line to long");
        return ERR_MALFORMED_REQUEST;
    }

    char *current = str;
    const char allowed_in_name[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!#$%&'*+-.^_`|~";
    char *name;

    while (*current != '\0' && *current != ':') {
        if (strchr(allowed_in_name, *current) == NULL) {
            fprintf(stderr, "Header name contains 1 or more invalid characters\n");
            return ERR_MALFORMED_REQUEST;
        }

        current++;
    }

    if (*current == '\0' || current == str) {
        fprintf(stderr, "Invalid header syntax or empty name\n");
        return ERR_MALFORMED_REQUEST;
    }

    *current = '\0';
    name = str;
    current++;

    while (*current == ' ' || *current == '\t') {
        current++;
    }

    if (!strcasecmp(name, "Content-Length") || !strcasecmp(name, "Content-Type") || !strcasecmp(name, "Transfer-Encoding") || !strcasecmp(name, "Host")) {
        if (strlen(current) < 1) {
            fprintf(stderr, "Header %s requires value\n", name);
            return ERR_MALFORMED_REQUEST;
        }
    }

    header->name = name;
    header->value = current;

    return PARSE_SUCCESS;
}