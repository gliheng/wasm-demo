CC = emcc
all:
	$(CC) main.cc -std=c++11 --bind -o index.html -s WASM=1 --post-js post.js

server:
	python3 -m http.server
