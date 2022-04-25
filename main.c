#include "HEADER.h"

int main()
{
    // VARIABLE
    t_map carte;
    int changement_mode_graphique;
    BITMAP* buffer1;
    BITMAP* soldat;

    // INITIALISATION ALLEGRO
    prepa_alleg();

    // INITIALISATION VARIABLE
    init_map(&carte);
    srand(time(NULL));
    changement_mode_graphique = 0;
    buffer1 = create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(buffer1);
    soldat = load_bitmap("soldat.bmp", 0);
    erreur_chargement_image(soldat);

    // CODE PRINCIPAL


    while (!key[KEY_ESC])
    {
        blit(carte.fond_map,buffer1,0,0, (SCREEN_W-carte.fond_map->w)/2, (SCREEN_H-carte.fond_map->h)/2, carte.fond_map->w, carte.fond_map->h);
        for (int x = 100; x <= 700; x = x + 30)
        {
            line(buffer1, x, 60, x, 540, makecol(255, 0, 0));
        }
        for (int y = 60; y <= 540; y = y + 30)
        {
            line(buffer1, 100, y, 700, y, makecol(255, 0, 0));
        }
        draw_sprite(buffer1,soldat, 145, 192);
        blit(buffer1, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

        if (key[KEY_SPACE])
        {
            if (changement_mode_graphique == 0)
            {
                changement_graphique(changement_mode_graphique);
                changement_mode_graphique = 1;
            }
            else
            {
                changement_graphique(changement_mode_graphique);
                changement_mode_graphique = 0;
            }
        }


    }

    return 0;
} END_OF_MAIN() ;
