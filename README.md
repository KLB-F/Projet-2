# Projet-2
Projet n°2 : simulation de la propagation d'une onde selon d'Alembert

# Présentation
Ce projet à pour but de simuler la propagation d'une onde selon d'Alembert.
Il utilise la méthode des éléments finis, à l'aide d'une matrice, pour simuler en temps réel la propagation d'une onde.
Les conditions initiales sont fixées de la manière suivante : une valeur de la matrice est fixée à une certaines valeur initiale.

# Principals fonctionnalités

Rapidité : le programme écrit en C++ et SFML permet d'être assez rapide, d'autant que l'optimisation temporelle à été prise en compte dans la manière de coder.
Ainsi, sur mon ordinateur, qui n'est pas le plus performant, j'arrive à atteindre les 400 000 cases actualisées 100 fois par seconde.

Gestion temporelle : le programme intègre un système de gestion temporelle, il permet de gérer indépendamment les actualisations graphiques et physiques.

# Fichier

Main.cpp : fichier principal

Phy_Principale.cpp/.h : classe s'occupant de la gestion de la propagation et de la matrice

fenetre.cpp/.h : classe s'occupant de la partie graphique

GTemps.cpp/.h : classe ayant la gestion temporelle des actualisations graphique et physique

# Remarque

Rq : ce projet est un vieux projet de terminale, il a été "dépoussiéré" pour l'occasion. (création d'une release pour Windows et ajout de commentaires, mais le code est resté le même)
Ainsi, comme il n'est pas fini, il manque des composants parmi lesquelles :
- un moyen d'interagir avec l'utilisateur
- un dispositif "anti-dérive ", car les calculs pour actualiser la matrice étant très précis (utilisation du type double, intervalle de temps réduits), il n'en reste néanmoins que des erreurs existent et font "dériver" le signal (sa somme, qui devrait être constante diverge vers +inf) aux bouts de quelques secondes.
