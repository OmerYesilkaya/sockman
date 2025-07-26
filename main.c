#include "request.h"
#include "request_utils.h"
#include "url.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: %s <method> <path>\n", argv[0]);
    return 1;
  }

  const char *method = argv[1];
  const char *url = argv[2];
  struct UrlParts parsed;
  int parse_err = parse_url(url, &parsed);
  if (parse_err != 0) {
    perror("parse error");
  }

  const char *body = "{\"name\": \"Sockman\",\"email\": "
                     "\"sockman@gmail.com\",\"password\": \"123123\"}";

  if (strcmp(method, "GET") == 0) {
    return http_get(parsed);
  } else if (strcmp(method, "POST") == 0) {
    return http_post(parsed, body);
  } else if (strcmp(method, "PUT") == 0) {
    return http_put(parsed, body);
  } else if (strcmp(method, "DELETE") == 0) {
    return http_delete(parsed, body);
  } else {
    printf("Unsupported method: %s\n", method);
    return 1;
  }
}