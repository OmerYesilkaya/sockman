#include <stdio.h>
#include <string.h>
#include <unistd.h>         // close()
#include <netdb.h>          // getaddrinfo(), struct addrinfo
#include "request_utils.h"
#include "url.h"


int http_get(struct UrlParts url_parts) {
    struct addrinfo *hints, *res;
    int socketfd;
    
    int connerr = create_tcp_connection(url_parts, &res, &socketfd);
    if(connerr != 0) {
        perror("socket");
        return 1;
    }
    
    char* template = http_get_request(url_parts.path, url_parts.host);
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

int http_post(struct UrlParts url_parts, const char *body) {
    struct addrinfo *hints, *res;
    int socketfd;
    
    int conn_err = create_tcp_connection(url_parts, &res, &socketfd);
    if(conn_err != 0) {
        perror("socket");
        return 1;
    }

    char* template = http_post_request(url_parts.path, url_parts.host, body);
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

int http_put(struct UrlParts url_parts, const char *body) {
    struct addrinfo *hints, *res;
    int socketfd;
    
    int conn_err = create_tcp_connection(url_parts, &res, &socketfd);
    if(conn_err != 0) {
        perror("socket");
        return 1;
    }

    char* template = http_put_request(url_parts.path, url_parts.host, body);
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


int http_delete(struct UrlParts url_parts, const char *body) {
    struct addrinfo *hints, *res;
    int socketfd;
    
    int conn_err = create_tcp_connection(url_parts, &res, &socketfd);
    if(conn_err != 0) {
        perror("socket");
        return 1;
    }

    char* template = http_delete_request(url_parts.path, url_parts.host, body);
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
