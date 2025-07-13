#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>         // close()
#include <sys/socket.h>     // socket(), connect(), send(), recv()
#include <netdb.h>          // getaddrinfo(), struct addrinfo
#include "request_utils.h"

char* http_get_request(const char *path, const char *host){
    char* request = malloc(1024);
    snprintf(
        request,
        1024,
        "GET %s HTTP/1.1\r\n"
        "Host: %s\r\n"
        "Connection: close\r\n"
        "\r\n",
        path,
        host
    );
    return request;
}

char* http_post_request(const char *path, const char *host, const char *body) {
    const char *content_type = "application/json";
    int body_len = strlen(body);
    
    char *request = malloc(2048); // Adjust size as needed
    if (!request) return NULL;

    snprintf(
        request,
        2048,
        "POST %s HTTP/1.1\r\n"
        "Host: %s\r\n"
        "Content-Type: %s\r\n"
        "Content-Length: %d\r\n"
        "Connection: close\r\n"
        "\r\n"
        "%s",
        path,
        host,
        content_type,
        body_len,
        body
    );

    return request;
}

char* http_put_request(const char *path, const char *host);

char* http_delete_request(const char *path, const char *host);

int create_tcp_connection(const char *host, struct addrinfo **res, int *socketfd){
    struct addrinfo hints;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;      // AF_INET or AF_INET6
    hints.ai_socktype = SOCK_STREAM;  // TCP

    int addrinfoerr = getaddrinfo(host, "8080", &hints, res);
    if (addrinfoerr != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(addrinfoerr));
        return 1;
    }

    *socketfd = socket((*res)->ai_family, (*res)->ai_socktype, (*res)->ai_protocol);
    if (*socketfd == -1) { // File descriptor not found
        perror("socket");
        freeaddrinfo(*res);
        return 1;
    }

    int connecterr = connect(*socketfd, (*res)->ai_addr, (*res)->ai_addrlen);
    if (connecterr != 0) {
        perror("connect");
        close(*socketfd);
        freeaddrinfo(*res);
        return 1;
    }
    return 0;
}