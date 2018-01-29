#include <emscripten.h>
#include <emscripten/html5.h>

EM_BOOL listener(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData) {
  int *n = (int*)userData;
  *n += 1;
  printf("press x: %ld, y: %ld (%d)\n", mouseEvent->clientX, mouseEvent->clientY, *n);
  return true;
}

int main() {
  int v = 1000;
  emscripten_set_click_callback("#canvas", (void*) &v, false, listener);
  emscripten_set_main_loop(emscripten_pause_main_loop, 1, 1);
  printf("Unreachable!\n");
}
