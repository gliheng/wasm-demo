OUTPUT=.

all:
	wat2wasm math.wat -o target/math.wasm
	wat2wasm ffi.wat -o target/ffi.wasm
	wat2wasm memory.wat -o target/memory.wasm
	wat2wasm table.wat -o target/table.wasm

server:
	cd $(OUTPUT) && python3 -m http.server

