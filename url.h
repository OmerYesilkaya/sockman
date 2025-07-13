#ifndef URL_H
#define URL_H

struct UrlParts {
    char scheme[8];
    char host[256];
    char port[6];
    char path[1024];
};

int parse_url(const char *url, struct UrlParts *out);

#endif
