#ifndef REQUEST_H
#define REQUEST_H

#include "url.h"
#include <netdb.h>  // for struct addrinfo

char* http_get_request(const char *path, const char *host);

char* http_post_request(const char *path, const char *host, const char *body);

char* http_put_request(const char *path, const char *host, const char *body);

char* http_delete_request(const char *path, const char *host, const char *body);

int create_tcp_connection(struct UrlParts url_parts, struct addrinfo **res, int *socketfd);

#endif