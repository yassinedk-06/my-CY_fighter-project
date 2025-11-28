# MEF2-E-CY-FIGHTERS
Présentation

CY Fighters est un petit jeu de combat tour par tour codé en C. Il se joue dans le terminal.
Le but est de créer deux équipes de personnages (2v2 ou 3v3) et de les faire s’affronter jusqu’à ce qu’une des deux soit complètement K.O.

⸻

Fonctionnalités
	•	12 personnages jouables, chacun avec ses propres statistiques et une technique spéciale
	•	2 modes de jeu :
	•	Joueur vs Joueur
	•	Joueur vs Ordinateur avec 3 niveaux :
	•	Noob : l’ordi attaque au hasard
	•	Facile : l’ordi attaque le plus faible
	•	Moyen : l’ordi utilise ses compétences et réfléchit un peu plus
	•	Système d’armes (appelées “assets”) qui modifient les stats
	•	Affichage des PV sous forme de barres + effets spéciaux visibles en emoji
	•	Gestion de la vitesse : les persos ne jouent pas tous en même temps

⸻

Fichiers importants
	•	main.c : lancement du jeu, menu, choix des équipes
	•	menu.c : affichage du titre, du menu, etc.
	•	choix.c : sélection des persos par les joueurs ou l’ordi
	•	structure.c : chargement des données (persos + techniques)
	•	combat.c : système de combat complet (attaques, compétences, effets…)
	•	computer.c : IA de l’ordinateur (niveau de difficulté, cibles, décisions)
	•	personnages.txt : données de base des 12 personnages
	•	techniques.txt : description des techniques spéciales

⸻

Compilation

Pour compiler le jeu, il suffit de taper : make
Pour nettoyer les fichiers objets : make clean
Lancement

Une fois compilé, le jeu se lance avec : ./exec

______

Nos points en plus
	
 •	Le mode contre l’ordinateur poussé, avec trois niveaux de difficulté codés proprement.
	•	On a fait attention à l’interface : couleurs, emojis, lisibilité dans le terminal.
	•	Le système de combat est dynamique (ordre des tours en fonction de la vitesse) pour éviter un simple aller-retour.
	•	Tous les effets (soins, buffs, attaques en zone, etc.) sont bien pris en compte, même côté IA.

 ______

 Conclusion

Ce projet nous a permis de mettre en pratique la programmation en C avec des structures, de la logique de jeu, de l’affichage en terminal et un peu d’IA.
Il reste des choses à améliorer, mais on est satisfaits du résultat final pour un projet de première année.
