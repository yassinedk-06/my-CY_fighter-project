#ifndef MENU_H
#define MENU_H

// Inclusion des structures nécessaires pour les fonctions du menu
#include "structure.h"
#include "choix.h"
#include "combat.h"

// Affiche le logo ASCII du jeu au lancement
void afficherTitre();

// Affiche le menu principal pour sélectionner le mode de jeu (PVP/PVC) et la taille de l’équipe
// Les valeurs sont retournées via pointeurs :
//   - mode = 1 (PVP), 2 (PVC)
//   - nbr_joueur = 1 (2v2), 2 (3v3)
void afficherMenu(int *mode , int *nbr_joueur);

// Affiche l’ensemble des personnages avec leurs statistiques simplifiées (graphique)
void afficherTousLesPersos(AffichagePerso persos_affichage[]);

// Affiche une barre graphique (#) représentant une statistique de 0 à 8
void afficherBarre(int valeur);

// Affiche les statistiques d’un seul personnage (nom + barres PV/ATT/DEF/etc.)
void afficherPersonnage(int x, AffichagePerso persos_affichage[]);

#endif
