#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>

#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#define TAILLE_TABLEAU 10

/* ----------- STRUCTURE DE DONNEES ----------- */

typedef struct Cases{
    int position_pixel_x;
    int position_pixel_y;
}t_cases;

typedef struct Map{
    int* map_obstacle[TAILLE_TABLEAU];
    BITMAP* fond_map;
    t_cases* tab_coordonnes[TAILLE_TABLEAU];
}t_map;

typedef struct Personnage{
    int numero_classe;
    char nom_classe[30];
    int pv_max;
    int pm_max;
    int pa_max;
    int pv_actuel;
    int pm_actuel;
    int pa_actuel;
}t_personnage;

/* ----------- FONCTION AFFICHAGE ----------- */

void prepa_alleg(void); // Lance alleg init et verifie qu'il fonctionne bien
void erreur_chargement_image(BITMAP* image); // Verifie qu'on a bien charger l'image
void changement_graphique(int valeur); // Permet de changer de mode graphique


/* ----------- FONCTION AFFICHAGE ----------- */

void init_map(t_map* carte); // Permet d'initaliser une map

#endif // HEADER_H_INCLUDED
