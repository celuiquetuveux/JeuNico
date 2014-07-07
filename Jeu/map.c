#include <stdlib.h>
#include <stdio.h>
#include "map.h"

struct map* newMap(int w, int h) {
  struct map* tmp = malloc(sizeof(struct map));

  tmp->width  = w;
  tmp->height = h;
  tmp->cases = calloc(w*h, sizeof(int));

  return tmp;
}

int getCase(struct map* carte, int i, int j) {
  return carte->cases[i*carte->width + j];
}

void setCase(struct map* carte, int i, int j, int n) {
  carte->cases[i*carte->width + j] = n;
}

void printMap(struct map* carte) {
  for(int i = 0; i < carte->height; ++i) {
    for(int j = 0; j < carte->width; ++j) {
      printf("%c", getCase(carte, i, j) == 0 ? ' ' : '#');
    }
    printf("\n");
  }
}

void freeMap(struct map* carte) {
  free(carte->cases);
  free(carte);
}
