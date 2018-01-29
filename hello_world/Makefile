CC = emcc
all: hello_world.c
	$(CC) hello_world.c -o hello_world.html -s WASM=1 -s NO_EXIT_RUNTIME=0

server:
	python3 -m http.server
