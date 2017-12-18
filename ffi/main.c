#include <emscripten.h>

int main() {
  emscripten_run_script("alert('hello world!')");

  EM_ASM(
    alert('hello world!');
    throw 'all done';
  );

  EM_ASM_({
      let s = Module.getValue($7, 'i8*');
      Module.print('I received: ', $0, $1, $2, $3, $4, $5, $6, s);
  }, 1, 2, 3, 4, 5, 6, 7, "a");

  int x = EM_ASM_INT({
      Module.print('I received: ' + $0);
      return $0 + 1;
  }, 100);

  printf("%d\n", x);

  return 0;
}
