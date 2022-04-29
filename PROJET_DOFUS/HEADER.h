#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>

#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#define LIGNE_TABLEAU 16
#define COLONNE_TABLEAU 20

/* ----------- STRUCTURE DE DONNEES ----------- */

typedef struct{
    int x;
    int y;
}coords;

typedef struct Cases{
    int position_pixel_x;
    int position_pixel_y;
}t_cases;

typedef struct Map{
    int map_obstacle[COLONNE_TABLEAU][LIGNE_TABLEAU];
    BITMAP* fond_map;
    t_cases tab_coordonnes[COLONNE_TABLEAU][LIGNE_TABLEAU];
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
    BITMAP* skin;
}t_personnage;

typedef struct Joueur{
    char nom_joueur[30];
    int numero_joueur;
    t_personnage classe;
    int position_colonne;
    int position_ligne;
} t_joueur;

/* ----------- FONCTION AFFICHAGE ----------- */

void prepa_alleg(void); // Lance alleg init et verifie qu'il fonctionne bien
void erreur_chargement_image(BITMAP* image); // Verifie qu'on a bien charger l'image
void changement_graphique(int valeur); // Permet de changer de mode graphique
void affichage_grille(BITMAP* buffer); // Permet d'afficher la grille sur la map
void affichagePerso(BITMAP* buffer, BITMAP* soldat, t_map carte,int x,int y); //permet d'afficher un personnage
void SurbrillanceDeplacement(BITMAP* buffer,t_map carte, int tab[20][16]); //est appelé par CalculDeplacement, permet d'afficher des carres verts sur les cases contenant des 1 dans le tableau tab
void afficheSouris(BITMAP* buffer,t_map carte, int tab[20][16]); // est appelé par SurbrillanceDeplacement et affiche un carré bleu a la position de la souris (si la souris se trouve dans la zone de deplacement)


/* ----------- SOUS PROGRAMME ----------- */

void init_map(t_map* carte); // Permet d'initaliser une map
void remplir_tab_coordonnes(t_map* carte); // Permet de remplir les coordonnées de la map
void remplir_map_obstacle(t_map* carte); // Permet de remplir les types de chaque case
int position_souris_colonne(void); // Renvoie la colonne dans lequel se situe la souris, renvoie -1 si pas dans une colonne
int position_souris_ligne(void); // Renvoie la ligne dans lequel se situe la souris, renvoie -1 si pas dans une ligne
void CalculDeplacement(BITMAP* buffer, t_map carte, int x_soldat,int y_soldat, int tab[20][16], int PM_restant); //Remplis le tableau tab,avec des 1, sur les cases sur lesquelles peut aller le joueur
int Deplacement(t_map carte, int tab[20][16], coords *position); //Recupere dans la struct position, la position fde la souris lors du click, renvoie le nb de PM utilisés
int CalculChemin( t_map carte, int x1,int y1,int x2,int y2, int tab[20][16], int PM_restant,coords chemin[]);//Stock le chemin dans le tableau chemin si il est possible, sinon renvoie -1
#endif // HEADER_H_INCLUDED
