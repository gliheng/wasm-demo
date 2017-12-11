OUTPUT=.

all:
	wat2wasm math.wat -o target/math.wasm
	wat2wasm ffi.wat -o target/ffi.wasm

server:
	cd $(OUTPUT) && python3 -m http.server

