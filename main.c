#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "include/global_parser.h"


int main(void) {
    char buffer[300] = "POST /submit-form HTTP/1.1\r\nHost: localhost:4331\r\nUser-Agent: Mozilla/5.0\r\nContent-Length: 25\r\n\r\nnaam=Jan+Smit&leeftijd=30";
    struct http_request request;
    parse_full_request(buffer, &request);
    return 0;
}
