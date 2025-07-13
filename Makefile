build:
	mkdir -p build
	clang main.c request.c request_utils.c -o build/httpc

run:
	build/httpc