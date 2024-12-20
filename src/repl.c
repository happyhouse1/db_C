#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "btree.h"
#include "repl.h"

// Fonction principale du REPL pour interpréter les commandes utilisateur
void run_repl()
{
    struct Node *root = NULL; // initialisation du noeud root, arbre vide -> NULL
    char command[20];         // nombre de char que le user va entrer (à tester)
    int value;                // valeur random à entrer pour intérragir avec l'arbre

    printf("Bienvenue dans l'arbre binaire interactif !\n");                                                               // printf arbre interractif
    printf("Commandes disponibles : createnode <valeur>, deletenode <valeur>, printtree, printascii, save, load, quit\n"); // printf arbre interractif

    while (1)
    {                                           // while pour garder le cli ouvert, trop stylé
        printf("Entrez une commande : ");       // printf arbre interractif
        fgets(command, sizeof(command), stdin); // user saisie la commande
        if (strncmp(command, "createnode", 10) == 0)
        {                                       // compare si l'entrée "command" avec "createnode"
            sscanf(command + 11, "%d", &value); // je donne à l'addresse value la valeur entrée après le 11eme caractère (entier entré par le user)
            root = insertnode(root, value);     // utilisation de insert node à la place de createnode
            printf("Nœud %d inséré.\n", value); // prinf intéractif
        }
        else if (strncmp(command, "deletenode", 10) == 0)
        {                                         // compare avec l'entrée user les 10 premier caractère
            sscanf(command + 11, "%d", &value);   // attribue à l'addresse de value l'entrée de l'user après les 11 caractères (10 + espace)
            root = deletenode(root, value);       // root noeud racine, value = entrée user, on delete
            printf("Nœud %d supprimé.\n", value); // print intéractif (%d entier)
        }
        else if (strncmp(command, "printtree", 9) == 0)
        {
            printf("Parcours de l'arbre en ordre croissant : "); // print intéractif
            printtraversal(root);                                // appel la fonction printraversal avec la valeur de du noeud racine
            printf("\n");                                        // print intéractif
        }
        else if (strncmp(command, "printascii", 10) == 0)
        {                                                         // compare avec l'entrée user les 10 premier caractère
            printf("Affichage de l'arbre binaire en ASCII : \n"); // printf arbre interractif
            printascii(root, 0);                                  // appel initial root et 0
        }
        else if (strncmp(command, "save", 4) == 0) //
        {
            FILE *file = fopen("esgi_tree.txt", "w"); // sauvegarde l'arbre dans un txt en mode écriture
            if (file == NULL)                         // si pas de fichier
            {
                perror("Erreur lors de l'ouverture du fichier pour sauvegarde"); // test bug
            }
            else
            {
                saveTreeToFile(root, file); // sinon sauvegarde racine dans le fichier
                fclose(file);               // ferme le fichier
                printf("Arbre sauvegardé dans esgi_tree.txt.\n");
            }
        }
        else if (strncmp(command, "load", 4) == 0)
        {                                             // check : https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)Persistence.html
            FILE *file = fopen("esgi_tree.txt", "r"); // ouvre esgitree en mode lecture
            if (file == NULL)                         // si pas de fichier
            {
                printf("Erreur lors de l'ouverture du fichier.\n"); // test bug
            }
            else
            {
                root = loadTreeFromFile(file); // Mets bien à jour la variable `root`
                fclose(file);                  // femre le fichier
                printf("Arbre chargé depuis esgi_tree.txt.\n");
                printf("Parcours de l'arbre après chargement : "); // test bug
                printtraversal(root);                              // test bug
                printf("\n");
            }
        }
        else if (strncmp(command, "quit", 4) == 0)
        {                                        // compare l'entrée command dois correspondre aux 4 premier caractère de quit
            printf("Fermeture du programme.\n"); // print intéractif
            break;                               // ferme la boucle while, qui le programme
        }
        else
        {
            printf("Commande non reconnue. Veuillez réessayer.\n"); // Si saisie pas de commande répertoriée, resaisir
        }
    }
}
