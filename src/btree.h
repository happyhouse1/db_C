#ifndef BTREE_H
#define BTREE_H

#include <stdint.h> // pour int8_t
#include <stdio.h>  // lib pour file

// Structure classique du node, vu en cours
struct Node
{
    int8_t data;
    struct Node *left;
    struct Node *right;
};

// Prototypes des fonctions de btree.c
struct Node *createnode(int8_t data);
struct Node *insertnode(struct Node *root, int8_t data); // link dans btree.c
struct Node *deletenode(struct Node *root, int8_t key);  // link dans btree.c
void printtraversal(struct Node *node);                  // link dans btree.c
void printascii(struct Node *root, int space);           // link dans btree.c

void saveTreeToFile(struct Node *root, FILE *file); // retourne pas de valeur, parametre le neoud root + fichier link dans btree.c
struct Node *loadTreeFromFile(FILE *file);          // retourne struc paramètre fichier link dans btree.c

#endif
