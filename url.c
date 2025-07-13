#include "url.h"
#include <string.h>
#include <stdio.h>

int parse_url(const char *url, struct UrlParts *out) {
    if (strncmp(url, "http://", 7) != 0) {
        fprintf(stderr, "Only http:// URLs are supported.\n");
        return 1;
    }

    strcpy(out->scheme, "http");

    const char *p = url + 7; // skip "http://"
    const char *host_start = p;
    const char *port_start = NULL;
    const char *path_start = NULL;

    while (*p && *p != '/' && *p != ':') p++;

    size_t host_len = p - host_start;
    strncpy(out->host, host_start, host_len);
    out->host[host_len] = '\0';

    if (*p == ':') {
        p++; // skip ':'
        port_start = p;
        while (*p && *p != '/') p++;
        size_t port_len = p - port_start;
        strncpy(out->port, port_start, port_len);
        out->port[port_len] = '\0';
    } else {
        strcpy(out->port, "80");
    }

    if (*p == '/') {
        path_start = p;
        strncpy(out->path, path_start, sizeof(out->path) - 1);
    } else {
        strcpy(out->path, "/");
    }

    return 0;
}
