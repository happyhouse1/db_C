#include <stdio.h>

// https://www.geeksforgeeks.org/binary-tree-in-c/
// Structure générale du Noeud
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

// schéma de l'arbre binaire 
//      0
//     / \
//    1   3
//   /     \
//  2       4
    
// là faut que j'organise mes noeuds (&nX pour pointer l'addresse mémoire)
// branche gauche de l'arbre
    n0.left = &n1;
    n1.left = &n2;
    n1.right = NULL;
    n2.left = NULL;
    n2.right = NULL;
// branche droite de l'arbre
    n0.right = &n3;
    n3.right = &n4;
    n3.left = NULL;
    n4.right = NULL;
    n4.left = NULL;

// Affichage des data pour voir si l'arbre est bien formé
// à utiliser pour debug pour le moment
//Affichage Racine
    printf("la racine est %d\n", n0.data);
// Affichage branche gauche    
    printf("branche gauche :\n");
    printf("à gauche de %d il y a %d\n", n0.data, n1.data);
    printf("à gauche de %d il y a %d\n", n1.data, n2.data);
// Affichage branche droite
        printf("branche droite :\n");
    printf("à gauche de %d il y a %d\n", n0.data, n3.data);
    printf("à gauche de %d il y a %d\n", n3.data, n4.data);

    return 0;
}
