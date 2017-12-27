#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <assert.h>
#include <emscripten.h>
#include <unistd.h>
#include <stdlib.h>
#include <string>

SDL_Surface* screen;

void ready(void *arg, const char *fileName) {
  printf("ready! %s (%d)\n", fileName, (int)arg);

  SDL_Surface *image = IMG_Load(fileName);

  SDL_BlitSurface (image, NULL, screen, NULL);
  SDL_FreeSurface (image);

  SDL_Flip(screen);

  printf("you should see an image.\n");

  SDL_Quit();
}

int main() {
  // printf("init result: %d %d\n", IMG_INIT_PNG, IMG_INIT_JPG);
  // int initted = IMG_Init(IMG_INIT_PNG|IMG_INIT_JPG);
  // printf("init result: %d\n", initted);
  SDL_Init(SDL_INIT_VIDEO);
  screen = SDL_SetVideoMode(600, 450, 32, SDL_SWSURFACE);

#define SIZE 203164
  FILE *f = fopen("icon.png", "rb");
  char *buffer = (char *) malloc(SIZE);
  fread(buffer, SIZE, 1, f);
  fclose(f);

  emscripten_run_preload_plugins_data(buffer, SIZE, "png", (void*)25, ready, NULL);
  return 0;
}

