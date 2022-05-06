#include "HEADER.h"

/* ------------------------------------- PRINCIPALE -------------------------------------
    Les fontions pr�sente dans ce fichier sont les fonctions principales. C'est celle qui permettront de lancer
    toutes les fonctionnalit�es principales du jeu
*/

void menu_principal(void) // A finir
{
    BITMAP* fond_menu = create_bitmap(SCREEN_W,SCREEN_H);
    t_decor visuel_menu;
    init_decor(&visuel_menu);
    BITMAP* page = create_bitmap(SCREEN_W,SCREEN_H);

    int couleur_quitter = makecol(0,255,255);
    int couleur_jouer = makecol(255,0,0);
    int couleur_apercu_classe = makecol(0,255,0);
    int couleur_parametre = makecol(0,0,255);
    int couleur_credit = makecol(255,255,0);

    while (!key[KEY_ESC])
    {
        clear_bitmap(page);
        blit(visuel_menu.visuel, page, visuel_menu.position_x, 0, 0, 0, 800, 600);
        clear_to_color(fond_menu, makecol(0, 0, 0));

        // Bouton pour quitter

        rectfill(fond_menu, 10, 10, 30, 30, couleur_quitter);
        rect(page, 10, 10, 30, 30, couleur_quitter);
        textprintf_ex(page, font, 15, 15, makecol(255,255, 255), -1, "II");

        // Bouton du menu


        rectfill(fond_menu, 250, 150, 560, 210, couleur_jouer); // Jouer
        rect(page, 250, 150, 560, 210, couleur_jouer);
        textprintf_ex(page, font, 270, 170, makecol(255,255, 255), -1, "Jouer");

        rectfill(fond_menu, 250, 250, 560, 310, couleur_apercu_classe); // Aper�u des classes
        rect(page,  250, 250, 560, 310, couleur_apercu_classe);
        textprintf_ex(page, font, 270, 270, makecol(255,255, 255), -1, "Apercu des classes");

        rectfill(fond_menu, 250, 350, 560, 410, couleur_parametre); // Parametre
        rect(page, 250, 350, 560, 410, couleur_parametre);
        textprintf_ex(page, font, 270, 370, makecol(255,255, 255), -1, "Parametre");

        rectfill(fond_menu, 250, 450, 560, 510, couleur_credit); // Credit
        rect(page, 250, 450, 560, 510, couleur_credit);
        textprintf_ex(page, font, 270, 470, makecol(255,255, 255), -1, "Credit");

        montre_curseur(page);

        // Detection Boite
        if (getpixel(fond_menu, mouse_x, mouse_y) == couleur_quitter)
        {
            if (mouse_b & 1)
            {
                return;
            }
        }
        if (getpixel(fond_menu, mouse_x, mouse_y) == couleur_jouer)
        {
            textprintf_ex(page, font, 100, 100, makecol(255,255, 255), -1, "Jouer");
            if (mouse_b & 1)
            {
                rest(100);
                jouer();
            }
        }
        if (getpixel(fond_menu, mouse_x, mouse_y) == couleur_apercu_classe)
        {
            textprintf_ex(page, font, 100, 100, makecol(255,255, 255), -1, "Apercu des classes");
        }
        if (getpixel(fond_menu, mouse_x, mouse_y) == couleur_parametre)
        {
            textprintf_ex(page, font, 100, 100, makecol(255,255, 255), -1, "Parametre");
        }
        if (getpixel(fond_menu, mouse_x, mouse_y) == couleur_credit)
        {
            textprintf_ex(page, font, 100, 100, makecol(255,255, 255), -1, "Credit");
        }


        blit(page, screen, 0, 0, 0, 0, 800, 600);

        if (visuel_menu.position_x >= 1599)
        {
            visuel_menu.avancement_x = -1;
        }
        else if (visuel_menu.position_x <=1)
        {
            visuel_menu.avancement_x = 1;
        }
        visuel_menu.position_x = (visuel_menu.position_x + visuel_menu.avancement_x);
        rest(1);
    }
}

void jouer(void) // A finir
{
    // VARIABLE
    t_map carte;
    BITMAP* page;
    BITMAP* soldat;


    // INITIALISATION VARIABLE
    init_map(&carte);
    srand(time(NULL));
    page = create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(page);
    soldat = load_bitmap("Starwars-V1.bmp", 0);
    erreur_chargement_image(soldat);
    BITMAP *personnage=load_bitmap("personnage.bmp", NULL);
    erreur_chargement_image(personnage);

    // CODE PRINCIPAL
    //////////////Pour tester le deplacement////////////////
    t_joueur joueurActuel;
    joueurActuel.position_colonne=13;
    joueurActuel.position_ligne=13;
    joueurActuel.classe.pm_actuel=6;
    /////////////////////////////////////////////////////////
    int positionTmpX=-1;    //Permet d'actualiser le chemin seulement si le joueur change de position
    int positionTmpY=-1;

    while (!key[KEY_ESC])
    {
        //int positionTmpX=-1;    //Permet d'actualiser le chemin seulement si le joueur change de position
        //int positionTmpY=-1;

        joueurActuel.classe.pm_actuel=6;    //joueurActuel.classe->pm_actuel=joueurActuel.classe->pm_max;

        //boucle tant que temps>0
        int  zoneDeplacement[20][16];

        blit(carte.fond_map,page,0,0, (SCREEN_W-carte.fond_map->w)/2, (SCREEN_H-carte.fond_map->h)/2, carte.fond_map->w, carte.fond_map->h);
        affichage_grille(page);


        ////////////////////////////////////DEPLACEMENT/////////////////////////////
        if(joueurActuel.classe.pm_actuel>0){
            if(joueurActuel.position_colonne!=positionTmpX || joueurActuel.position_ligne!=positionTmpY){   //Permet d'actualiser le chemin seulement si le joueur change de position
                CalculDeplacement(page,carte, joueurActuel.position_colonne,joueurActuel.position_ligne,zoneDeplacement, joueurActuel.classe.pm_actuel);
                positionTmpX=joueurActuel.position_colonne;
                positionTmpY=joueurActuel.position_ligne;
            }
            SurbrillanceDeplacement(page,carte,zoneDeplacement);
            joueurActuel.classe.pm_actuel-=Deplacement(carte, zoneDeplacement, &joueurActuel, page, soldat);
        }
        masked_blit(soldat,page, 409, 14, carte.tab_coordonnes[joueurActuel.position_colonne][joueurActuel.position_ligne].position_pixel_x, carte.tab_coordonnes[joueurActuel.position_colonne][joueurActuel.position_ligne].position_pixel_y-30, 32,64);
        ////////////////////////////////////////////////////////////////////////////
        montre_curseur(page);
        blit(page, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        clear(page);
    }
    free(page);
}
