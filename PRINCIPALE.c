#include "HEADER.h"

/* ------------------------------------- PRINCIPALE -------------------------------------
    Les fontions présente dans ce fichier sont les fonctions principales. C'est celle qui permettront de lancer
    toutes les fonctionnalitées principales du jeu
*/

void menu_principal(void) // A finir
{
    ///////////////////////////// INITALISATION VARIABLE /////////////////////////////////////
    BITMAP* fond_menu = create_bitmap(SCREEN_W,SCREEN_H);
    BITMAP* page = create_bitmap(SCREEN_W,SCREEN_H);
    FONT* arial_16 = load_font("arial_14.pcx", NULL, NULL);
    SAMPLE* musique = load_wav("imperial_march.wav");
    BITMAP* soldat = load_bitmap("Starwars-V1.bmp", NULL);
    erreur_chargement_image(soldat);
    t_decor visuel_menu;
    BITMAP* tab_bitmap[4];
    tab_bitmap[0] = load_bitmap("map_desert.bmp", NULL);
    erreur_chargement_image(tab_bitmap[0]);
    tab_bitmap[1] = load_bitmap("map_neige.bmp", NULL);
    erreur_chargement_image(tab_bitmap[1]);
    tab_bitmap[2] = load_bitmap("map_ville.bmp", NULL);
    erreur_chargement_image(tab_bitmap[2]);
    visuel_menu.visuel =  create_bitmap(3200, SCREEN_H);
    blit(tab_bitmap[2], visuel_menu.visuel, 0, 0, 2400, 0, 800, 600);
    blit(tab_bitmap[0], visuel_menu.visuel, 0, 0, 1600, 0, 800, 600);
    blit(tab_bitmap[1], visuel_menu.visuel, 0, 0, 800, 0, 800, 600);
    blit(tab_bitmap[2], visuel_menu.visuel, 0, 0, 0, 0, 800, 600);
    visuel_menu.avancement_x = 1;
    visuel_menu.avancement_y = 1;
    visuel_menu.position_x = 0;
    visuel_menu.position_y = 0;
    t_acteur jedi1;
    init_acteur(&jedi1, 800, 160, soldat, 8, 8, 32, 108, 96, 94);
    t_acteur mesActeurs[10];
    mesActeurs[0] = jedi1;
    if (!musique)   //blindage
    {
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    int quitter = 0;
    int couleur_quitter = makecol(0,255,255);
    int couleur_jouer = makecol(255,0,0);
    int couleur_apercu_classe = makecol(0,255,0);
    int couleur_parametre = makecol(0,0,255);
    int couleur_credit = makecol(255,255,0);
    int delay=0;
    int volume=200;
    unsigned int temps=0;
    play_sample(musique,volume,128,1000,1);

    // initialisation des classes

    t_personnage mage;
    mage=init_classes("mage",1,6,2000,4);

    t_personnage archer;
    archer=init_classes("archer",2,6,1700,4);

    t_personnage guerrier;
    guerrier=init_classes("guerrier",3,6,2500,3);

    t_personnage tank;
    tank=init_classes("tank",4,6,4800,2);

    ///////////////////////////// BOUCLE EVENEMENT /////////////////////////////////////
    BITMAP* curseur = load_bitmap("curseur.bmp", NULL);
    erreur_chargement_image(curseur);
    while ((quitter != 1) && (!key[KEY_ESC]))
    {
        clear_bitmap(page);
        animation_decor_menu(soldat, mesActeurs, &delay, &visuel_menu, tab_bitmap, &temps);
        blit(visuel_menu.visuel, visuel_menu.visuel, 0, 0, 2400, 0, 800, 600);
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
                quitter = 1;
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
                quitter=nouvellePartie(page, musique, &volume, mage, archer, guerrier, tank, &visuel_menu, soldat, &delay, mesActeurs, tab_bitmap, &temps);
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
                apercu_classe_en_cours(page, &visuel_menu, soldat, &delay, mesActeurs, tab_bitmap, &temps, mage, archer, guerrier,tank);
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
                parametre_en_cours(page, &visuel_menu, musique, &volume, soldat, mesActeurs, &delay, tab_bitmap, &temps);
            }
        }
        if (getpixel(fond_menu, mouse_x, mouse_y) == couleur_credit) // CREDIT
        {
            rectfill(page, 250, 450, 560, 510, makecol(210,210,210));
            rectfill(page, 253, 453, 557, 507, makecol(195,195,175));
            rectfill(page, 256, 456, 554, 504, makecol(180,180,180));
            textprintf_ex(page, font, 270, 470, makecol(20,20,20), -1, "Credit");
            if (mouse_b & 1)
            {
                credit_en_cours(page, &visuel_menu, soldat, mesActeurs, &delay, &temps, tab_bitmap);
            }
        }
        montre_curseur(page,curseur);
        /////////////////////////////  /////////////////////////////////////





        ///////////////////////////// AVANCEMENT DU FOND /////////////////////////////////////
        rest(1);

        blit(page, screen, 0, 0, 0, 0, 800, 600);
    }
    destroy_sample(musique);
}

