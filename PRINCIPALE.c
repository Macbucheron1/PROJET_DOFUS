#include "HEADER.h"

/* ------------------------------------- PRINCIPALE -------------------------------------
    Les fontions présente dans ce fichier sont les fonctions principales. C'est celle qui permettront de lancer
    toutes les fonctionnalitées principales du jeu
*/

void menu_principal(void) // A finir
{
    ///////////////////////////// INITALISATION VARIABLE /////////////////////////////////////

    BITMAP* fond_menu = create_bitmap(SCREEN_W,SCREEN_H);
    t_decor visuel_menu;
    init_decor(&visuel_menu);
    BITMAP* page = create_bitmap(SCREEN_W,SCREEN_H);
    FONT* arial_16 = load_font("arial_14.pcx", NULL, NULL);

    int couleur_quitter = makecol(0,255,255);
    int couleur_jouer = makecol(255,0,0);
    int couleur_apercu_classe = makecol(0,255,0);
    int couleur_parametre = makecol(0,0,255);
    int couleur_credit = makecol(255,255,0);
    int quitter = 0;


     ///////////////////////////// BOUCLE EVENEMENT /////////////////////////////////////

    while ((quitter!=1) && (!key[KEY_ESC]))
    {
        clear_bitmap(page);
        blit(visuel_menu.visuel, page, visuel_menu.position_x, 0, 0, 0, 800, 600);
        clear_to_color(fond_menu, makecol(0, 0, 0));

        ///////////////////////////// Dessin Bouton pour quitter /////////////////////////////////////
        
        rectfill(fond_menu, 10, 10, 30, 32, couleur_quitter);
        rectfill(page, 10, 10, 33, 34, makecol(190,190,190));
        rectfill(page, 12, 12, 31, 32, makecol(175,175,175));
        rectfill(page, 14, 14, 29, 30, makecol(160,160,160));
        textprintf_ex(page, arial_16, 17, 12, makecol(0,0,0), -1, "X");

        ///////////////////////////// Dessin Bouton du menu /////////////////////////////////////


        rectfill(fond_menu, 250, 150, 560, 210, couleur_jouer); // Jouer

        rectfill(fond_menu, 250, 250, 560, 310, couleur_apercu_classe); // Aperçu des classes

        rectfill(fond_menu, 250, 350, 560, 410, couleur_parametre); // Parametre

        rectfill(fond_menu, 250, 450, 560, 510, couleur_credit); // Credit

         ///////////////////////////// DESSIN MENU /////////////////////////////////////

        rectfill(page, 250, 150, 560, 210, makecol(190,190,190));
        rectfill(page, 253, 153, 557, 207, makecol(175,175,175));
        rectfill(page, 256, 156, 554, 204, makecol(160,160,160));
        textprintf_ex(page, font, 270, 170, makecol(0,0,0), -1, "Jouer"); // JOUER

        rectfill(page,  250, 250, 560, 310, makecol(190,190,190));
        rectfill(page, 253, 253, 557, 307, makecol(175,175,175));
        rectfill(page, 256, 256, 554, 304, makecol(160,160,160));
        textprintf_ex(page, font, 270, 270, makecol(0,0,0), -1, "Apercu des classes"); // APERCU DES CLASSES

        rectfill(page, 250, 350, 560, 410, makecol(190,190,190));
        rectfill(page, 253, 353, 557, 407, makecol(175,175,175));
        rectfill(page, 256, 356, 554, 404, makecol(160,160,160));
        textprintf_ex(page, font, 270, 370, makecol(0,0,0), -1, "Parametre"); // PARAMETRE

        rectfill(page, 250, 450, 560, 510, makecol(190,190,190));
        rectfill(page, 253, 453, 557, 507, makecol(175,175,175));
        rectfill(page, 256, 456, 554, 504, makecol(160,160,160));
        textprintf_ex(page, font, 270, 470, makecol(0,0,0), -1, "Credit"); // CREDIT


         ///////////////////////////// DETECTION BOUTON /////////////////////////////////////

        if (getpixel(fond_menu, mouse_x, mouse_y) == couleur_quitter) // QUITTER
        {
            rectfill(page, 10, 10, 33, 34, makecol(210,210,210));
            rectfill(page, 12, 12, 31, 32, makecol(195,195,195));
            rectfill(page, 14, 14, 29, 30, makecol(180,180,180));
            textprintf_ex(page, arial_16, 17, 12, makecol(0,0,0), -1, "X");
            if (mouse_b & 1)
            {
                quitter = 1; // Trouver un moyen de quitter autre
            }
        }

        if (getpixel(fond_menu, mouse_x, mouse_y) == couleur_jouer) // JOUER
        {
            rectfill(page, 250, 150, 560, 210, makecol(210,210,210));
            rectfill(page, 253, 153, 557, 207, makecol(195,195,195));
            rectfill(page, 256, 156, 554, 204, makecol(180,180,180));
            textprintf_ex(page, font, 270, 170, makecol(20,20, 20), -1, "Jouer");
            if (mouse_b & 1)
            {
                rest(100);
                quitter = jouer();
            }
        }

        if (getpixel(fond_menu, mouse_x, mouse_y) == couleur_apercu_classe) // APERCU DES CLASSES
        {
            rectfill(page,  250, 250, 560, 310, makecol(210,210,210));
            rectfill(page, 253, 253, 557, 307, makecol(195,195,175));
            rectfill(page, 256, 256, 554, 304, makecol(180,180,180));
            textprintf_ex(page, font, 270, 270, makecol(20,20,20), -1, "Apercu des classes");
            if (mouse_b & 1)
            {
                apercu_classe_en_cours(page, &visuel_menu);
            }
        }

        if (getpixel(fond_menu, mouse_x, mouse_y) == couleur_parametre) // PARAMETRE
        {
            rectfill(page, 250, 350, 560, 410, makecol(210,210,210));
            rectfill(page, 253, 353, 557, 407, makecol(195,195,175));
            rectfill(page, 256, 356, 554, 404, makecol(180,180,180));
            textprintf_ex(page, font, 270, 370, makecol(20,20,20), -1, "Parametre");
            if (mouse_b & 1)
            {
                parametre_en_cours(page, &visuel_menu);
            }
        }

        if (getpixel(fond_menu, mouse_x, mouse_y) == couleur_credit) // CREDIT
        {
            rectfill(page, 250, 450, 560, 510, makecol(210,210,210));
            rectfill(page, 253, 453, 557, 507, makecol(195,195,175));
            rectfill(page, 256, 456, 554, 504, makecol(180,180,180));
            textprintf_ex(page, font, 270, 470, makecol(20,20,20), -1, "Credit"); // CREDIT
            if (mouse_b & 1)
            {
                credit_en_cours(page, &visuel_menu);
            }
        }

        /////////////////////////////  /////////////////////////////////////





        ///////////////////////////// AVANCEMENT DU FOND /////////////////////////////////////



        if (visuel_menu.position_x >= 2399)
        {
            visuel_menu.position_x = 1;
        }
        visuel_menu.position_x = (visuel_menu.position_x + visuel_menu.avancement_x);
        rest(1);


        blit(page, screen, 0, 0, 0, 0, 800, 600);
    }
}

