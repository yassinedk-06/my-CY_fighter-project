#include <stdio.h>
#include <stdlib.h>
#include "choix.h"
#include "structure.h"

// Fonction générique pour demander un choix entre deux bornes incluses
int demanderChoixDansIntervalle(const char *texte, int min, int max, const char *couleur) {
    int choix = 0;
    char ligne[10];

    do {
        // Affichage de la question avec couleur
        printf("%s%s (%d à %d) : " RESET, couleur, texte, min, max);

        // Lecture de la ligne saisie par l'utilisateur
        if (fgets(ligne, sizeof(ligne), stdin)) {
            // Vérifie si la saisie est bien un entier dans l'intervalle
            if (sscanf(ligne, "%d", &choix) == 1 && choix >= min && choix <= max) {
                return choix;
            }
        }

        // Si la saisie est invalide, message d'erreur
        printf(ROUGE "Choix incorrect, rechoisis\n" RESET);
    } while (1);
}

// Fonction pour que le joueur sélectionne ses personnages (entre 2 et 3)
void choix_joueur_E(int *equipe, int nbr_joueur, AffichagePerso persos_affichage[]) {
    int x = -1, y = -1; // Pour éviter les doublons

    for (int i = 0; i <= nbr_joueur; i++) {
        switch(i) {
            case 0:
                // Premier personnage
                equipe[i] = demanderChoixDansIntervalle("👉 Choisis le premier Personnage", 1, 12, JAUNE);
                x = equipe[i];
                break;

            case 1:
                // Deuxième personnage (doit être différent du premier)
                equipe[i] = demanderChoixDansIntervalle("👉 Choisis le deuxième Personnage", 1, 12, JAUNE);
                while(equipe[i] == x){
                    equipe[i] = demanderChoixDansIntervalle(" Vous ne pouvez pas choisir deux fois le même personnage", 1, 12, ROUGE);
                }
                y = equipe[i];
                break;

            case 2:
                // Troisième personnage (différent des deux premiers)
                equipe[i] = demanderChoixDansIntervalle("👉 Choisis le troisième Personnage", 1, 12, JAUNE);
                while(equipe[i] == x || equipe[i] == y){
                    equipe[i] = demanderChoixDansIntervalle(" Vous ne pouvez pas choisir deux fois le même personnage", 1, 12, ROUGE);
                }
                break;

            default:
                // Ce cas ne devrait jamais arriver (protection)
                printf("Erreur : nombre de personnages non supporté\n");
                exit(1);
        }

        // Affiche le nom du personnage sélectionné
        printf("✅  Vous avez choisi : %s\n", persos_affichage[equipe[i] - 1].nom);
    }
}

// Fonction générale pour faire choisir les personnages aux deux équipes
void choix_joueur(int *equipe1, int *equipe2, int nbr_joueur , int mode, AffichagePerso persos_affichage[]) {
    switch(mode){
        case 1: // PvP
            printf("\n👥  EQUIPE 1, c’est à votre tour :\n");
            choix_joueur_E(equipe1, nbr_joueur, persos_affichage);
            printf("\n👥  EQUIPE 2, c’est à votre tour :\n");
            choix_joueur_E(equipe2, nbr_joueur, persos_affichage);
            break;

        case 2: // PvC (équipe 2 sera choisie automatiquement dans main.c)
            printf("\n👥  EQUIPE 1, c’est à votre tour :\n");
            choix_joueur_E(equipe1, nbr_joueur, persos_affichage);
            break;

        default:
            // Cas de sécurité
            printf("Erreur : mode non supporté\n");
            exit(1);
    }

    // Pause avant de passer à l'étape suivante
    printf("\n Appuie sur Entrée pour continuer... \n");
    while (getchar() != '\n');
}
