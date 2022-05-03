
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
    int nb_bacta; //initialiser a 0 contre le nombre de seringue utilisée
    int nb_bacta_max; //limite l'utilisation de seringue de bacta (pour les chasseur de primes)

}t_personnage;

typedef struct Joueur{
    char nom_joueur[30];
    int numero_joueur;
    t_personnage classe;
    int position_colonne;
    int position_ligne;
} t_joueur;

typedef struct Decor{
    BITMAP* visuel;
    int position_x;
    int position_y;
    int avancement_x;
    int avancement_y;
} t_decor;

/* ----------- FONCTION AFFICHAGE ----------- */

void changement_graphique(int valeur); // Permet de changer de mode graphique
void affichage_grille(BITMAP* buffer); // Permet d'afficher la grille sur la map
void montre_curseur(BITMAP* page); // Permet d'afficher un curseur personnalisé
void affichagePerso(BITMAP* buffer, BITMAP* soldat, t_map carte,int x,int y); //permet d'afficher un personnage
void SurbrillanceDeplacement(BITMAP* buffer,t_map carte, int tab[20][16]); //est appelé par CalculDeplacement, permet d'afficher des carres verts sur les cases contenant des 1 dans le tableau tab
void afficheSouris(BITMAP* buffer,t_map carte, int tab[20][16]); // est appelé par SurbrillanceDeplacement et affiche un carré bleu a la position de la souris (si la souris se trouve dans la zone de deplacement)
void AnimationDeplacement(BITMAP* buffer, BITMAP* soldat, t_map carte, int x_initial, int y_initial, t_joueur joueurActuel, coords chemin[], int PM); // Fait l'animation de deplacement


/* ----------- SOUS PROGRAMME ----------- */

void remplir_tab_coordonnes(t_map* carte); // Permet de remplir les coordonnées de la map
void remplir_map_obstacle(t_map* carte); // Permet de remplir les types de chaque case
int position_souris_colonne(void); // Renvoie la colonne dans lequel se situe la souris, renvoie -1 si pas dans une colonne
int position_souris_ligne(void); // Renvoie la ligne dans lequel se situe la souris, renvoie -1 si pas dans une ligne
void prepa_alleg(void); // Lance alleg init et verifie qu'il fonctionne bien
void erreur_chargement_image(BITMAP* image); // Verifie qu'on a bien charger l'image
void CalculDeplacement(BITMAP* buffer, t_map carte, int x_soldat,int y_soldat, int tab[20][16], int PM_restant); //Remplis le tableau tab,avec des 1, sur les cases sur lesquelles peut aller le joueur
int Deplacement(t_map carte, int zoneDeplacement[20][16], t_joueur* joueurActuel, BITMAP* buffer, BITMAP* soldat ); //Recupere dans la struct position, la position fde la souris lors du click, renvoie le nb de PM utilisés
int CalculChemin( t_map carte, int x1,int y1,int x2,int y2, int PM_restant,coords chemin[]);//Stock le chemin dans le tableau chemin si il est possible, sinon renvoie -1


/* ----------- INITIALISATION ----------- */

t_personnage init_classes(char* nom_classe,int num_classe,int p_action_max, int p_vie_max,int p_mvt_max,int nb_skin_total); //initialise les differentes classes
void init_map(t_map* carte); // Permet d'initaliser une map
void init_decor(t_decor* decor); // Initialise le decor

/* ----------- PRINCIPALE ----------- */

void menu_principal(void); // Lance le menu principale
void jouer(void); // Permet de jouer



#endif // HEADER_H_INCLUDED
