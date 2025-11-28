#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "computer.h"

// Fonction utilisée en mode PvC pour permettre à l'ordinateur de choisir aléatoirement des personnages sans doublons
void choix_ordi_persos(int *equipe, int nbr_joueur) {
    int dispo[12] = {0}; // Tableau pour vérifier les personnages déjà pris
    for (int i = 0; i <= nbr_joueur; i++) {
        int r;
        do {
            r = rand() % 12; // Choix aléatoire entre 0 et 11
        } while (dispo[r]); // On boucle tant que le personnage est déjà choisi
        dispo[r] = 1;
        equipe[i] = r + 1; // On stocke l'indice + 1 (car affichage commence à 1)
        printf("🤖 Ordi a choisi le perso %d\n", equipe[i]);
    }
}

// L’ordinateur choisit une arme aléatoire pour chaque personnage et applique ses effets
void choix_ordi_assets(int *equipe, int nbr_joueur, Player *eq_stats, AffichagePerso *affichage) {
    for (int i = 0; i <= nbr_joueur; i++) {
        int choix = rand() % 6 + 1; // Choix entre 1 et 6
        printf("🤖 Ordi donne arme %d à %s\n", choix, eq_stats[i].name);
        atout(&affichage[equipe[i] - 1], choix);   // Modification pour l'affichage
        vraiatout(&eq_stats[i], choix);            // Application réelle des effets sur le joueur
    }
}

// Fonction qui renvoie l'index du combattant adverse avec le moins de PV > 0
int trouver_cible_plus_faible(Player *ennemis, int nbr_joueur) {
    int min_index = -1;
    float min_pv = 100000; // Très grande valeur initiale
    for (int i = 0; i <= nbr_joueur; i++) {
        if (ennemis[i].stats_temp.pv > 0 && ennemis[i].stats_temp.pv < min_pv) {
            min_pv = ennemis[i].stats_temp.pv;
            min_index = i;
        }
    }
    return min_index;
}

// Gère le tour complet de l'ordinateur selon la difficulté sélectionnée
void tour_ordinateur(Player *ordi, Player *ennemis, Player *alliés, int nbr_joueur, int difficulte) {
    printf("🤖 Tour de %s (ordi - difficulté %d)\n", ordi->name, difficulte);

    switch (difficulte) {
        case 1: { // Niveau noob : attaque un ennemi au hasard
            int cible;
            do {
                cible = rand() % (nbr_joueur + 1);
            } while (ennemis[cible].stats_temp.pv <= 0); // Ignore les cibles K.O.
            printf("🤖 Ordi attaque un ennemi aléatoire : %s\n", ennemis[cible].name);
            attaque_classique_direct(ordi, &ennemis[cible]); // Attaque directe
            break;
        }
        case 2: { // Niveau facile : attaque le plus faible
            int cible = trouver_cible_plus_faible(ennemis, nbr_joueur);
            if (cible != -1) {
                printf("🤖 Ordi attaque le plus faible : %s\n", ennemis[cible].name);
                attaque_classique_direct(ordi, &ennemis[cible]);
            }
            break;
        }
        case 3: { // Niveau moyen : compétence si possible, sinon attaque intelligente
            if (ordi->atk_spe.recharge == 0) {
                printf("🤖 Ordi utilise sa compétence : %s\n", ordi->atk_spe.name);
                printf("⌀ %s\n", ordi->atk_spe.description);
                appliquer_effet(ordi, alliés, ennemis, nbr_joueur, 1); // is_ordi = 1
                ordi->atk_spe.recharge = ordi->atk_spe.recharge_max; // Recharge la compétence
                attendreEntree();
            } else {
                int cible = trouver_cible_plus_faible(ennemis, nbr_joueur);
                if (cible != -1) {
                    printf("🤖 Ordi attaque %s\n", ennemis[cible].name);
                    attaque_classique_direct(ordi, &ennemis[cible]);
                }
            }
            break;
        }
    }
}
