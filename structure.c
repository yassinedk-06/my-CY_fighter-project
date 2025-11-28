#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

#define MAX_LIGNE 256  // Taille maximale d'une ligne lue dans les fichiers

// Fonction qui charge les personnages depuis le fichier personnages.txt
void chargerPersonnages(Player persos[], int taille) {
    FILE *f = fopen("personnages.txt", "r");
    if (!f) {
        perror("Erreur ouverture personnages.txt");
        exit(1); // Quitte le programme si le fichier est introuvable
    }

    char ligne[MAX_LIGNE];
    fgets(ligne, MAX_LIGNE, f); // Ignore la première ligne (en-tête)

    for (int i = 0; i < taille; i++) {
        if (fgets(ligne, MAX_LIGNE, f)) {
            // Déclaration des variables pour lire les données
            char nom[50];
            int pv, att, speed, crit;
            float def, dodge;

            // Lecture des valeurs depuis la ligne
            sscanf(ligne, "%[^;];%d;%d;%f;%d;%f;%d", nom, &pv, &att, &def, &speed, &dodge, &crit);

            // Remplissage des données dans le tableau persos
            persos[i].name = strdup(nom);
            persos[i].stats.pv = pv;
            persos[i].stats.pv_max = PVMAX;
            persos[i].stats.att = att;
            persos[i].stats.def = def;
            persos[i].stats.speed = speed;
            persos[i].stats.dodge = dodge;
            persos[i].stats_temp = persos[i].stats; // stats temporaires initialisées avec les valeurs de base
            persos[i].tour_buff_restant = 0; // Aucun effet actif au début
        }
    }

    fclose(f); // Fermeture du fichier
}

// Fonction qui charge les techniques spéciales depuis le fichier techniques.txt
void chargerTechniques(Player persos[], int taille) {
    FILE *f = fopen("techniques.txt", "r");
    if (!f) {
        perror("Erreur ouverture techniques.txt");
        exit(1); // Quitte si le fichier n’est pas disponible
    }

    char ligne[MAX_LIGNE];
    fgets(ligne, MAX_LIGNE, f); // Ignore l'en-tête

    for (int i = 0; i < taille; i++) {
        if (fgets(ligne, MAX_LIGNE, f)) {
            // Variables temporaires pour récupérer les données
            char nom[50], effet[20], description[200];
            float valeur;
            int tours, recharge;

            // Extraction des valeurs du fichier
            sscanf(ligne, "%[^;];%f;%[^;];\"%[^\"]\";%d;%d", nom, &valeur, effet, description, &tours, &recharge);

            // Remplissage de la structure de technique spéciale
            persos[i].atk_spe.name = strdup(nom);
            persos[i].atk_spe.valeur = valeur;
            strncpy(persos[i].atk_spe.description, description, sizeof(persos[i].atk_spe.description));
            persos[i].atk_spe.tour_actif = tours;
            persos[i].atk_spe.recharge = 0; // Toujours 0 au début
            persos[i].atk_spe.recharge_max = recharge;
            strncpy(persos[i].atk_spe.effet_type, effet, sizeof(persos[i].atk_spe.effet_type));
        }
    }

    fclose(f); // Fermeture du fichier
}

// Fonction qui initialise l’affichage simplifié des personnages pour le menu
void chargerAffichage(AffichagePerso aff[], Player persos[], int taille) {
    for (int i = 0; i < taille; i++) {
        char buffer[32];
        // Génère le texte affiché pour le nom, ex: "(1) Luffy"
        snprintf(buffer, sizeof(buffer), "(%d)  %s", i + 1, persos[i].name);
        aff[i].nom = strdup(buffer);

        // Transforme les vraies stats en valeurs simplifiées pour affichage visuel
        aff[i].pv = persos[i].stats.pv / 20;        // Normalisé sur 5-6
        aff[i].att = persos[i].stats.att;
        aff[i].def = (int)(persos[i].stats.def * 10);  // DEF en échelle 0-5
        aff[i].speed = persos[i].stats.speed;
        aff[i].dodge = (int)(persos[i].stats.dodge * 10);
        aff[i].crit = 3; // Valeur par défaut (non personnalisée dans les données)
    }
}
