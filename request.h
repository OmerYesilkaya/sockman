#ifndef REQUEST_H
#define REQUEST_H

int http_get(const char *host, const char *path);

int http_post(const char *host, const char *path, const char *body);

#endif