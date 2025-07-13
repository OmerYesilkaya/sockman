build:
	clang main.c request.c request_utils.c url.c -o ./httpc

run:
	./httpc POST http://localhost:8080/auth/signup