#ifndef REQUEST_H
#define REQUEST_H

#include "url.h"

int http_get(struct UrlParts);

int http_post(struct UrlParts, const char *body);

int http_put(struct UrlParts, const char *body);

int http_delete(struct UrlParts, const char *body);

#endif