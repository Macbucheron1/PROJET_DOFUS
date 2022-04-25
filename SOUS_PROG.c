#include "HEADER.h"

void init_map(t_map* carte)
{
    /* Permet d'initialiser une map
    Prend en parametre la carte qu'on doit remplir
    Ne renvoie rien*/
    carte->fond_map = load_bitmap("fond_jeu.bmp",NULL);
    erreur_chargement_image(carte->fond_map);
}

