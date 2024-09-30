#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> // pour malloc (memory allocation)
#include <string.h>

// Structure classique du node, vu en cours + 
struct Node {
    int8_t data;    // utilisation de toutes petites valeurs
    struct Node* left; 
    struct Node* right;
};

// on veut créer un nouveau noeud
struct Node* createnode(int8_t data) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node)); // allocation dynamique d'une case mémoire dans le noeud car la valeur n'est pas encore défénie alors -> malloc
    if (newNode == NULL) { // check si une addresse mémoire a été alloué avec notre fonction createnode, si pas d'allocation -> NULL
        printf("Erreur d'allocation mémoire\n"); //
        exit(1); // exit si ça fail, notes cours (code erreur)
    }
    newnode->data = data; // on donne la valeur qu'on vient d'entrée à notre newNode
    newnode->left = NULL; // on initialise une branche gauche 
    newnode->right = NULL; // on initialise une branche droite 
    return newnode;
}

int main() {
    struct Node* root = NULL; // initialisation du noeud root, arbre vide -> NULL
    char command[20]; // https://www.w3schools.com/c/c_user_input.php
    int value;

    printf("Bienvenue dans l'arbre binaire interactif !\n");
    printf("Commandes disponibles : createnode <valeur>, quit\n");

    while (1) {
        printf("Entrez une commande : ");
        fgets(command, sizeof(command), stdin);

        // Commande "createnode"
        if (strncmp(command, "createnode", 10) == 0) {
            sscanf(command + 11, "%d", &value);
            root = createnode(value);  // Crée un nœud avec la valeur spécifiée
            printf("Nœud %d inséré.\n", value);
        } 
        // Commande "quit"
        else if (strncmp(command, "quit", 4) == 0) {
            printf("Fermeture du programme.\n");
            break;
        } 
        else {
            printf("Commande non reconnue. Veuillez réessayer.\n");
        }
    }

    return 0;
}

// test demain si ça marche, flemme là