CC = em++
all: main.cpp
	$(CC) main.cpp -s WASM=1 --use-preload-plugins --preload-file icon.png -s USE_SDL=1 -s USE_SDL_IMAGE=1 -o index.html

server:
	python3 -m http.server
