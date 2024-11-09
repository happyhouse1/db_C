#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> // pour malloc (memory allocation)
#include <string.h> 
#include "btree.h"



// on veut créer un nouveau noeud
struct Node* createnode(int8_t data) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node)); // allocation dynamique d'une case mémoire dans le noeud car la valeur n'est pas encore défénie alors -> malloc
    if (newnode == NULL) { // check si une addresse mémoire a été alloué avec notre fonction createnode, si pas d'allocation -> NULL
        printf("Erreur d'allocation mémoire\n"); //
        exit(1); // exit si ça fail, notes cours (code erreur)
    }
    newnode->data = data; // on donne la valeur qu'on vient d'entrée à notre newnode
    newnode->left = NULL; // on initialise une branche gauche 
    newnode->right = NULL; // on initialise une branche droite 
    return newnode;
}

struct Node* insertnode(struct Node* root, int8_t data) { // insert node à appeler dans le main createnode
    if (root == NULL) { // si le noeud racine est vide
        return createnode(data); // on crée le noeud de manière classique avec createnode en associant data au nouveau noeud
    }

    if (data < root->data) { // si data est inférieur à la valeur du noeud racine on place la valeur à gauche (sous arbre gauche)
        root->left = insertnode(root->left, data);  // on insère la valeur de root à left si c'est plus petit
    } else {
        root->right = insertnode(root->right, data);  // on insère la valeur de root à right si c'est plus grand
    }

    return root;
}

// Supprimer noeud
struct Node* deletenode(struct Node* root, int8_t key) { // pointeur vers node, noeud root valeur à suppr
    if (root == NULL) return root; // si l'arbre est vide, peut rien faire
    if (key < root->data) { // si valeur entrée plus petite que root on attribu à data et on check
        root->left = deletenode(root->left, key); // valeur plus petite à gauche check
    } else if (key > root->data) { // si valeur entrée plus petite que root on attribu à data et on check
        root->right = deletenode(root->right, key); // check à droite
    } else {
        if (root->left == NULL) { // si le noeud n'a pas d'enfant a gauche
            struct Node* temp = root->right; // valeur sous arbre droit dans temp
            free(root); // libère la mémoire de root
            return temp; // return la valeur à droite stocké dans temp (temporaireement)
        } else if (root->right == NULL) { // on fait l'inverse pour la gauche
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // SI DEUX ENFANTS!!!
        struct Node* temp = root->right; // on veut check les noeuds à droite -> temp le noeud droits
        while (temp && temp->left != NULL) // tant que il y a un enfant à gauche, il y a une petite valeur
            temp = temp->left; //temp prend la valeur de l'enfant à gauche car plus petit et reboucle 
        root->data = temp->data; // le noeud root, principal, prend la valeur de son succéseur stocké dans temp à la même addresse
        root->right = deletenode(root->right, temp->data); // suppression noeud succésseur qui a la même valeur que le nouveau root 
    }
    return root; 
}
// https://www.geeksforgeeks.org/inorder-traversal-of-binary-tree/
void printtraversal(struct Node* node) { // pas de retour, paramètre pointeur vers le noeud 
    if (node == NULL) return; // si le noeud est NULL, pas de printtraversal fin de la branche de l'arbre
    printtraversal(node->left); // traversal à gauche jusqu'à ce qu'il y ai plus de data
    printf("%d ", node->data); // affiche la valeur du noeud à la fin du parcours (traversal)
    printtraversal(node->right); // traversal à droite, plus grande valeur que la racine donc rien au dessus
}
// test du afficher en ascii l'arbre
void printascii(struct Node* root, int space) { // ne renvoie pas de valeur, pointeur comme d'hab vers le noeud root, int nombre d'espace pour créer l'arbre, on va voir ce que ça donne
    int count = 10;  // indente de 10 espace à chaque fois
    if (root == NULL) { // si le noeud et vide, return, cut.
             return;}
    space += count; // augemente la valeur de espace à chaque fois que l'on est à gauche dans l'arbre
    printascii(root->right, space); // sous arbre droit + espace
    printf("\n"); // insère une nouvelle ligne pour chaque noeud pour séparer
    for (int i = count; i < space; i++) { // Plus on est loin dans le noeud plus y'aura d'espece 
        printf(" "); // print l'espace
    }
    printf("%d\n", root->data); // affiche la valeure du noeud + print valeur du noeud
    printascii(root->left, space); // sous arbre gauche + espace
}


// TO DO :
// afficher l'arbre
// penser à faire une doc .. comment ?
// quand j'utilise print traversal ça print seulement la dernière valeur du createnode bug à corriger