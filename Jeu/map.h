#ifndef HEAD_MAP_H
#define HEAD_MAP_H

struct map {
  int width;
  int height;
  int* cases;
};

// Renvoie un pointeur vers une map de taille w*h
struct map* newMap(int w, int h);

// Renvoie la case en position (j,i)
int getCase(struct map*, int i, int j);

// Change la case en position (j,i) par la valeur n
void setCase(struct map*, int i, int j, int n);

// Affiche la map
void printMap(struct map*);

// Libère la mémoire alloué pour une map
void freeMap(struct map*);

#endif