int jouer(t_joueur Joueurs[], int nbJoueurs, SAMPLE* musique, int* volume) // A finir
{
    // VARIABLE
    t_map carte;
    BITMAP* page;
    BITMAP* soldat;

    BITMAP* fond_menu = create_bitmap(SCREEN_W,SCREEN_H);

    BITMAP* avatar[4];
    avatar[0] = load_bitmap("avatar.bmp", NULL);
    erreur_chargement_image(avatar[0]);

    avatar[1] = load_bitmap("avatar2.bmp", NULL);
    erreur_chargement_image(avatar[1]);

    avatar[2] = load_bitmap("avatar3.bmp", NULL);
    erreur_chargement_image(avatar[2]);

    avatar[3] = load_bitmap("avatar4.bmp", NULL);
    erreur_chargement_image(avatar[3]);

    int couleur_menu = makecol(0,255,255);
    int couleur_attaque_1 = makecol(255,0,0);
    int couleur_attaque_2 = makecol(0,255,0);
    int couleur_attaque_3 = makecol(0,0,255);
    int couleur_attaque_4 = makecol(255,255,0);
    int couleur_attaque_5 = makecol(255,255,255);
    int couleur_fin_tour = makecol(150, 0, 0);
    int couleur_fin_attaque = makecol(136,136,136);

    clear_to_color(fond_menu, makecol(0, 0, 0));

    rectfill(fond_menu, 750,10,790,50,couleur_menu);
    rectfill(fond_menu, 100+78*0, 555, 150+78*0, 595, couleur_attaque_1);
    rectfill(fond_menu, 100+78*1, 555, 150+78*1, 595, couleur_attaque_2);
    rectfill(fond_menu, 256+128*0, 555, 356+128*0, 595, couleur_attaque_3);
    rectfill(fond_menu, 256+128*1, 555, 356+128*1, 595, couleur_attaque_4);
    rectfill(fond_menu, 256+128*2, 555, 356+128*2, 595, couleur_attaque_5);
    rectfill(fond_menu, 256+128*3, 555, 356+128*3, 595, couleur_fin_tour);
    rectfill(fond_menu, 22,555,72,595,couleur_fin_attaque);

    // INITIALISATION VARIABLE
    init_map(&carte);
    srand(time(NULL));
    page = create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(page);
    soldat = load_bitmap("Starwars-V1.bmp", 0);
    erreur_chargement_image(soldat);
    BITMAP* perso1 = load_bitmap("nv_perso1.bmp", NULL);
    erreur_chargement_image(perso1);
    BITMAP *personnage=load_bitmap("personnage.bmp", NULL);
    erreur_chargement_image(personnage);
    int quitter = 0;
    int affiche_son = 1;
    int affiche_grille = 1;
    int quelle_attaque = 0;


    ///pour les attaques
    BITMAP* animation_attaque; //pas initialiser car pas encore d'animation pr les attaques
    int attaqueActive=0;


    // CODE PRINCIPAL

    BITMAP* curseur = load_bitmap("curseur.bmp", NULL);
    erreur_chargement_image(curseur);

    int indiceActuel= rand()%nbJoueurs;    //indice du joueur actuel choisi aleatoirement
    time_t temps1;
    time_t temps2;

    for(int i=0; i<nbJoueurs; i++)
    {
        do
        {
            Joueurs[i].position_colonne=rand()%20;                      //On donne une position aléatoire à chaque joueur
            Joueurs[i].position_ligne=rand()%16;
        }
        while(caseDisponible2(carte, Joueurs[i].position_colonne, Joueurs[i].position_ligne, Joueurs,nbJoueurs,i)==0);  //Tant que la case est indisponible
    }


    while (((quitter != 1) && (quitter != 3)) || (!key[KEY_ESC]))
    {
        if(Joueurs[indiceActuel].pv_actuel<=0)
        {
            Joueurs[indiceActuel].elimine=1;
        }


        int  positionTmpX=-1;    //Permet d'actualiser le chemin seulement si le joueur change de position
        int positionTmpY=-1;

        if(Joueurs[indiceActuel].classe.numero_classe==1) //gestion de la meditation du mage
        {
            Joueurs[indiceActuel].pm_actuel=Joueurs[indiceActuel].pm_max_actu_mage;
        }
        else
        {
            Joueurs[indiceActuel].pm_actuel=Joueurs[indiceActuel].classe.pm_max;  //On remet le pm max au joueur à chaque tour
        }
        Joueurs[indiceActuel].pa_actuel=Joueurs[indiceActuel].classe.pa_max;

        temps1=clock();  //On stocke le temps en secondes dans temps1
        temps2=temps1+30000;
        time_t dureeStop=0;     ///permet de determiner combien de temps le timer a été stoppé (A mettre en place)
        time_t tmp=0;
        quelle_attaque=0;
        while(temps1<=temps2 && (Joueurs[indiceActuel].pm_actuel>0 || Joueurs[indiceActuel].pa_actuel>0))           //rajouter la condition si le joueurtuilise tous ses pm et pa
        {

            temps1=clock()-dureeStop;

            int  zoneDeplacement[20][16];
            AfficheTout(page, soldat, carte, nbJoueurs, Joueurs,fond_menu,avatar,temps1,temps2, affiche_son, affiche_grille, indiceActuel);

            ////////////////////////////////////DEPLACEMENT/////////////////////////////

            if(Joueurs[indiceActuel].pm_actuel>0 && attaqueActive==0)
            {
                if(Joueurs[indiceActuel].position_colonne!=positionTmpX || Joueurs[indiceActuel].position_ligne!=positionTmpY)    //Permet d'actualiser le chemin seulement si le joueur change de position
                {
                    CalculDeplacement(page,carte, Joueurs[indiceActuel].position_colonne,Joueurs[indiceActuel].position_ligne,zoneDeplacement, Joueurs[indiceActuel].pm_actuel, Joueurs, nbJoueurs,indiceActuel, affiche_son, affiche_grille);
                    positionTmpX=Joueurs[indiceActuel].position_colonne;
                    positionTmpY=Joueurs[indiceActuel].position_ligne;
                }
                SurbrillanceDeplacement(page,carte,zoneDeplacement);
                tmp=clock();
                Joueurs[indiceActuel].pm_actuel-=Deplacement(carte, zoneDeplacement, indiceActuel, page, perso1,nbJoueurs,Joueurs,fond_menu,avatar, temps1,temps2, affiche_son, affiche_grille);
                dureeStop+=clock()-tmp;
            }

            ////////////////////////////////////////////////////////////////////////////

            ////////////////////////////////////ATTAQUE/////////////////////////////////

            int zoneAttaque[20][16];

            if(quelle_attaque==0)
            {
                attaqueActive=0; //ne fait rien
            }
            else
            {
                attaqueActive=1;

                attaque(Joueurs,indiceActuel,page,carte,zoneAttaque,animation_attaque,nbJoueurs,&quelle_attaque);
                //printf("%d\n",quelle_attaque);
            }


            for(int i=0;i<nbJoueurs;i++)
                //printf("PV du jouer %d: %d\n",i,Joueurs[i].pv_actuel);

            if(mouse_b && getpixel(fond_menu,mouse_x,mouse_y)== couleur_fin_attaque){
                attaqueActive=0;
                quelle_attaque=0;
            }
            /*
            for (int j=0;j<nbJoueurs;j++)
            {
                printf("pv %d:%d\n",j,Joueurs[j].pv_actuel);
            }*/
            ////////////////////////////////////////////////////////////////////////////


            AffichePerso(page, perso1, carte, nbJoueurs, Joueurs,9999);
            //respiration a faire
            //affichage_en_jeu(page,fond_menu,avatar,avatar2,avatar3,avatar4);

            if (affiche_son == 1)
                adjust_sample(musique, *volume, 128, 1000, 1);
            else
                adjust_sample(musique, 0, 128, 1000, 1);

            if (mouse_b && getpixel(fond_menu, mouse_x, mouse_y) == couleur_menu) // menu
            {
                tmp=clock();
                quitter = menu_en_jeu(page, fond_menu, &affiche_son, &affiche_grille);
                if(quitter==1 || quitter==2)
                {
                    rest(100);
                    return quitter;
                }
                rest(200);
                dureeStop+=clock()-tmp;
            }
            else if (mouse_b && getpixel(fond_menu, mouse_x, mouse_y) == couleur_attaque_1) // Attaque 1
            {
                quelle_attaque = 1;
            }
            else if (mouse_b && getpixel(fond_menu, mouse_x, mouse_y) == couleur_attaque_2) // Attaque 2
            {
                quelle_attaque = 2;
            }
            else if (mouse_b && getpixel(fond_menu, mouse_x, mouse_y) == couleur_attaque_3) // Attaque 3
            {
                quelle_attaque = 3;
            }
            else if (mouse_b && getpixel(fond_menu, mouse_x, mouse_y) == couleur_attaque_4) // Attaque 4
            {
                quelle_attaque = 4;
            }
            else if (mouse_b && getpixel(fond_menu, mouse_x, mouse_y) == couleur_attaque_5) // Attaque 5
            {
                quelle_attaque = 5;
            }
            else if (mouse_b && getpixel(fond_menu, mouse_x, mouse_y) == couleur_fin_tour) // Fin de tour
            {
                textout_ex(page, font, "Fin de tour", 100, 100, makecol(255, 255, 255), -1);
                rest(100);
                break;
            }

            //textprintf_ex(page, font, 10, 250, makecol(0, 0, 0), -1, "PV : %d/%d", Joueurs[indiceActuel].pv_actuel, Joueurs[indiceActuel].classe.pv_max);
           // textprintf_ex(page, font, 10, 275, makecol(0, 0, 0), -1, "PM : %d/%d", Joueurs[indiceActuel].pm_actuel, Joueurs[indiceActuel].classe.pm_max);
            //textprintf_ex(page, font, 10, 300, makecol(0, 0, 0), -1, "PA : %d/%d", Joueurs[indiceActuel].pa_actuel, Joueurs[indiceActuel].classe.pa_max);
            montre_curseur(page,curseur);
            blit(page, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            clear_bitmap(page);
        }
        do
        {
            //Passage au joueur suivant
            indiceActuel=(indiceActuel+1)%nbJoueurs;
        }
        while(Joueurs[indiceActuel].elimine==1);




    }
    destroy_bitmap(soldat);
    destroy_bitmap(page);
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
    BITMAP* curseur = load_bitmap("curseur.bmp", NULL);

    rectfill(fond_menu,303,173,512,237, couleur_retour_menu);
    rectfill(fond_menu, 303, 398, 512, 462, couleur_quitter);
    rectfill(fond_menu, 462, 255, 512, 305, couleur_son);
    rectfill(fond_menu, 462, 330, 512, 380, couleur_affichage);

    rectfill(buffer, 250, 50, 550, 500, makecol(200,200,200));
    rectfill(buffer, 754,14,786,46, makecol(160,160,160));
    line(buffer,754,14,786,46, makecol(96,96,96));
    line(buffer,786,14,754,46, makecol(96,96,96));

    textprintf_ex(buffer, arial_26, 360, 100, makecol(0,0,0), -1, "Menu");
    for(i = 0; i<3; i++)
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
        montre_curseur(buffer,curseur);
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
void credit_en_cours(BITMAP* page, t_decor* visuel_menu, BITMAP* soldat, t_acteur mesActeurs[], int* delay, unsigned int* temps, BITMAP* tab_bitmap[])
{
    /* Lance les credits
    Prend en parametre la bitmap d'affichage et le decor
    Ne renvoie rien */

    /////////////////////////// VARIABLE //////////////////////////
    BITMAP* curseur = load_bitmap("curseur.bmp", NULL);
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
    for (int j=0 ; j<LIMIT_STAR; j++)
    {
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

        Stardelay = Star(TabStar,Stardelay,0,page);  //Appel du sous-programme qui gère le fond
        police = affichage_credit(police, vitesse, depart_texte, page, arial_28, arial_26, arial_24, arial_22, arial_20, arial_18, arial_16, arial_14, arial_12, arial_10, arial_8);


        montre_curseur(page,curseur);

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

        animation_decor_menu(soldat, mesActeurs, delay, visuel_menu, tab_bitmap, temps);
        rest(1);


        blit(page, screen, 0, 0, 0, 0, 800, 600);
    }

}


void parametre_en_cours(BITMAP* page, t_decor* visuel_menu, SAMPLE* musique, int* volume, BITMAP* soldat, t_acteur mesActeurs[], int* delay, BITMAP* tab_bitmap[], unsigned int* temps)
{
    /* Lance les credits
    Prend en parametre la bitmap d'affichage et le decor
    Ne renvoie rien */

    /////////////////////////// VARIABLE //////////////////////////
    BITMAP* curseur = load_bitmap("curseur.bmp", NULL);
    BITMAP* fond_parametre = create_bitmap(SCREEN_W,SCREEN_H);
    int  mode_graphique = 1;
    int point[6] = {250, 500, 250+255, 500, 250+255, 350};
    int dernier_point_vert_y = 500;
    polygon(fond_parametre, 3, point, makecol(0, 255, 0));
    while(getpixel(fond_parametre, *volume+250, dernier_point_vert_y) == makecol(0, 255, 0))
        dernier_point_vert_y--;
    dernier_point_vert_y+=5;
    printf("Volume+250 : %d / dernier point y : %d", *volume+250, dernier_point_vert_y);
    int point2[6] = {256, 500, *volume+250, 500, *volume+250, dernier_point_vert_y};
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

        line(page, 251, 501, 251+255, 501, makecol(0,0, 0));
        line(page, 251+255, 351, 251+255, 501, makecol(0,0, 0));
        line(page, 251, 501, 251+255, 351, makecol(0,0, 0));

        polygon(page, 3, point2, makecol(0, 255, 0));

        montre_curseur(page,curseur);

        ////////////////////////// DESSIN BOUTON //////////////////////////

        clear_to_color(fond_parametre, makecol(0, 0, 0));
        rectfill(fond_parametre, 40, 30, 150, 100, makecol(255, 0, 0));

        rectfill(fond_parametre, 200, 200, 300, 300, makecol(255, 255, 0));
        rectfill(fond_parametre, 500, 200, 600, 300, makecol(255, 0, 255));
        polygon(fond_parametre, 3, point, makecol(0, 255, 0));
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
        if (getpixel(fond_parametre, mouse_x, mouse_y) == makecol(0, 255, 0))
        {
            if (mouse_b & 1)
            {
                point2[2] = mouse_x;
                point2[4] = mouse_x;
                dernier_point_vert_y = mouse_y;
                while(getpixel(fond_parametre, mouse_x, dernier_point_vert_y) == makecol(0, 255, 0))
                    dernier_point_vert_y--;
                point2[5] = dernier_point_vert_y+5;
                adjust_sample(musique, mouse_x-250, 128, 1000, 1);
                *volume = mouse_x-250;
            }

        }


        ///////////////////////////// AVANCEMENT DU FOND /////////////////////////////////////

        animation_decor_menu(soldat, mesActeurs, delay, visuel_menu, tab_bitmap, temps);
        rest(1);

        blit(page, screen, 0, 0, 0, 0, 800, 600);
    }
}


void apercu_classe_en_cours(BITMAP* page, t_decor* visuel_menu, BITMAP* soldat, int* delay, t_acteur mesActeurs[], BITMAP* tab_bitmap[], unsigned int* temps,t_personnage mage,t_personnage archer,t_personnage guerrier, t_personnage tank)  //soldat, mesActeurs, &delay, &visuel_menu, tab_bitmap, &temps
{
    /* Lance les credits
    Prend en parametre la bitmap d'affichage et le decor
    Ne renvoie rien */

/////////////////////////// VARIABLE //////////////////////////

    BITMAP* fond_apercu_classe = create_bitmap(SCREEN_W,SCREEN_H);

    BITMAP* map_desert = load_bitmap("map_desert.bmp", NULL);
    erreur_chargement_image(map_desert);

    BITMAP* map_neige = load_bitmap("map_neige.bmp", NULL);
    erreur_chargement_image(map_neige);

    BITMAP* map_ville = load_bitmap("map_ville.bmp", NULL);
    erreur_chargement_image(map_ville);

    BITMAP* perso1 = load_bitmap("nv_perso1.bmp", NULL);
    erreur_chargement_image(perso1);
    BITMAP* perso2 = load_bitmap("nv_perso2.bmp", NULL);
    erreur_chargement_image(perso2);

    BITMAP* text_jedi = create_bitmap(300,200);
    clear_to_color(text_jedi, makecol(40, 40, 40));
    textout_ex(text_jedi, font, "JEDI : ", 105, 5, makecol(255, 255, 255), -1);
    textprintf_ex(text_jedi, font, 105, 30, makecol(255, 255, 255), -1,"PV : %d", mage.pv_max);
    textprintf_ex(text_jedi, font,105, 45, makecol(255, 255, 255), -1, "PM : %d", mage.pm_max);
    textprintf_ex(text_jedi, font,105, 60, makecol(255, 255, 255), -1, "PA : %d", mage.pa_max);
    textout_ex(text_jedi, font, "Attaque corps a corps : ", 5, 105, makecol(255, 255, 255), -1);
    textout_ex(text_jedi, font, "Attaque special : ", 5, 125, makecol(255, 255, 255), -1);

    BITMAP* text_vador = create_bitmap(300,200);
    clear_to_color(text_vador, makecol(40, 40, 40));
    textout_ex(text_vador, font, "CLONE : ", 105, 5, makecol(255, 255, 255), -1);
    textprintf_ex(text_vador, font, 105, 30, makecol(255, 255, 255), -1, "PV : %d", archer.pv_max);
    textprintf_ex(text_vador, font, 105, 45, makecol(255, 255, 255), -1, "PM : %d", archer.pm_max);
    textprintf_ex(text_vador, font, 105, 60, makecol(255, 255, 255), -1, "PA : %d", archer.pa_max);
    textout_ex(text_vador, font, "Attaque corps a corps : ", 5, 105, makecol(255, 255, 255), -1);
    textout_ex(text_vador, font, "Attaque special : ", 5, 125, makecol(255, 255, 255), -1);

    BITMAP* text_clone = create_bitmap(300,200);
    clear_to_color(text_clone, makecol(40, 40, 40));
    textout_ex(text_clone, font, "CHASSEUR DE PRIME : ", 105, 5, makecol(255, 255, 255), -1);
    textprintf_ex(text_clone, font,105, 30, makecol(255, 255, 255), -1, "PV : %d", guerrier.pv_max);
    textprintf_ex(text_clone, font,105, 45, makecol(255, 255, 255), -1, "PM : %d", guerrier.pm_max);
    textprintf_ex(text_clone, font,105, 60, makecol(255, 255, 255), -1, "PA : %d", guerrier.pa_max);
    textout_ex(text_clone, font, "Attaque corps a corps : ", 5, 105, makecol(255, 255, 255), -1);
    textout_ex(text_clone, font, "Attaque special : ", 5, 125, makecol(255, 255, 255), -1);

    BITMAP* text_droide = create_bitmap(300,200);
    clear_to_color(text_droide, makecol(40, 40, 40));
    textout_ex(text_droide, font, "DROIDE : ", 105, 5, makecol(255, 255, 255), -1);
    textprintf_ex(text_droide, font, 105, 30, makecol(255, 255, 255), -1, "PV : %d", tank.pv_max);
    textprintf_ex(text_droide, font, 105, 45, makecol(255, 255, 255), -1, "PM : %d", tank.pm_max);
    textprintf_ex(text_droide, font, 105, 60, makecol(255, 255, 255), -1, "PA : %d", tank.pa_max);
    textout_ex(text_droide, font, "Attaque corps a corps : ", 5, 105, makecol(255, 255, 255), -1);
    textout_ex(text_droide, font, "Attaque special : ", 5, 125, makecol(255, 255, 255), -1);
    BITMAP* curseur = load_bitmap("curseur.bmp", NULL);
    //BITMAP* map_
    int position_x_bitmap_jedi = 0;
    int nouvelle_affichage_jedi = 0;
    int direction_jedi = 0;
    int sortie_boite_jedi_x = 210;
    int sortie_boite_jedi_y = 200;

    int position_x_bitmap_vador= 432;
    int nouvelle_affichage_vador = 20;
    int direction_vador = 1;
    int sortie_boite_vador_x = 560;
    int sortie_boite_vador_y = 200;

    int position_x_bitmap_clone = 96;
    int nouvelle_affichage_clone = 40;
    int direction_clone = 2;
    int sortie_boite_clone_x = 210;
    int sortie_boite_clone_y = 450;

    int position_x_bitmap_droid = 144; // a changer quand skin droid
    int nouvelle_affichage_droid = 40; // a changer quand skin droid
    int direction_droid = 2; // A changer skin droid
    int sortie_boite_droid_x = 560;
    int sortie_boite_droid_y = 450;

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



        rectfill(page, 110 - 3, 350 - 3, 210 + 3, 450 + 3, makecol(40, 40, 40));
        rectfill(page, 110, 350, 210, 450, makecol(20, 20, 20));
        rectfill(page, 110 + 3, 350 + 3, 210 - 3, 450 - 3, makecol(0, 0, 0));





        textout_ex(page, font, "Retour", 90, 60, makecol(255, 0, 0), -1);


        // Afficher les classes




        masked_blit(map_neige, page, 400, 400, 111, 351, 98, 98);



////////////////////////// DESSIN BOUTON //////////////////////////

        clear_to_color(fond_apercu_classe, makecol(0, 0, 0));
        rectfill(fond_apercu_classe, 40, 30, 150, 100, makecol(255, 0, 0));

        rectfill(fond_apercu_classe, 110, 100, 210, 200, makecol(0, 255, 0));
        rectfill(fond_apercu_classe, 110, 350, 210, 450, makecol(0, 0, 255));
        rectfill(fond_apercu_classe, 460, 100, 560, 200, makecol(255, 255, 0));
        rectfill(fond_apercu_classe, 460, 350, 560, 450, makecol(0, 255, 255));

////////////////////////// DETECTION BOUTON //////////////////////////

        if (getpixel(fond_apercu_classe, mouse_x, mouse_y) == makecol(255, 0, 0))
        {
            if (mouse_b & 1)
            {
                return;
            }
        }

        ///////////// JEDI /////////////

        if (getpixel(fond_apercu_classe, mouse_x, mouse_y) == makecol(0, 255, 0))
        {

            rectfill(page, 110, 100, sortie_boite_jedi_x, sortie_boite_jedi_y, makecol(0, 0, 0));
            rectfill(page, 110+2, 100+2, sortie_boite_jedi_x-2, sortie_boite_jedi_y-2, makecol(20, 20, 20));
            blit(text_jedi, page, 0, 0, 110+4, 100+4, sortie_boite_jedi_x-110-7, sortie_boite_jedi_y-100-7);
            if (sortie_boite_jedi_x <= 410)
            {
                sortie_boite_jedi_x+=2;
            }
            if (sortie_boite_jedi_y <= 300)
            {
                sortie_boite_jedi_y++;
            }
        }
        else
        {
            rectfill(page, 110, 100, sortie_boite_jedi_x, sortie_boite_jedi_y, makecol(0, 0, 0));
            rectfill(page, 110+2, 100+2, sortie_boite_jedi_x-2, sortie_boite_jedi_y-2, makecol(20, 20, 20));
            blit(text_jedi, page, 0, 0, 110+4, 100+4, sortie_boite_jedi_x-110-6, sortie_boite_jedi_y-100-6);
            if (sortie_boite_jedi_x>=210)
            {
                sortie_boite_jedi_x-=2;
            }
            if (sortie_boite_jedi_y>=200)
            {
                sortie_boite_jedi_y--;
            }
        }

        ///////////// DARK VADOR /////////////

        if (getpixel(fond_apercu_classe, mouse_x, mouse_y) == makecol(255, 255, 0))
        {
            rectfill(page, 460, 100, sortie_boite_vador_x, sortie_boite_vador_y, makecol(0, 0, 0));
            rectfill(page, 460+2, 100+2, sortie_boite_vador_x-2, sortie_boite_vador_y-2, makecol(20, 20, 20));
            blit(text_vador, page, 0, 0, 460+4, 100+4, sortie_boite_vador_x-460-7, sortie_boite_vador_y-100-7);
            if (sortie_boite_vador_x <= 760)
            {
                sortie_boite_vador_x+=2;
            }
            if (sortie_boite_vador_y <= 300)
            {
                sortie_boite_vador_y++;
            }
        }
        else
        {
            rectfill(page, 460, 100, sortie_boite_vador_x, sortie_boite_vador_y, makecol(0, 0, 0));
            rectfill(page, 460+2, 100+2, sortie_boite_vador_x-2, sortie_boite_vador_y-2, makecol(20, 20, 20));
            blit(text_vador, page, 0, 0, 460+4, 100+4, sortie_boite_vador_x-460-6, sortie_boite_vador_y-100-6);
            if (sortie_boite_vador_x>=560)
            {
                sortie_boite_vador_x-=2;
            }
            if (sortie_boite_vador_y>=200)
            {
                sortie_boite_vador_y--;
            }
        }

        ///////////// CLONE /////////////

        if (getpixel(fond_apercu_classe, mouse_x, mouse_y) == makecol(0, 0, 255))
        {
            rectfill(page, 110, 350, sortie_boite_clone_x, sortie_boite_clone_y, makecol(0, 0, 0));
            rectfill(page, 110+2, 350+2, sortie_boite_clone_x-2, sortie_boite_clone_y-2, makecol(20, 20, 20));
            blit(text_clone, page, 0, 0, 110+4, 350+4, sortie_boite_clone_x-110-7, sortie_boite_clone_y-350-7);
            if (sortie_boite_clone_x <= 410)
            {
                sortie_boite_clone_x+=2;
            }
            if (sortie_boite_clone_y <= 550)
            {
                sortie_boite_clone_y++;
            }
        }
        else
        {
            rectfill(page, 110, 350, sortie_boite_clone_x, sortie_boite_clone_y, makecol(0, 0, 0));
            rectfill(page, 110+2, 350+2, sortie_boite_clone_x-2, sortie_boite_clone_y-2, makecol(20, 20, 20));
            blit(text_clone, page, 0, 0, 110+4, 350+4, sortie_boite_clone_x-110-6, sortie_boite_clone_y-350-6);
            if (sortie_boite_clone_x>=210)
            {
                sortie_boite_clone_x-=2;
            }
            if (sortie_boite_clone_y>=450)
            {
                sortie_boite_clone_y--;
            }
        }

        ///////////// DROIDE /////////////

        if (getpixel(fond_apercu_classe, mouse_x, mouse_y) == makecol(0, 255, 255))
        {
            rectfill(page, 460, 350, sortie_boite_droid_x, sortie_boite_droid_y, makecol(0, 0, 0));
            rectfill(page, 460+2, 350+2, sortie_boite_droid_x-2, sortie_boite_droid_y-2, makecol(20, 20, 20));
            blit(text_droide, page, 0, 0, 460+4, 350+4, sortie_boite_droid_x-460-7, sortie_boite_droid_y-350-7);
            if (sortie_boite_droid_x <= 760)
            {
                sortie_boite_droid_x+=2;
            }
            if (sortie_boite_droid_y <= 550)
            {
                sortie_boite_droid_y++;
            }
        }
        else
        {
            rectfill(page, 460, 350, sortie_boite_droid_x, sortie_boite_droid_y, makecol(0, 0, 0));
            rectfill(page, 460+2, 350+2, sortie_boite_droid_x-2, sortie_boite_droid_y-2, makecol(20, 20, 20));
            blit(text_droide, page, 0, 0, 460+4, 350+4, sortie_boite_droid_x-460-6, sortie_boite_droid_y-350-6);
            if (sortie_boite_droid_x>=560)
            {
                sortie_boite_droid_x-=2;
            }
            if (sortie_boite_droid_y>=450)
            {
                sortie_boite_droid_y--;
            }
        }



        ///////////////////////////// AVANCEMENT DU FOND /////////////////////////////////////

        animation_decor_menu(soldat, mesActeurs, delay, visuel_menu, tab_bitmap, temps);
        rest(1);


        ///////////////////////////// ANIMATION PERSONNAGE /////////////////////////////////////

        affichage_classe1(&position_x_bitmap_jedi, &nouvelle_affichage_jedi, &direction_jedi, perso1, page, 150, 150, map_desert);
        affichage_classe3(&position_x_bitmap_vador, &nouvelle_affichage_vador, &direction_vador, perso1, page, 490, 150, map_neige);
        affichage_classe2(&position_x_bitmap_clone, &nouvelle_affichage_clone, &direction_clone, perso1, page, 140, 405, map_ville);
        affichage_classe4(&position_x_bitmap_droid, &nouvelle_affichage_droid, &direction_droid, perso2, page, 490, 405, map_desert);

        montre_curseur(page,curseur);

        blit(page, screen, 0, 0, 0, 0, 800, 600);
    }
}












