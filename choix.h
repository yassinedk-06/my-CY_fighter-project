#ifndef CHOIX_H
#define CHOIX_H

#include "structure.h" // Pour utiliser AffichagePerso

// Définition des codes couleurs ANSI pour l'affichage terminal
#define ROUGE   "\033[1;31m"
#define VERT    "\033[1;32m"
#define JAUNE   "\033[1;33m"
#define BLEU    "\033[1;36m"
#define RESET   "\033[0m"

// Demande à l'utilisateur un entier entre min et max, avec un message en couleur
int demanderChoixDansIntervalle(const char *texte, int min, int max, const char *couleur);

// Permet à un joueur de choisir ses personnages (sans doublon)
void choix_joueur_E(int *equipe, int nbr_joueur, AffichagePerso persos_affichage[]);

// Gestion du choix des personnages pour les deux équipes selon le mode (PvP ou PvC)
void choix_joueur(int *equipe1, int *equipe2, int nbr_joueur , int mode, AffichagePerso persos_affichage[]);

#endif
