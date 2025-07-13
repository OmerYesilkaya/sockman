char* http_get_request(const char *path, const char *host);

char* http_post_request(const char *path, const char *host, const char *body);

char* http_put_request(const char *path, const char *host);

char* http_remove_request(const char *path, const char *host);

int create_tcp_connection(const char *host, struct addrinfo **res, int *socketfd);
