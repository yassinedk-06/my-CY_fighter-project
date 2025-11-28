#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "structure.h"
#include "choix.h"
#include "combat.h"
#include "computer.h"

#define NB_PERSOS 12 // Nombre total de personnages disponibles

int main() {
    int mode = 0, nbr_joueur = 0, difficulte = 1; // Mode de jeu, taille des équipes, et niveau de difficulté pour l'IA
    int equipe1[3], equipe2[3]; // Stocke les indices des personnages choisis pour chaque équipe

    Player persos[NB_PERSOS]; // Tableau contenant les données complètes des personnages
    AffichagePerso affichage[NB_PERSOS]; // Données simplifiées pour l'affichage en menu

    // Chargement des données depuis les fichiers textes
    chargerPersonnages(persos, NB_PERSOS);      // personnages.txt
    chargerTechniques(persos, NB_PERSOS);       // techniques.txt
    chargerAffichage(affichage, persos, NB_PERSOS); // données d'affichage dérivées des personnages

    // Interface utilisateur
    afficherTitre();                            // Affiche l'écran de titre
    afficherMenu(&mode, &nbr_joueur);           // Demande le mode (PvP / PvC) et la taille de l’équipe
    afficherTousLesPersos(affichage);           // Affiche la liste complète des personnages disponibles

    if (mode == 1) {
        // Mode Joueur vs Joueur : chaque joueur choisit ses persos
        choix_joueur(equipe1, equipe2, nbr_joueur, mode, affichage);
    } else {
        // Mode Joueur vs Ordinateur :
        // Le joueur choisit son équipe, l'ordinateur choisit la sienne automatiquement
        choix_joueur_E(equipe1, nbr_joueur, affichage);
        choix_ordi_persos(equipe2, nbr_joueur);
    }

    // Création des équipes avec les vraies stats copiées depuis les personnages
    Player eq1_stats[nbr_joueur + 1];
    Player eq2_stats[nbr_joueur + 1];
    for (int i = 0; i <= nbr_joueur; i++) {
        eq1_stats[i] = persos[equipe1[i] - 1]; // Copie des données du personnage vers l’équipe 1
        eq2_stats[i] = persos[equipe2[i] - 1]; // Idem pour l’équipe 2
    }

    // Choix des armes (assets)
    if (mode == 1)
        // Mode PvP : chaque joueur choisit les armes de ses combattants
        choix_assets_E(equipe1, equipe2, nbr_joueur, eq1_stats, eq2_stats, affichage);
    else {
        // Mode PvC : joueur choisit ses armes, l’ordi les choisit au hasard
        afficher_stats(); // Affiche les bonus/malus des assets
        choix_assets(equipe1, nbr_joueur, eq1_stats, affichage); // Choix du joueur
        attendreEntree();
        choix_ordi_assets(equipe2, nbr_joueur, eq2_stats, affichage); // Choix automatique pour l’IA
        attendreEntree();

        // Choix de la difficulté de l'IA
        printf("\n+================ DIFFICULTÉ ================+\n");
        printf("1. Noob    (attaque aléatoire)\n");
        printf("2. Facile  (attaque le plus faible)\n");
        printf("3. Moyen   (utilise les compétences intelligemment)\n\n");
        difficulte = demanderChoixDansIntervalle("Choisis la difficulté", 1, 3, JAUNE);
    }

    // Lancement du combat
    combat(eq1_stats, eq2_stats, nbr_joueur, affichage, mode, difficulte);
    return 0;
}
