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
    /*V�rification que l'image est bien charg�e (dans le cas contraire image vaut NULL)
    TOUJOURS LE FAIRE CAR ON N'EST JAMAIS CERTAIN DE BIEN TROUVER L'IMAGE
    Prend en parametre l'image a test�
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
