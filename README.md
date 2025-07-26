# Sockman

Like Postman but in C w/ sockets

## Building

The project includes a minimal raylib distribution (headers + static library). To build:

```bash
make build
```

## Dependencies

-   raylib (included in `lib/raylib/`)
-   macOS frameworks: OpenGL, Cocoa, IOKit, CoreVideo

## Usage

```bash
./httpc <method> <url>
```

Example:

```bash
./httpc POST http://localhost:8080/auth/signup
```
