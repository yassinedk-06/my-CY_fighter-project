#ifndef COMPUTER_H
#define COMPUTER_H

#include "structure.h"
#include "combat.h"

// Fonction qui permet à l'ordinateur de choisir aléatoirement ses personnages sans doublons
void choix_ordi_persos(int *equipe, int nbr_joueur);

// L'ordinateur choisit une arme au hasard pour chaque personnage et applique les effets
void choix_ordi_assets(int *equipe, int nbr_joueur, Player *eq_stats, AffichagePerso *affichage);

// Retourne l'index du combattant adverse ayant le moins de PV (mais encore en vie)
int trouver_cible_plus_faible(Player *ennemis, int nbr_joueur);

// Gère entièrement un tour de l'ordinateur selon la difficulté choisie (1, 2 ou 3)
void tour_ordinateur(Player *ordi, Player *ennemis, Player *alliés, int nbr_joueur, int difficulte);

#endif
