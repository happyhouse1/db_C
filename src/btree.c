#include <stdio.h>

// Structure d'un nœud simple
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int main() {
    // Déclaration d'un seul nœud statique
    struct Node root;

    // Initialisation des valeurs
    root.data = 50;
    root.left = NULL;  // Pas de sous-arbre gauche
    root.right = NULL; // Pas de sous-arbre droit

    // Affichage des données
    printf("Donnée du nœud racine : %d\n", root.data);

    return 0;
}
