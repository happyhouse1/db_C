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
    if (newnode == NULL) { // check si une addresse mémoire a été alloué avec notre fonction createnode, si pas d'allocation -> NULL
        printf("Erreur d'allocation mémoire\n"); //
        exit(1); // exit si ça fail, notes cours (code erreur)
    }
    newnode->data = data; // on donne la valeur qu'on vient d'entrée à notre newnode
    newnode->left = NULL; // on initialise une branche gauche 
    newnode->right = NULL; // on initialise une branche droite 
    return newnode;
}

// Fonction de suppression (deletenode)
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

int main() {
    struct Node* root = NULL; // initialisation du noeud root, arbre vide -> NULL
    char command[20]; // https://www.w3schools.com/c/c_user_input.php // nombre de char que le user va entrer (à tester)
    int value; // valeur random à entrer pour intérragir avec l'arbre

    printf("Bienvenue dans l'arbre binaire interactif !\n"); // printf arbre interractif 
    printf("Commandes disponibles : createnode <valeur>, deletenode <valeur>, printtree quit\n"); // printf arbre interractif

    while (1) { // while pour garder le cli ouvert, trop stylé
        printf("Entrez une commande : "); // printf arbre interractif
        fgets(command, sizeof(command), stdin); // user saisie la commande https://www.geeksforgeeks.org/fgets-gets-c-language/
        if (strncmp(command, "createnode", 10) == 0) { // compare si l'entrée "command" avec "createnode", il faut 0 diff
            sscanf(command + 11, "%d", &value); // je donne à l'addresse value la valeur entrée après le 11eme caractère (entier entré par le user)
            root = createnode(value);  // crée le noeud avec la valeur de value
            printf("Nœud %d inséré.\n", value); // prinf intéractif
        }
        else if (strncmp(command, "deletenode", 10) == 0) { // compare avec l'entrée user les 10 premier caractère, 0 diff
            sscanf(command + 11, "%d", &value); // attribue à l'addresse de value l'entrée de l'user après les 11 caractères (10 + espace)
            root = deletenode(root, value); // root noeud racine, value = entrée user, on delete
            printf("Nœud %d supprimé.\n", value); // print intéractif (%d entier)
        }
        else if (strncmp(command, "printtree", 9) == 0) { // compare avec l'entrée user les 9 premier caractère, 0 diff
            printf("Parcours de l'arbre en ordre croissant : "); // print intéractif 
            printtraversal(root); // appel la fonction printraversal avec la valeur de du noeud racine
            printf("\n"); // print intéractif 
        }
        else if (strncmp(command, "quit", 4) == 0) { // compare l'entrée command dois correspondre aux 4 premier caractère de quit
            printf("Fermeture du programme.\n"); // print intéractif
            break; // ferme la boucle while, qui le programme
        } 
        else {
            printf("Commande non reconnue. Veuillez réessayer.\n"); // Si saisie pas de commande répertoriée, resaisir
        }
    }

    return 0; // le fameux return 0
}


// TO DO :
// afficher l'arbre
// penser à faire une doc .. comment ?
// quand j'utilise print traversal ça print seulement la dernière valeur du createnode bug à corriger