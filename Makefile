build:
	clang main.c request.c request_utils.c -o httpc

run:
	./httpc