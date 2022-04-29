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
    //////////////Pour tester le deplacement////////////////
    t_joueur joueurActuel;
    joueurActuel.position_colonne=9;
    joueurActuel.position_ligne=8;
    joueurActuel.classe.pm_actuel=3;
    /////////////////////////////////////////////////////////

    while (!key[KEY_ESC])
    {
        //joueurActuel.classe->pm_actuel=joueurActuel.classe->pm_max;
        //boucle tant que temps>0
        int  zoneDeplacement[20][16];

        blit(carte.fond_map,buffer1,0,0, (SCREEN_W-carte.fond_map->w)/2, (SCREEN_H-carte.fond_map->h)/2, carte.fond_map->w, carte.fond_map->h);
        affichage_grille(buffer1);
        show_mouse(buffer1);

        ////////////////////////////////////DEPLACEMENT/////////////////////////////
        if(joueurActuel.classe.pm_actuel>0){
            CalculDeplacement(buffer1,carte, joueurActuel.position_colonne,joueurActuel.position_ligne,zoneDeplacement, joueurActuel.classe.pm_actuel);
            joueurActuel.classe.pm_actuel-=Deplacement(carte, zoneDeplacement, &joueurActuel);
            //AnimationDeplacement(joueurActuel.position_colonne, joueurActuel.position_ligne=position.y, position.x, position.y);
        }
        affichagePerso(buffer1,soldat,carte,joueurActuel.position_colonne,joueurActuel.position_ligne);
        ////////////////////////////////////////////////////////////////////////////


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

        blit(buffer1, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        clear(buffer1);
    }

    return 0;
} END_OF_MAIN() ;
