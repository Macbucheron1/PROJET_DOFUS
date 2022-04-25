#include "HEADER.h"

int main()
{
    // VARIABLE
    t_map carte;
    int changement_mode_graphique;

    // INITIALISATION ALLEGRO
    prepa_alleg();

    // INITIALISATION VARIABLE
    init_map(&carte);
    srand(time(NULL));
    changement_mode_graphique = 0;

    // CODE PRINCIPAL
    while (!key[KEY_ESC])
    {
        blit(carte.fond_map,screen,0,0, (SCREEN_W-carte.fond_map->w)/2, (SCREEN_H-carte.fond_map->h)/2, carte.fond_map->w, carte.fond_map->h);

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
