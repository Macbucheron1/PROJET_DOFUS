#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <stdbool.h>

#define LIGNE_TABLEAU 16
#define COLONNE_TABLEAU 20

#define TAILLE_NOM_CLASSE 15
#define TAILLE_SKINS 15

/* ----------- STRUCTURE DE DONNEES ----------- */

typedef struct Cases{
    int position_pixel_x;
    int position_pixel_y;
}t_cases;

typedef struct Map{
    int map_obstacle[COLONNE_TABLEAU][LIGNE_TABLEAU];
    BITMAP* fond_map;
    t_cases tab_coordonnes[COLONNE_TABLEAU][LIGNE_TABLEAU];
}t_map;

typedef struct Personnage{ //les classes
    int numero_classe; // de 1 à 4 pour differencier les classes plus facilement
    char nom_classe[TAILLE_NOM_CLASSE];
    int pv_max; //si soin ne pas depasser ce pv max
    int pm_max; // afin de remettre a ca a chaque tour
    int pa_max; // pareil
    int pv_actuel;
    int pm_actuel;
    int pa_actuel;
    BITMAP* skin[TAILLE_SKINS];

    //pour les attaques
    int max_meditation; //limite de meditation de la classe jedi (sinon gagne trop de PM)
    bool bouclier; //si la classe tank active son bouclier true, sinon false
    int tour_bouclier; //commence a 0 et sincrement a chaque tour
    int tour_bouclier_max; //a partir de cb de tour le bouclier doit se desactiver
    int PM_roule; //si true augmente les PM du tank (se desactive au bout d'1 tour)
    bool en_feu; //si true prend des degats sinon rien
    int tour_en_feu; //comme tour bouclier
    int tour_en_feu_max; //pareil

}t_personnage;

typedef struct Joueur{
    char nom_joueur[30];
    int numero_joueur;
    t_personnage* classe;
    int position_colonne;
    int position_ligne;
} t_joueur;

/* ----------- FONCTION AFFICHAGE ----------- */

void prepa_alleg(void); // Lance alleg init et verifie qu'il fonctionne bien
void erreur_chargement_image(BITMAP* image); // Verifie qu'on a bien charger l'image
void changement_graphique(int valeur); // Permet de changer de mode graphique
void affichage_grille(BITMAP* buffer); // Permet d'afficher la grille sur la map


/* ----------- SOUS PROGRAMME ----------- */

void init_map(t_map* carte); // Permet d'initaliser une map
void remplir_tab_coordonnes(t_map* carte); // Permet de remplir les coordonnées de la map
void remplir_map_obstacle(t_map* carte); // Permet de remplir les types de chaque case
int position_souris_colonne(void); // Renvoie la colonne dans lequel se situe la souris, renvoie -1 si pas dans une colonne
int position_souris_ligne(void); // Renvoie la ligne dans lequel se situe la souris, renvoie -1 si pas dans une ligne

/* ----------- INITIALISATION ----------- */

t_personnage init_classes(char* nom_classe,int num_classe,int p_action_max, int p_vie_max,int p_mvt_max,BITMAP** skin);
void init_tab_skin(int nb_skin_total,char* nom_classe,BITMAP** tab_skin);

#endif // HEADER_H_INCLUDED