int jouer(void) // A finir
{
    // VARIABLE
    t_map carte;
    BITMAP* page;
    BITMAP* soldat;


    BITMAP* fond_menu = create_bitmap(SCREEN_W,SCREEN_H);

    int couleur_menu = makecol(0,255,255);
    int couleur_attaque_1 = makecol(255,0,0);
    int couleur_attaque_2 = makecol(0,255,0);
    int couleur_attaque_3 = makecol(0,0,255);
    int couleur_attaque_4 = makecol(255,255,0);
    int couleur_attaque_5 = makecol(255,255,255);

    clear_to_color(fond_menu, makecol(0, 0, 0));

    rectfill(fond_menu, 750,10,790,50,couleur_menu);
    rectfill(fond_menu,110,555,210,585,couleur_attaque_1);
    rectfill(fond_menu,238,555,338,585,couleur_attaque_2);
    rectfill(fond_menu,366,555,466,585,couleur_attaque_3);
    rectfill(fond_menu,494,555,594,585,couleur_attaque_4);
    rectfill(fond_menu,622,555,722,585,couleur_attaque_5);


    // INITIALISATION VARIABLE
    init_map(&carte);
    srand(time(NULL));
    page = create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(page);
    soldat = load_bitmap("Starwars-V1.bmp", 0);
    erreur_chargement_image(soldat);
    BITMAP *personnage=load_bitmap("personnage.bmp", NULL);
    erreur_chargement_image(personnage);
    int quitter = 0;
    int affiche_son = 0;
    int affiche_grille = 0;

    // CODE PRINCIPAL
    //////////////Pour tester le deplacement////////////////
    t_joueur joueurActuel;
    joueurActuel.position_colonne=13;
    joueurActuel.position_ligne=13;
    joueurActuel.classe.pm_actuel=6;
    /////////////////////////////////////////////////////////
    int positionTmpX=-1;    //Permet d'actualiser le chemin seulement si le joueur change de position
    int positionTmpY=-1;

    while (((quitter == 0) || (quitter == 3) )&&(!key[KEY_ESC]))
    {
        //int positionTmpX=-1;    //Permet d'actualiser le chemin seulement si le joueur change de position
        //int positionTmpY=-1;

        joueurActuel.classe.pm_actuel=6;    //joueurActuel.classe->pm_actuel=joueurActuel.classe->pm_max;

        //boucle tant que temps>0
        int  zoneDeplacement[20][16];

        blit(carte.fond_map,page,0,0, (SCREEN_W-carte.fond_map->w)/2, (SCREEN_H-carte.fond_map->h)/2, carte.fond_map->w, carte.fond_map->h);
        //affichage_grille(page);


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
        affichage_en_jeu(page);
        if (getpixel(fond_menu, mouse_x, mouse_y) == couleur_menu) // menu
        {

            if (mouse_b & 1)
            {
                quitter = menu_en_jeu(page, fond_menu, &affiche_son, &affiche_grille);
            }
        }
        /*
        if (getpixel(fond_menu, mouse_x, mouse_y) == couleur_menu) // attaque 1
        {
            if (mouse_b & 1)
            {
                rest(100);
            }
        }
        if (getpixel(fond_menu, mouse_x, mouse_y) == couleur_menu) // attaque 2
        {
            if (mouse_b & 1)
            {
                rest(100);
            }
        }
        if (getpixel(fond_menu, mouse_x, mouse_y) == couleur_menu) // attaque 3
        {
            if (mouse_b & 1)
            {
                rest(100);
            }
        }
        if (getpixel(fond_menu, mouse_x, mouse_y) == couleur_menu) // attaque 4
        {
            if (mouse_b & 1)
            {
                rest(100);
            }
        }
        if (getpixel(fond_menu, mouse_x, mouse_y) == couleur_menu) // attaque 5
        {
            if (mouse_b & 1)
            {
                rest(100);
            }
        }*/
        montre_curseur(page);
        blit(page, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        clear(page);
    }
    return quitter;
}

int menu_en_jeu(BITMAP* buffer, BITMAP* fond_menu, int* affiche_son, int* affiche_grille)
{
    rest(100);
    int couleur_menu = makecol(0,255,255);
    int couleur_retour_menu = makecol(196,196,196);
    int couleur_quitter = makecol(175,175,175);
    int couleur_son = makecol(100,100,100);
    int couleur_affichage = makecol(50,50,50);
    int i;
    int quitter = 0;
    FONT* arial_26 = load_font("arial_26.pcx", NULL, NULL);

    rectfill(fond_menu,303,173,512,237, couleur_retour_menu);
    rectfill(fond_menu, 303, 398, 512, 462, couleur_quitter);
    rectfill(fond_menu, 462, 255, 512, 305, couleur_son);
    rectfill(fond_menu, 462, 330, 512, 380, couleur_affichage);

    rectfill(buffer, 250, 50, 550, 500, makecol(200,200,200));
    rectfill(buffer, 754,14,786,46, makecol(160,160,160));
    line(buffer,754,14,786,46, makecol(96,96,96));
    line(buffer,786,14,754,46, makecol(96,96,96));

    textprintf_ex(buffer, arial_26, 360, 100, makecol(0,0,0), -1, "Menu");
    for(i = 0;i<3;i++)
    {
        rectfill(buffer, 303+4*i, 173+4*i, 512-4*i, 237-4*i, makecol(190-15*i,190-15*i,190-15*i));
        rectfill(buffer, 303+4*i, 398+4*i, 512-4*i, 462-4*i, makecol(190-15*i,190-15*i,190-15*i));
        rectfill(buffer, 462+4*i, 255+4*i, 512-4*i, 305-4*i, makecol(190-15*i,190-15*i,190-15*i));
        rectfill(buffer, 462+4*i, 330+4*i, 512-4*i, 380-4*i, makecol(190-15*i,190-15*i,190-15*i));
    }
    textprintf_ex(buffer, font, 313, 200, makecol(0,0,0), -1, "Retour au menu principal");
    textprintf_ex(buffer, font, 313, 275, makecol(0,0,0), -1, "Activer le son");
    textprintf_ex(buffer, font, 313, 350, makecol(0,0,0), -1, "Affichage grille");
    textprintf_ex(buffer, font, 350, 425, makecol(0,0,0), -1, "Quitter le jeu");

    BITMAP* fond_de_jeu = create_bitmap(800, 600);

    blit(buffer, fond_de_jeu, 0, 0, 0, 0, 800, 600);
    while((quitter == 0)&&(!key[KEY_ESC]))
    {
        blit(fond_de_jeu, buffer, 0, 0, 0, 0, 800, 600);
        if (*affiche_son == 1)
        {
            line(buffer,470,263,504,297, makecol(96,96,96));
            line(buffer,504,263,470,297, makecol(96,96,96));
        }
        if (*affiche_grille == 1)
        {
            line(buffer,470,338,504,372, makecol(96,96,96));
            line(buffer,504,338,470,372, makecol(96,96,96));
        }
        montre_curseur(buffer);
        if (getpixel(fond_menu, mouse_x, mouse_y) == couleur_menu) // menu
        {
            if (mouse_b & 1)
            {
                rest(100);
                return 3;
            }
        }
        if (getpixel(fond_menu, mouse_x, mouse_y) == couleur_retour_menu) // retour menu
        {
            if (mouse_b & 1)
            {
                rest(100);
                return 2;
            }
        }
        if (getpixel(fond_menu, mouse_x, mouse_y) == couleur_son) // son
        {
            if (mouse_b & 1)
            {
                if (*affiche_son == 0)
                    *affiche_son = 1;
                else
                    *affiche_son = 0;
                rest(100);
            }
        }
        if (getpixel(fond_menu, mouse_x, mouse_y) == couleur_affichage) // affichage grille
        {
            if (mouse_b & 1)
            {
                if (*affiche_grille == 0)
                    *affiche_grille = 1;
                else
                    *affiche_grille = 0;
                rest(100);
            }
        }
        if (getpixel(fond_menu, mouse_x, mouse_y) == couleur_quitter) // quitter
        {
            if (mouse_b & 1)
            {
                rest(100);
                quitter = 1;
            }
        }
        blit(buffer, screen, 0, 0, 0, 0, 800, 600);
    }
    return quitter;
}




void credit_en_cours(BITMAP* page, t_decor* visuel_menu)
{
    /* Lance les credits
    Prend en parametre la bitmap d'affichage et le decor
    Ne renvoie rien */

    /////////////////////////// VARIABLE //////////////////////////

    BITMAP* fond_credit = create_bitmap(SCREEN_W,SCREEN_H);
    FONT* arial_8 = load_font("arial_8.pcx", NULL, NULL);
    FONT* arial_10 = load_font("arial_10.pcx", NULL, NULL);
    FONT* arial_12 = load_font("arial_12.pcx", NULL, NULL);
    FONT* arial_14 = load_font("arial_14.pcx", NULL, NULL);
    FONT* arial_16 = load_font("arial_16.pcx", NULL, NULL);
    FONT* arial_18 = load_font("arial_18.pcx", NULL, NULL);
    FONT* arial_20 = load_font("arial_20.pcx", NULL, NULL);
    FONT* arial_22 = load_font("arial_22.pcx", NULL, NULL);
    FONT* arial_24 = load_font("arial_24.pcx", NULL, NULL);
    FONT* arial_26 = load_font("arial_26.pcx", NULL, NULL);
    FONT* arial_28 = load_font("arial_28.pcx", NULL, NULL);
    int police = 0;
    int vitesse = 25;
    int depart_texte = 400;
    int Stardelay = 10;

    t_star TabStar[LIMIT_STAR];          //Etoile dans le fond
        for (int j=0 ; j<LIMIT_STAR; j++) {
        TabStar[j].posY = 1000;
    }

    ////////////////////////// BOUCLE EVENEMENT //////////////////////////

    while (!key[KEY_ESC])
    {
        clear_bitmap(page);
        blit(visuel_menu->visuel, page, visuel_menu->position_x, 0, 0, 0, 800, 600);

        ////////////////////////// DESSIN MENU //////////////////////////

        rect(page, 80, 50, 150, 80, makecol(255, 0, 0));

        line(page, 80, 30, 40, 65, makecol(255, 0, 0));
        line(page, 80, 100, 40, 65, makecol(255, 0, 0));
        line(page, 80, 100, 80, 30, makecol(255, 0, 0));

        textout_ex(page, font, "Retour", 90, 60, makecol(255, 0, 0), -1);

        // Rajouter le texte des crédits
        rectfill(page, 150, 100, 675, 525, makecol(40,40,40));
        rectfill(page, 155, 105, 670, 520, makecol(20,20,20));
        rectfill(page, 160, 110, 665, 515, makecol(0,0,0));

        //police = affichage_credit(police, vitesse, depart_texte, page, arial_28, arial_26, arial_24, arial_22, arial_20, arial_18, arial_16, arial_14, arial_12, arial_10, arial_8);
        police = affichage_credit(police, vitesse, depart_texte, page, arial_28, arial_26, arial_24, arial_22, arial_20, arial_18, arial_16, arial_14, arial_12, arial_10, arial_8);

        Stardelay = Star(TabStar ,Stardelay,0,page); //Appel du sous-programme qui gère le fond


        montre_curseur(page);

        ////////////////////////// DESSIN BOUTON //////////////////////////

        clear_to_color(fond_credit, makecol(0, 0, 0));
        rectfill(fond_credit, 40, 30, 150, 100, makecol(255, 0, 0));

        ////////////////////////// DETECTION BOUTON //////////////////////////

        if (getpixel(fond_credit, mouse_x, mouse_y) == makecol(255, 0, 0))
        {
            if (mouse_b & 1)
            {
                return;
            }

        }


        ///////////////////////////// AVANCEMENT DU FOND /////////////////////////////////////

        if (visuel_menu->position_x >= 1599)
        {
            visuel_menu->avancement_x = -1;
        }
        else if (visuel_menu->position_x <=1)
        {
            visuel_menu->avancement_x = 1;
        }
        visuel_menu->position_x = (visuel_menu->position_x + visuel_menu->avancement_x);
        rest(1);


        blit(page, screen, 0, 0, 0, 0, 800, 600);
    }

}


void parametre_en_cours(BITMAP* page, t_decor* visuel_menu)
{
    /* Lance les credits
    Prend en parametre la bitmap d'affichage et le decor
    Ne renvoie rien */

    /////////////////////////// VARIABLE //////////////////////////

    BITMAP* fond_parametre = create_bitmap(SCREEN_W,SCREEN_H);
    int  mode_graphique = 1;

    ////////////////////////// BOUCLE EVENEMENT //////////////////////////

    while (!key[KEY_ESC])
    {
        clear_bitmap(page);
        blit(visuel_menu->visuel, page, visuel_menu->position_x, 0, 0, 0, 800, 600);

        ////////////////////////// DESSIN MENU //////////////////////////

        rect(page, 80, 50, 150, 80, makecol(255, 0, 0));

        line(page, 80, 30, 40, 65, makecol(255, 0, 0));
        line(page, 80, 100, 40, 65, makecol(255, 0, 0));
        line(page, 80, 100, 80, 30, makecol(255, 0, 0));

        rectfill(page, 200, 200, 300, 300, makecol(255, 255, 0));
        rectfill(page, 500, 200, 600, 300, makecol(255, 0, 225));

        textout_ex(page, font, "Retour", 90, 60, makecol(255, 0, 0), -1);
        textout_ex(page, font, "Pleine ecran", 205, 225, makecol(0, 0, 0), -1);
        textout_ex(page, font, "Fenetre", 525, 225, makecol(0, 0, 0), -1);



        montre_curseur(page);

        ////////////////////////// DESSIN BOUTON //////////////////////////

        clear_to_color(fond_parametre, makecol(0, 0, 0));
        rectfill(fond_parametre, 40, 30, 150, 100, makecol(255, 0, 0));

        rectfill(fond_parametre, 200, 200, 300, 300, makecol(255, 255, 0));
        rectfill(fond_parametre, 500, 200, 600, 300, makecol(255, 0, 255));

        ////////////////////////// DETECTION BOUTON //////////////////////////

        if (getpixel(fond_parametre, mouse_x, mouse_y) == makecol(255, 0, 0))
        {
            if (mouse_b & 1)
            {
                return;
            }

        }

        if (getpixel(fond_parametre, mouse_x, mouse_y) == makecol(255, 255, 0))
        {
            if ((mouse_b & 1) && (mode_graphique == 1))
            {
                //changement_graphique(0);
                allegro_message("Fonctionnalite indisponible");
                mode_graphique = 0;
            }

        }

        if (getpixel(fond_parametre, mouse_x, mouse_y) == makecol(255, 0, 255))
        {
            if (mouse_b & 1)
            {
                changement_graphique(1);
            }

        }



        ///////////////////////////// AVANCEMENT DU FOND /////////////////////////////////////

        if (visuel_menu->position_x >= 1599)
        {
            visuel_menu->avancement_x = -1;
        }
        else if (visuel_menu->position_x <=1)
        {
            visuel_menu->avancement_x = 1;
        }
        visuel_menu->position_x = (visuel_menu->position_x + visuel_menu->avancement_x);
        rest(1);


        blit(page, screen, 0, 0, 0, 0, 800, 600);
    }
}


void apercu_classe_en_cours(BITMAP* page, t_decor* visuel_menu)
{
    /* Lance les credits
    Prend en parametre la bitmap d'affichage et le decor
    Ne renvoie rien */

    /////////////////////////// VARIABLE //////////////////////////

    BITMAP* fond_apercu_classe = create_bitmap(SCREEN_W,SCREEN_H);
    BITMAP* soldat = load_bitmap("Starwars-V1.bmp", NULL);
    erreur_chargement_image(soldat);
    int position_x_bitmap_soldat = 32;
    int nouvelle_affichage = 0;
    int direction_soldat = 0;

    ////////////////////////// BOUCLE EVENEMENT //////////////////////////

    while (!key[KEY_ESC])
    {
        clear_bitmap(page);
        blit(visuel_menu->visuel, page, visuel_menu->position_x, 0, 0, 0, 800, 600);

        ////////////////////////// DESSIN MENU //////////////////////////

        rect(page, 80, 50, 150, 80, makecol(255, 0, 0));

        line(page, 80, 30, 40, 65, makecol(255, 0, 0));
        line(page, 80, 100, 40, 65, makecol(255, 0, 0));
        line(page, 80, 100, 80, 30, makecol(255, 0, 0));

        rectfill(page, 110 - 3, 100 - 3, 210 + 3, 200 + 3, makecol(40, 40, 40));
        rectfill(page, 110, 100, 210, 200, makecol(20, 20, 20));
        rectfill(page, 110 + 3, 100 + 3, 210 - 3, 200 - 3, makecol(0, 0, 0));

        rectfill(page, 110 - 3, 350 - 3, 210 + 3, 450 + 3, makecol(40, 40, 40));
        rectfill(page, 110, 350, 210, 450, makecol(20, 20, 20));
        rectfill(page, 110 + 3, 350 + 3, 210 - 3, 450 - 3, makecol(0, 0, 0));

        rectfill(page, 510 - 3, 100 - 3, 610 + 3, 200 + 3, makecol(40, 40, 40));
        rectfill(page, 510, 100, 610, 200, makecol(20, 20, 20));
        rectfill(page, 510 + 3, 100 + 3, 610 - 3, 200 - 3, makecol(0, 0, 0));

        rectfill(page, 510 - 3, 350 - 3, 610 + 3, 450 + 3, makecol(40, 40, 40));
        rectfill(page, 510, 350, 610, 450, makecol(20, 20, 20));
        rectfill(page, 510 + 3, 350 + 3, 610 - 3, 450 - 3, makecol(0, 0, 0));

        textout_ex(page, font, "Retour", 90, 60, makecol(255, 0, 0), -1);




        // Afficher les classes

        montre_curseur(page);

        ////////////////////////// DESSIN BOUTON //////////////////////////

        clear_to_color(fond_apercu_classe, makecol(0, 0, 0));
        rectfill(fond_apercu_classe, 40, 30, 150, 100, makecol(255, 0, 0));

        ////////////////////////// DETECTION BOUTON //////////////////////////

        if (getpixel(fond_apercu_classe, mouse_x, mouse_y) == makecol(255, 0, 0))
        {
            if (mouse_b & 1)
            {
                return;
            }

        }



        ///////////////////////////// AVANCEMENT DU FOND /////////////////////////////////////

        if (visuel_menu->position_x >= 1599)
        {
            visuel_menu->avancement_x = -1;
        }
        else if (visuel_menu->position_x <=1)
        {
            visuel_menu->avancement_x = 1;
        }
        visuel_menu->position_x = (visuel_menu->position_x + visuel_menu->avancement_x);
        rest(1);


        ///////////////////////////// AVANCEMENT DU FOND /////////////////////////////////////

        nouvelle_affichage++;
        if (nouvelle_affichage%10 == 0)
        {
            position_x_bitmap_soldat = position_x_bitmap_soldat + 96;
        }
        if (position_x_bitmap_soldat>=340)
        {
            position_x_bitmap_soldat = 32;
        }
        if (nouvelle_affichage >= 80)
        {
            direction_soldat++;
            nouvelle_affichage = 0;
        }
        if (direction_soldat >= 4)
        {
            direction_soldat = 0;
        }
        else if (direction_soldat == 0)
        {
            masked_blit(soldat,page, position_x_bitmap_soldat, 207, 150,150-30, 32,64);
        }
        else if (direction_soldat == 1)
        {
            masked_blit(soldat,page, position_x_bitmap_soldat, 14, 150,150-30, 32,64);
        }
        else if (direction_soldat == 2)
        {
            masked_blit(soldat,page, position_x_bitmap_soldat, 300, 150,150-30, 32,64);
        }
        else if (direction_soldat == 3)
        {
           masked_blit(soldat,page, position_x_bitmap_soldat, 108, 150,150-30, 32,64);
        }

        blit(page, screen, 0, 0, 0, 0, 800, 600);
    }
}





























