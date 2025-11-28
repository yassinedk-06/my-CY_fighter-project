#ifndef COMBAT_H
#define COMBAT_H

#include "structure.h"
#include "choix.h"
#include "menu.h"

// Affiche les bonus/malus de chaque arme possible
void afficher_stats();

// Applique les effets visuels (AffichagePerso) d’une arme sélectionnée
void atout(AffichagePerso *p, int a);

// Applique les effets réels (Player) d’une arme sélectionnée
void vraiatout(Player* p, int a);

// Permet à un joueur de choisir ses armes une par une
void choix_assets(int equipe[], int nbr_joueur, Player eq_stats[], AffichagePerso persos_affichage[]);

// Lance le choix d'armes pour deux équipes en mode PvP
void choix_assets_E(int equipe1[], int equipe2[], int nbr_joueur, Player eq1_stats[], Player eq2_stats[], AffichagePerso persos_affichage[]);

// Affiche les emojis correspondant aux effets actifs d’un joueur
void afficher_emojis_effets(Player p);

// Affiche tout l’état du combat (noms, PV, effets, progression des joueurs)
void afficher_etat_combat(Player eq1[], Player eq2[], int joueur_actuel, int equipe_joueur, int nbr_joueur);

// Gère l’attaque classique avec sélection de cible par le joueur
void attaque_classique(Player* attaquant, Player ennemis[], int nbr_joueur);

// Gère l’attaque classique directe (utilisé par l’IA)
void attaque_classique_direct(Player* attaquant, Player* cible);

// Lance la compétence spéciale d’un joueur
void utiliser_competence(Player* lanceur, Player equipe[], Player ennemis[], int nbr_joueur);

// Applique l’effet réel d’une compétence spéciale (avec ou sans interaction joueur selon is_ordi)
void appliquer_effet(Player* lanceur, Player equipe[], Player ennemis[], int nbr_joueur, int is_ordi);

// Diminue le compteur de recharge d’une compétence
void update_competence(Player* p);

// Met à jour les effets temporaires (fin de buff, réinitialisation des stats)
void update_effets(Player* p);

// Vérifie si une équipe est complètement K.O.
int equipe_KO(Player equipe[], int nbr_joueur);

// Affiche un message et attend que l’utilisateur appuie sur Entrée
void attendreEntree();

// Fonction principale qui gère le déroulement du combat, que ce soit PvP ou PvC
void combat(Player eq1_stats[], Player eq2_stats[], int nbr_joueur, AffichagePerso affichage[], int mode, int difficulte);

#endif
