#ifndef STRUCTURE_H
#define STRUCTURE_H

// Codes ANSI pour les couleurs (utilisés dans les printf pour mise en forme console)
#define ROUGE   "\033[1;31m"
#define VERT    "\033[1;32m"
#define JAUNE   "\033[1;33m"
#define BLEU    "\033[1;36m"
#define RESET   "\033[0m"

// Valeurs globales définies pour les stats
#define PVMAX 120       // PV maximum par défaut
#define ENNERGIE 10     // Non utilisé dans le projet, mais défini

// Structure utilisée uniquement pour l'affichage visuel des personnages (menu)
typedef struct {
    char* nom;      // Nom affiché ex : "(1) Luffy"
    int pv;         // PV simplifié (échelle visuelle)
    int att;        // Attaque
    int def;        // Défense
    int speed;      // Vitesse
    int dodge;      // Esquive
    int crit;       // Coup critique (valeur non utilisée pour l’instant)
} AffichagePerso;

// Structure contenant les vraies statistiques d’un personnage
typedef struct {
    float pv;           // Points de vie actuels
    float pv_max;       // Points de vie maximum
    float def;          // Défense (0.0 à 1.0)
    float att;          // Attaque (multiplicateur de dégâts)
    int speed;          // Vitesse (remplit la jauge de tour)
    float dodge;        // Probabilité d'esquive (ex : 0.3 = 30%)
} Stats;

// Structure jamais utilisée dans le code (prévue pour des effets, mais vide ici)
typedef struct {
    int pv;
    int att;
    int def;
    int speed;
    int dodge;
} Effect;

// Décrit une attaque spéciale pour un personnage
typedef struct {
    char* name;             // Nom de la technique
    float valeur;           // Valeur du bonus/dégâts (interprétation selon effet)
    char description[200];  // Description affichée
    int tour_actif;         // Durée de l'effet (en tours)
    int recharge;           // Compteur de recharge actuel (décroît à 0)
    int recharge_max;       // Combien de tours faut-il attendre avant de réutiliser
    Effect buff;            // Champ inutilisé dans le projet
    char effet_type[20];    // Type d'effet (ex : "pv+", "aoe", "def--", etc.)
} Special;

// Structure principale représentant un personnage complet dans le jeu
typedef struct {
    char* name;             // Nom du personnage
    Stats stats;            // Statistiques de base
    Stats stats_temp;       // Statistiques temporaires (modifiées pendant le combat)
    Special atk_spe;        // Attaque spéciale
    int tour_buff_restant;  // Durée restante des effets spéciaux actifs
    int barre_vitesse;      // Jauge de tour (quand >=1000, le personnage joue)
} Player;

// Déclarations des fonctions de chargement (implémentées dans structure.c)
Player initialiserJoueur(int index); // Pas utilisée
AffichagePerso getAffichagePerso(int index); // Pas utilisée

void chargerPersonnages(Player persos[], int taille);
void chargerTechniques(Player persos[], int taille);
void chargerAffichage(AffichagePerso aff[], Player persos[], int taille);

#endif
