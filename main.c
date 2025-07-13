#include <stdio.h>
#include "request.h"

int main(){
    const char *host = "localhost";
    const char *path = "/auth/signup";
    const char  *body = "{\"name\": \"Sockman\",\"email\": \"sockman@gmail.com\",\"password\": \"123123\"}";
    
    return http_post(host, path, body);
}