#include <stdio.h>

// https://www.geeksforgeeks.org/binary-tree-in-c/
// Structure du Noeud
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int main() {
   
    // Je déclare mon nombre de noeuds
    struct Node n0, n1, n2, n3, n4;

    // Je donne la valeurs random aux data de mes nodes
    n0.data = 0; // c'est le noeud racine
    n1.data = 1;
    n2.data = 2;
    n3.data = 3;
    n4.data = 4;

    // là faut que j'organise mes noeuds


    // On verra pour l'affichage plus tard, doit être modifié 

    return 0;
}
