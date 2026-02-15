//
// Created by dontknow on 2/13/26.
//

#ifndef HTTP_SERVER_PARSE_HEADERS_H
#define HTTP_SERVER_PARSE_HEADERS_H

#include <stdbool.h>
#include "http_types.h"

#define MAX_HEADER_LINE_LENGTH 8192

//neemt een pointer naar de eerste header, verwerkt alle headers in de http_request struct en geeft een pointer terug naar de volgende regel


int parse_header(char *str, struct http_header *header);

#endif //HTTP_SERVER_PARSE_HEADERS_H