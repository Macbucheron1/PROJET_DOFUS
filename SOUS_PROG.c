#include "HEADER.h"

void init_map(t_map* carte)
{
    /* Permet d'initialiser une map
    Prend en parametre la carte qu'on doit remplir
    Ne renvoie rien*/
    carte->fond_map = load_bitmap("fond_jeu.bmp",NULL);
    erreur_chargement_image(carte->fond_map);
    remplir_tab_coordonnes(carte);
    remplir_map_obstacle(carte);
}

void remplir_tab_coordonnes(t_map* carte)
{
    /* Permet de remplir le tableau de coordonnées de la map
    Prend en parametre un pointeur sur la map
    Ne renvoie rien*/
    int x = 96;
    int y = 32;
    for (int colonne = 0; colonne < COLONNE_TABLEAU; colonne++)
    {
        for (int ligne = 0; ligne < LIGNE_TABLEAU; ligne++)
        {
            carte->tab_coordonnes[colonne][ligne].position_pixel_x = x + 32 * colonne;
            carte->tab_coordonnes[colonne][ligne].position_pixel_y = y + 32 * ligne;
        }
    }
}


void remplir_map_obstacle(t_map* carte)
{
    /* Permet de remplir la matrice contenant la valeur de chaque case. Avec chaque numero represantant soit un obstacle soit un element de decor
    Prend en parametre un pointeur sur une map
    Ne renvoie rien*/
    int terrain [COLONNE_TABLEAU][LIGNE_TABLEAU] = {
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
    // On créée cette variable temporaire afin de pouvoir modifier facilement le tableau

    for (int colonne = 0; colonne < COLONNE_TABLEAU; colonne++)
    {
        for (int ligne = 0; ligne < LIGNE_TABLEAU; ligne++)
        {
            carte->map_obstacle[colonne][ligne] = terrain[colonne][ligne];
        }
    }
}


int position_souris_colonne(void)
{
/* Permet de savoir dans quelle colonne se situe la souris
    Ne prend pas de parametre
    Renvoie la colonne dans laquelle la souris se situe. -1 si la souris n'est pas dans une colonne*/
    int debut_tableau_x = 96;
    for (int colonne = 0; colonne < COLONNE_TABLEAU; colonne++)
    {
        if ((mouse_x >= debut_tableau_x + 32 * colonne) && (mouse_x <= debut_tableau_x + 32 * (colonne+1)))
        {
            return colonne;
        }
    }
    return -1;
}


int position_souris_ligne(void)
{
/* Permet de savoir dans quelle ligne se situe la souris
    Ne prend pas de parametre
    Renvoie la ligne dans laquelle la souris se situe. -1 si la souris n'est pas dans une ligne*/
    int debut_tab_y = 32;
    for (int ligne = 0; ligne < LIGNE_TABLEAU; ligne++)
    {
        if ((mouse_y >= debut_tab_y + 32 * ligne) && (mouse_y <= debut_tab_y + 32 * (ligne+1)))
        {
            return ligne;
        }
    }
    return -1;
}

