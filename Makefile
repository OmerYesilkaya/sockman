build:
	clang main.c request.c request_utils.c url.c -o ./httpc -I./lib/raylib/include -L./lib/raylib/lib -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

run:
	./httpc POST http://localhost:8080/auth/signup

clean:
	rm -f httpc

.PHONY: build run clean