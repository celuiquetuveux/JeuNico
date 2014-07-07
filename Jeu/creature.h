#ifndef CREATURE_H
#define CREATURE_H

#include "map.h"

enum creatureType {JOUEUR, MONSTRE};
enum direction {NORD, SUD, EST, OUEST};

struct caracteristiques {
  int vie;
  int force;
  int intelligence;
  int constitution;
  int dexterite;
};

struct creature {
  enum creatureType type;
  struct caracteristiques stats;
  int x,y;
  enum direction vue;
};

// Renvoie une nouvelle créature
struct creature* newCreature(enum creatureType);

// Déplace une créature dans la direction demandé
void moveCreature(struct creature*, enum direction, struct map*);

// Affiche la créature
void printCreature(struct creature*, struct map*);

// Libère la mémoire alloué par une créature
void freeCreature(struct creature*);

#endif
