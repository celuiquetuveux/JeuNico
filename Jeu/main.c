#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include "map.h"
#include "creature.h"

int main()
{
  // Initialisation de l'écran
  WINDOW *wnd =  initscr();

  cbreak(); // pas besoin de "enter" pour valider caractère
  noecho(); // n'affiche pas les caractères tapés

  clear(); // efface l'écran
  refresh();

  keypad(stdscr, 1); // permet de récupérer touches spéciales

  int nrows, ncols;
  // on récupère la taille de la console
  //getmaxyx(wnd, nrows, ncols);
  nrows = ncols = 20;

  // Creation de la carte
  struct map* carte = newMap(ncols, nrows);

  // Creation du joueur
  struct creature* player = newCreature(JOUEUR);
  player->x = ncols/2;
  player->y = nrows/2;
  player->vue = NORD;

  // Initialisation de la map
  for(int i = 0; i < carte->height; ++i) {
    for(int j = 0; j < carte->width; ++j) {
      int tmp = i == 0 || j == 0 || i == carte->height-1 || j == carte->width-1;
      setCase(carte, i, j, tmp);
    }
  }

  // Affichage map
  printMap(carte);
  
  // Affiche le joueur
  printCreature(player, carte);

  // Boucle principal pour se déplacer
  int touche = 0;
  while(touche != 27) {
    touche = getch();
    switch(touche) {
    case KEY_UP:    moveCreature(player, NORD,  carte); break;
    case KEY_DOWN:  moveCreature(player, SUD,   carte); break;
    case KEY_LEFT:  moveCreature(player, OUEST, carte); break;
    case KEY_RIGHT: moveCreature(player, EST,   carte); break;
    }
  }

  // On libère la mémoire
  freeMap(carte);
  freeCreature(player);

  endwin();

  return EXIT_SUCCESS;
}
