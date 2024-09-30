#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> // pour malloc

// Structure générale du Noeud
struct Node {
    int8_t data;    // utilisation de toutes petites valeurs
    struct Node* left;
    struct Node* right;
};

// Fonction pour créer un nouveau noeud
struct Node* createNode(int8_t data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(1); // Sortie si allocation échoue
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    // Test de la fonction createNode
    struct Node* testNode = createNode(10);  // Crée un nœud avec la valeur 10

    // Vérification
    if (testNode != NULL) {
        printf("Nœud créé avec succès : data = %d\n", testNode->data);
    } else {
        printf("Erreur lors de la création du nœud\n");
    }

    return 0;
}
