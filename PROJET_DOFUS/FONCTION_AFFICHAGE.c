#include "HEADER.h"

void prepa_alleg(void)
{
    /* Lance alleg init et verifie qu'il fonctionne bien
    Ne prend de parametre
    Ne renvoie rien */
    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}

void erreur_chargement_image(BITMAP* image)
{
    /*Vérification que l'image est bien chargée (dans le cas contraire image vaut NULL)
    TOUJOURS LE FAIRE CAR ON N'EST JAMAIS CERTAIN DE BIEN TROUVER L'IMAGE
    Prend en parametre l'image a testé
    Ne renvoie rien */
    if (!image)
    {
        allegro_message("pas pu trouver/charger mon_image.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}

void changement_graphique(int valeur)
{
/* Permet de changer de mode graphique
   0 pour mettre en pleine ecran et 1 pour mettre en fenetre*/
    if (valeur == 0)
    {
        if (set_gfx_mode(GFX_AUTODETECT_FULLSCREEN,800,600,0,0)!=0)
        {
            allegro_message("prb gfx mode");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
        }
        else
        {
            if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
            {
                allegro_message("prb gfx mode");
                allegro_exit();
                exit(EXIT_FAILURE);
            }
        }
}

void affichage_grille(BITMAP* buffer)
{
    /* Permet d'afficher la grille sur la carte
    Prend en parametre le buffer
    Ne renvoie rien*/

    for (int x = 96; x <= 736; x = x + 32)
    {
        line(buffer, x, 32, x, 544, makecol(255, 0, 0));
    }
    for (int y = 32; y <= 544; y = y + 32)
    {
        line(buffer, 96, y, 736, y, makecol(255, 0, 0));
    }
}

void affichagePerso(BITMAP* buffer, BITMAP* soldat, t_map carte,int x,int y)
{
    draw_sprite(buffer, soldat, carte.tab_coordonnes[x][y].position_pixel_x, carte.tab_coordonnes[x][y].position_pixel_y-40);
}


//Affiche les zones sur lesqeuelles peut aller le perso en vert
void SurbrillanceDeplacement(BITMAP* buffer,t_map carte, int tab[20][16])
{
    for(int i=0; i<20;i++)
    {

        for(int j=0;j<16;j++)
        {
            if(tab[i][j]==1)
            {
                rectfill(buffer,carte.tab_coordonnes[i][j].position_pixel_x+5, carte.tab_coordonnes[i][j].position_pixel_y+5, carte.tab_coordonnes[i][j].position_pixel_x +32-5,carte.tab_coordonnes[i][j].position_pixel_y+32-5, makecol(0,255,0));
            }
        }
    }
    afficheSouris(buffer,carte,tab);
}

//Affiche un carré bleu a la position de la souris (si la souris se trouve dans la zone de deplacement)
void afficheSouris(BITMAP* buffer,t_map carte, int tab[20][16])
{
    int i=0,j=0;
    if(position_souris_colonne()!=-1 && position_souris_ligne()!=-1)
    {
        i= position_souris_colonne();
        j= position_souris_ligne();
        if(tab[i][j]==1)
            rectfill(buffer,carte.tab_coordonnes[i][j].position_pixel_x+5, carte.tab_coordonnes[i][j].position_pixel_y+5, carte.tab_coordonnes[i][j].position_pixel_x +32-5,carte.tab_coordonnes[i][j].position_pixel_y+32-5, makecol(0,0,255));
    }

}



