#include <stdio.h>
#include <stdlib.h>
#include "map.h"

#define MAP_W 20
#define MAP_H 20

int main()
{
  // Creation de la carte
  struct map* carte = newMap(MAP_W, MAP_H);

  // Initialisation de la map
  for(int i = 0; i < carte->height; ++i) {
    for(int j = 0; j < carte->width; ++j) {
      int tmp = i == 0 || j == 0 || i == carte->height-1 || j == carte->width-1;
      setCase(carte, i, j, tmp);
    }
  }

  // Affichage map
  printMap(carte);

  // On libère la map
  freeMap(carte);

  return EXIT_SUCCESS;
}
