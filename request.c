#include <stdio.h>
#include <string.h>
#include <unistd.h>         // close()
#include <netdb.h>          // getaddrinfo(), struct addrinfo
#include "request_utils.h"


int http_get(const char *host, const char *path) {
    struct addrinfo *hints, *res;
    int socketfd;
    
    int connerr = create_tcp_connection(host, &res, &socketfd);
    if(connerr != 0) {
        perror("socket");
        return 1;
    }
    
    char* template = http_get_request(path, host);
    send(socketfd, template, strlen(template), 0);


    char buffer[2048];
    ssize_t bytes_received;

    while ((bytes_received = recv(socketfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // null-terminate the string
        printf("%s", buffer);
    }

    close(socketfd);
    freeaddrinfo(res);

    return 0;
}

int http_post(const char *host, const char *path, const char *body) {
    struct addrinfo *hints, *res;
    int socketfd;
    
    int connerr = create_tcp_connection(host, &res, &socketfd);
    if(connerr != 0) {
        perror("socket");
        return 1;
    }

    char* template = http_post_request(path, host, body);
    send(socketfd, template, strlen(template), 0);

    char buffer[2048];
    ssize_t bytes_received;

    while ((bytes_received = recv(socketfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // null-terminate the string
        printf("%s", buffer);
    }

    close(socketfd);
    freeaddrinfo(res);

    return 0;
}