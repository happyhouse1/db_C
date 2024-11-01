#ifndef BTREE_H
#define BTREE_H

#include <stdint.h>  // pour int8_t

// Structure classique du node, vu en cours
struct Node {
    int8_t data;
    struct Node* left;
    struct Node* right;
};

// Prototypes des fonctions de btree.c
struct Node* createnode(int8_t data);
struct Node* insertnode(struct Node* root, int8_t data);
struct Node* deletenode(struct Node* root, int8_t key);
void printtraversal(struct Node* node);
void printascii(struct Node* root, int space);

#endif
