#include <stdlib.h>
#include <curses.h>
#include "creature.h"
#include "map.h"

struct creature* newCreature(enum creatureType type) {
  struct creature* tmp = malloc(sizeof(struct creature));
  tmp->type = type;
  return tmp;
}

void moveCreature(struct creature* perso, enum direction way, struct map* carte) {
  // On change la direction du regard du perso
  perso->vue = way;  

  // On calcul la nouvelle position
  int new_x = perso->x, new_y = perso->y;
  switch(way) {
    case NORD:  new_y = perso->y-1; break;
    case SUD:   new_y = perso->y+1; break;
    case OUEST: new_x = perso->x-1; break;
    case EST:   new_x = perso->x+1; break;
  }
  
  // On vérifie que cette nouvelle case est accessible
  if(isIn(carte, new_y, new_x) && getCase(carte, new_y, new_x) == 0) {
    // On enlève le caractère de l'ancienne position du perso
    delch();
    insch(getCase(carte, perso->y, perso->x) == 0 ? ' ' : '#');

    // On déplace et affiche le perso à la nouvelle position
    perso->x = new_x;
    perso->y = new_y;
    printCreature(perso, carte);
  }
}

void printCreature(struct creature* perso, struct map* carte) {
  move(perso->y, perso->x);
  delch();
  switch(perso->vue) {
    case NORD:  insch('H'); break;
    case SUD:   insch('B'); break;
    case OUEST: insch('G'); break;
    case EST:   insch('D'); break;
  }
}

void freeCreature(struct creature* perso) {
  free(perso);
}
