//
// Created by dontknow on 2/9/26.
//

#ifndef HTTP_SERVER_HTTP_TYPES_H
#define HTTP_SERVER_HTTP_TYPES_H
#include <stddef.h>

#define PARSE_SUCCESS          1
#define ERR_MALFORMED_REQUEST (-1)
#define ERR_INVALID_METHOD    (-2)
#define ERR_INVALID_VERSION   (-3)
#define ERR_TOO_MANY_HEADERS  (-4)
#define ERR_MISSING_HOST      (-5)

struct http_header {
    char *name;
    char *value;
};

struct http_request {
    //Request line
    char *method;
    char *uri;
    char *version;

    //Headers
    struct http_header headers[50];

    //Body
    char *body;
    size_t body_length;
};

#endif //HTTP_SERVER_HTTP_TYPES_H