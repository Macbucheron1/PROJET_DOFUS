#include "HEADER.h"

/* ------------------------------------- FONCTION d'affichage -------------------------------------
    Les fontions présente dans ce fichier sont des fonctions d'affichage, elles ne servent à rien d'autre
    que l'affichage
*/


void changement_graphique(int valeur)
{
/* Permet de changer de mode graphique
   0 pour mettre en pleine ecran et 1 pour mettre en fenetre*/
    if (valeur == 0)
    {
        if (set_gfx_mode(GFX_AUTODETECT_FULLSCREEN,1600,600,0,0)!=0)
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

void montre_curseur(BITMAP* page)
{
    /* Permet d'afficher un curseur personnalisé
    Prend en parametre la bitmap sur laquel affiché le curseur
    Ne renvoie rien*/
    BITMAP* curseur = load_bitmap("curseur.bmp", NULL);
    erreur_chargement_image(curseur);
    draw_sprite(page, curseur, mouse_x, mouse_y);
}


void SurbrillanceDeplacement(BITMAP* buffer,t_map carte, int zoneDeplacement[20][16])
{
    /* Affiche les zones sur lesqeuelles peut aller le personnage en vert
    Prend en parametre la bitmap d'affichage, la carte, la zone de deplacement
    Ne renvoie rien */

    for(int i=0; i<20;i++)
    {

        for(int j=0;j<16;j++)
        {
            if(zoneDeplacement[i][j]==1)
            {
                rectfill(buffer,carte.tab_coordonnes[i][j].position_pixel_x+5, carte.tab_coordonnes[i][j].position_pixel_y+5, carte.tab_coordonnes[i][j].position_pixel_x +32-5,carte.tab_coordonnes[i][j].position_pixel_y+32-5, makecol(0,255,0));
            }
        }
    }
    afficheSouris(buffer,carte,zoneDeplacement);
}


void afficheSouris(BITMAP* buffer,t_map carte, int zoneDeplacement[20][16])
{
    /* Affiche un carré bleu a la position de la souris (si la souris se trouve dans la zone de deplacement)
    Prend en parametre la bitmap d'affichage, la carte et la zone de deplacement
    Ne renvoie rien */

    int i=0,j=0;
    if(position_souris_colonne()!=-1 && position_souris_ligne()!=-1)
    {
        i= position_souris_colonne();
        j= position_souris_ligne();
        if(zoneDeplacement[i][j]==1)
            rectfill(buffer,carte.tab_coordonnes[i][j].position_pixel_x+5, carte.tab_coordonnes[i][j].position_pixel_y+5, carte.tab_coordonnes[i][j].position_pixel_x +32-5,carte.tab_coordonnes[i][j].position_pixel_y+32-5, makecol(0,0,255));
    }

}

void AnimationDeplacement(BITMAP* buffer, BITMAP* soldat, t_map carte, int x_initial, int y_initial, int indiceActuel, coords chemin[], int PM, int nbJoueurs, t_joueur Joueurs[])
{
    /* Permet d'animer le deplacement
    Prend en parametre la bitmap d'image, le skin du joueur, la carte, les coordonnées initial, le joueur qui joue, le chemin, les points de mouvement
    Ne renvoie rien */

    if(Joueurs[indiceActuel].classe.numero_classe==1)
        AnimationClasse1(buffer, soldat, carte, x_initial, y_initial, indiceActuel, chemin, PM, nbJoueurs, Joueurs);
    else if(Joueurs[indiceActuel].classe.numero_classe==2)
        AnimationClasse2(buffer, soldat, carte, x_initial, y_initial, indiceActuel, chemin, PM, nbJoueurs, Joueurs);
    else if(Joueurs[indiceActuel].classe.numero_classe==3)
        AnimationClasse3(buffer, soldat, carte, x_initial, y_initial, indiceActuel, chemin, PM, nbJoueurs, Joueurs);
    /*else if(Joueurs[indiceActuel].classe.numero_classe==4)
        AnimationClasse4(buffer, soldat, carte, x_initial, y_initial, indiceActuel, chemin, PM, nbJoueurs, Joueurs);*/
}

void affichage_classe1(int* position_x_bitmap_soldat, int* nouvelle_affichage, int* direction_soldat, BITMAP* soldat, BITMAP* page, int position_affichage_x, int position_affichage_y, BITMAP* map_desert)
{
        /* Permet d'afficher la classe jedi
        Prend en parametre la position du skin dans la bitmap, le temps ecoulé depuis le dernier changement d'affichage, la direction du personnage, le personnage, la bitmap d'affichage, la position d'affichage, la bitmap de fond
        Ne renvoie rien */
        rectfill(page, 110 - 3, 100 - 3, 210 + 3, 200 + 3, makecol(40, 40, 40));
        rectfill(page, 110, 100, 210, 200, makecol(20, 20, 20));
        rectfill(page, 110 + 3, 100 + 3, 210 - 3, 200 - 3, makecol(0, 0, 0));
        masked_blit(map_desert, page, 100, 100, 111, 101, 98, 98);
        *nouvelle_affichage = *nouvelle_affichage + 1;
        if (*nouvelle_affichage%10 == 0)
        {
            *position_x_bitmap_soldat = *position_x_bitmap_soldat + 96;
        }
        if (*position_x_bitmap_soldat>=340)
        {
            *position_x_bitmap_soldat = 32;
        }
        if (*nouvelle_affichage >= 80)
        {
            *direction_soldat = *direction_soldat + 1;
            *nouvelle_affichage = 0;
        }
        if (*direction_soldat >= 4)
        {
            *direction_soldat = 0;
        }
        else if (*direction_soldat == 0)
        {
            masked_blit(soldat,page, *position_x_bitmap_soldat, 207, position_affichage_x,position_affichage_y-30, 32,64);
        }
        else if (*direction_soldat == 1)
        {
            masked_blit(soldat,page, *position_x_bitmap_soldat, 14, position_affichage_x,position_affichage_y-30, 32,64);
        }
        else if (*direction_soldat == 2)
        {
            masked_blit(soldat,page, *position_x_bitmap_soldat, 300, position_affichage_x,position_affichage_y-30, 32,64);
        }
        else if (*direction_soldat == 3)
        {
           masked_blit(soldat,page, *position_x_bitmap_soldat, 108, position_affichage_x,position_affichage_y-30, 32,64);
        }


}


void affichage_classe3(int* position_x_bitmap_soldat, int* nouvelle_affichage, int* direction_soldat, BITMAP* soldat, BITMAP* page, int position_affichage_x, int position_affichage_y, BITMAP* map_neige)
{
        /* Permet d'afficher la classe Dark vador
        Prend en parametre la position du skin dans la bitmap, le temps ecoulé depuis le dernier changement d'affichage, la direction du personnage, le personnage, la bitmap d'affichage, la position d'affichage, la bitmap de fond
        Ne renvoie rien */
        rectfill(page, 460 - 3, 100 - 3, 560 + 3, 200 + 3, makecol(40, 40, 40));
        rectfill(page, 460, 100, 560, 200, makecol(20, 20, 20));
        rectfill(page, 460 + 3, 100 + 3, 560 - 3, 200 - 3, makecol(0, 0, 0));
        masked_blit(map_neige, page, 100, 200, 461, 101, 98, 98);
        *nouvelle_affichage = *nouvelle_affichage + 1;
        if (*nouvelle_affichage%10 == 0)
        {
            *position_x_bitmap_soldat = *position_x_bitmap_soldat + 75;
        }
        if (*position_x_bitmap_soldat>=870)
        {
            *position_x_bitmap_soldat = 630;
        }
        if (*nouvelle_affichage >= 80)
        {
            *direction_soldat = *direction_soldat + 1;
            *nouvelle_affichage = 0;
        }
        if (*direction_soldat >= 4)
        {
            *direction_soldat = 0;
        }
        else if (*direction_soldat == 0)
        {
            masked_blit(soldat,page, *position_x_bitmap_soldat, 492, position_affichage_x,position_affichage_y-30, 33,64);
        }
        else if (*direction_soldat == 1)
        {
            masked_blit(soldat,page, *position_x_bitmap_soldat, 417, position_affichage_x,position_affichage_y-30, 33,64);
        }
        else if (*direction_soldat == 2)
        {
            masked_blit(soldat,page, *position_x_bitmap_soldat, 566, position_affichage_x,position_affichage_y-30, 33,64);
        }
        else if (*direction_soldat == 3)
        {
           masked_blit(soldat,page, *position_x_bitmap_soldat, 340, position_affichage_x,position_affichage_y-30, 33,64);
        }


}

void affichage_classe2(int* position_x_bitmap_soldat, int* nouvelle_affichage, int* direction_soldat, BITMAP* soldat, BITMAP* page, int position_affichage_x, int position_affichage_y, BITMAP* map_ville)
{
        /* Permet d'afficher la classe clone
        Prend en parametre la position du skin dans la bitmap, le temps ecoulé depuis le dernier changement d'affichage, la direction du personnage, le personnage, la bitmap d'affichage, la position d'affichage, la bitmap de fond
        Ne renvoie rien */
        rectfill(page, 460 - 3, 350 - 3, 560 + 3, 450 + 3, makecol(40, 40, 40));
        rectfill(page, 460, 350, 560, 450, makecol(20, 20, 20));
        rectfill(page, 460 + 3, 350 + 3, 560 - 3, 450 - 3, makecol(0, 0, 0));
        masked_blit(map_ville, page, 180, 200, 111, 351, 98, 98);
        *nouvelle_affichage = *nouvelle_affichage + 1;
        if (*nouvelle_affichage%10 == 0)
        {
            *position_x_bitmap_soldat = *position_x_bitmap_soldat + 77;
        }
        if (*position_x_bitmap_soldat>=890)
        {
            *position_x_bitmap_soldat = 630;
        }
        if (*nouvelle_affichage >= 80)
        {
            *direction_soldat = *direction_soldat + 1;
            *nouvelle_affichage = 0;
        }
        if (*direction_soldat >= 4)
        {
            *direction_soldat = 0;
        }
        else if (*direction_soldat == 0)
        {
            masked_blit(soldat,page, *position_x_bitmap_soldat, 166, position_affichage_x,position_affichage_y-30, 36,64);
        }
        else if (*direction_soldat == 1)
        {
            masked_blit(soldat,page, *position_x_bitmap_soldat, 7, position_affichage_x,position_affichage_y-30, 36,64);
        }
        else if (*direction_soldat == 2)
        {
            masked_blit(soldat,page, *position_x_bitmap_soldat, 247, position_affichage_x,position_affichage_y-30, 36,64);
        }
        else if (*direction_soldat == 3)
        {
           masked_blit(soldat,page, *position_x_bitmap_soldat, 85, position_affichage_x,position_affichage_y-30, 36,64);
        }
}

int affichage_credit(int police, int vitesse, int depart_texte, BITMAP* page, FONT* arial_28, FONT* arial_26, FONT* arial_24, FONT* arial_22, FONT* arial_20,FONT* arial_18, FONT* arial_16, FONT* arial_14, FONT* arial_12, FONT* arial_10, FONT* arial_8)
{

        if (police <= 1*vitesse)
        {
            textout_ex(page, arial_28, "DOFUS STAR WARS", 250-20, depart_texte-police, makecol(255, 255, 0), -1);
        }
        else if (police <= 2*vitesse)
        {
            textout_ex(page, arial_26, "DOFUS STAR WARS", 250-10, depart_texte-police, makecol(255, 255, 0), -1);
            textout_ex(page, arial_28, "Realise par :", 250-20, depart_texte-police+vitesse+10, makecol(255, 255, 0), -1);
        }
        else if (police <= 3*vitesse)
        {
            textout_ex(page, arial_24, "DOFUS STAR WARS", 250, depart_texte-police, makecol(255, 255, 0), -1);
            textout_ex(page, arial_26, "Realise par :", 250-10, depart_texte-police+vitesse+10, makecol(255, 255, 0), -1);
            textout_ex(page, arial_28, "Nathan Deprat", 300-20, depart_texte-police+2*vitesse+15, makecol(255, 255, 0), -1);
        }
        else if (police <= 4*vitesse)
        {
            textout_ex(page, arial_22, "DOFUS STAR WARS", 250+10, depart_texte-police, makecol(255, 255, 0), -1);
            textout_ex(page, arial_24, "Realise par :", 250, depart_texte-police+vitesse+10, makecol(255, 255, 0), -1);
            textout_ex(page, arial_26, "Nathan Deprat", 300-10, depart_texte-police+2*vitesse+15, makecol(255, 255, 0), -1);
            textout_ex(page, arial_28, "Luc Renaud", 300-20, depart_texte-police+3*vitesse+20, makecol(255, 255, 0), -1);
        }
        else if (police <= 5*vitesse)
        {
            textout_ex(page, arial_20, "DOFUS STAR WARS", 250+20, depart_texte-police, makecol(255, 255, 0), -1);
            textout_ex(page, arial_22, "Realise par :", 250+10, depart_texte-police+vitesse+10, makecol(255, 255, 0), -1);
            textout_ex(page, arial_24, "Nathan Deprat", 300, depart_texte-police+2*vitesse+15, makecol(255, 255, 0), -1);
            textout_ex(page, arial_26, "Luc Renaud", 300-10, depart_texte-police+3*vitesse+20, makecol(255, 255, 0), -1);
            textout_ex(page, arial_28, "Ibrahim Diallo", 300-20, depart_texte-police+4*vitesse+25, makecol(255, 255, 0), -1);
        }
        else if (police <= 6*vitesse)
        {
            textout_ex(page, arial_18, "DOFUS STAR WARS", 250+30, depart_texte-police, makecol(255, 255, 0), -1);
            textout_ex(page, arial_20, "Realise par :", 250+20, depart_texte-police+vitesse+10, makecol(255, 255, 0), -1);
            textout_ex(page, arial_22, "Nathan Deprat", 300+10, depart_texte-police+2*vitesse+15, makecol(255, 255, 0), -1);
            textout_ex(page, arial_24, "Luc Renaud", 300, depart_texte-police+3*vitesse+20, makecol(255, 255, 0), -1);
            textout_ex(page, arial_26, "Ibrahim Diallo", 300-10, depart_texte-police+4*vitesse+25, makecol(255, 255, 0), -1);
            textout_ex(page, arial_28, "Maxime Maeder", 300-20, depart_texte-police+5*vitesse+30, makecol(255, 255, 0), -1);
        }
        else if (police <= 7*vitesse)
        {
            textout_ex(page, arial_16, "DOFUS STAR WARS", 250+40, depart_texte-police, makecol(255, 255, 0), -1);
            textout_ex(page, arial_18, "Realise par :", 250+30, depart_texte-police+vitesse+10, makecol(255, 255, 0), -1);
            textout_ex(page, arial_20, "Nathan Deprat", 300+20, depart_texte-police+2*vitesse+15, makecol(255, 255, 0), -1);
            textout_ex(page, arial_22, "Luc Renaud", 300+10, depart_texte-police+3*vitesse+20, makecol(255, 255, 0), -1);
            textout_ex(page, arial_24, "Ibrahim Diallo", 300, depart_texte-police+4*vitesse+25, makecol(255, 255, 0), -1);
            textout_ex(page, arial_26, "Maxime Maeder", 300-10, depart_texte-police+5*vitesse+30, makecol(255, 255, 0), -1);
        }
        else if (police <= 8*vitesse)
        {
            textout_ex(page, arial_14, "DOFUS STAR WARS", 250+50, depart_texte-police, makecol(255, 255, 0), -1);
            textout_ex(page, arial_16, "Realise par :", 250+40, depart_texte-police+vitesse+10, makecol(255, 255, 0), -1);
            textout_ex(page, arial_18, "Nathan Deprat", 300+30, depart_texte-police+2*vitesse+15, makecol(255, 255, 0), -1);
            textout_ex(page, arial_20, "Luc Renaud", 300+20, depart_texte-police+3*vitesse+20, makecol(255, 255, 0), -1);
            textout_ex(page, arial_22, "Ibrahim Diallo", 300+10, depart_texte-police+4*vitesse+25, makecol(255, 255, 0), -1);
            textout_ex(page, arial_24, "Maxime Maeder", 300, depart_texte-police+5*vitesse+30, makecol(255, 255, 0), -1);
            textout_ex(page, arial_28, "Il etait une fois", 300-20, depart_texte-police+6*vitesse+35, makecol(255, 255, 0), -1);
        }
        else if (police <= 9*vitesse)
        {
            textout_ex(page, arial_12, "DOFUS STAR WARS", 250+60, depart_texte-police, makecol(255, 255, 0), -1);
            textout_ex(page, arial_14, "Realise par :", 250+50, depart_texte-police+vitesse+10, makecol(255, 255, 0), -1);
            textout_ex(page, arial_16, "Nathan Deprat", 300+40, depart_texte-police+2*vitesse+15, makecol(255, 255, 0), -1);
            textout_ex(page, arial_18, "Luc Renaud", 300+30, depart_texte-police+3*vitesse+20, makecol(255, 255, 0), -1);
            textout_ex(page, arial_20, "Ibrahim Diallo", 300+20, depart_texte-police+4*vitesse+25, makecol(255, 255, 0), -1);
            textout_ex(page, arial_22, "Maxime Maeder", 300+10, depart_texte-police+5*vitesse+30, makecol(255, 255, 0), -1);
            textout_ex(page, arial_26, "Il etait une fois", 300-10, depart_texte-police+6*vitesse+35, makecol(255, 255, 0), -1);
            textout_ex(page, arial_28, "dans une lointaine galaxie", 250-20, depart_texte-police+7*vitesse+40, makecol(255, 255, 0), -1);
        }
        else if (police <= 10*vitesse)
        {
            textout_ex(page, arial_10, "DOFUS STAR WARS", 250+70, depart_texte-police, makecol(255, 255, 0), -1);
            textout_ex(page, arial_12, "Realise par :", 250+60, depart_texte-police+vitesse+10, makecol(255, 255, 0), -1);
            textout_ex(page, arial_14, "Nathan Deprat", 300+50, depart_texte-police+2*vitesse+15, makecol(255, 255, 0), -1);
            textout_ex(page, arial_16, "Luc Renaud", 300+40, depart_texte-police+3*vitesse+20, makecol(255, 255, 0), -1);
            textout_ex(page, arial_18, "Ibrahim Diallo", 300+30, depart_texte-police+4*vitesse+25, makecol(255, 255, 0), -1);
            textout_ex(page, arial_20, "Maxime Maeder", 300+20, depart_texte-police+5*vitesse+30, makecol(255, 255, 0), -1);
            textout_ex(page, arial_24, "Il etait une fois", 300, depart_texte-police+6*vitesse+35, makecol(255, 255, 0), -1);
            textout_ex(page, arial_26, "dans une lointaine galaxie", 250-10, depart_texte-police+7*vitesse+40, makecol(255, 255, 0), -1);
            textout_ex(page, arial_28, "4 etudiants talentueux", 280-20, depart_texte-police+8*vitesse+45, makecol(255, 255, 0), -1);
        }
        else if (police <= 11*vitesse)
        {
            textout_ex(page, arial_8, "DOFUS STAR WARS", 250+80, depart_texte-police, makecol(255, 255, 0), -1);
            textout_ex(page, arial_10, "Realise par ", 250+70, depart_texte-police+vitesse+10, makecol(255, 255, 0), -1);
            textout_ex(page, arial_12, "Nathan Deprat", 300+60, depart_texte-police+2*vitesse+15, makecol(255, 255, 0), -1);
            textout_ex(page, arial_14, "Luc Renaud", 300+50, depart_texte-police+3*vitesse+20, makecol(255, 255, 0), -1);
            textout_ex(page, arial_16, "Ibrahim Diallo", 300+40, depart_texte-police+4*vitesse+25, makecol(255, 255, 0), -1);
            textout_ex(page, arial_18, "Maxime Maeder", 300+30, depart_texte-police+5*vitesse+30, makecol(255, 255, 0), -1);
            textout_ex(page, arial_22, "Il etait une fois", 300+10, depart_texte-police+6*vitesse+35, makecol(255, 255, 0), -1);
            textout_ex(page, arial_24, "dans une lointaine galaxie", 250, depart_texte-police+7*vitesse+40, makecol(255, 255, 0), -1);
            textout_ex(page, arial_26, "4 etudiants talentueux", 280-10, depart_texte-police+8*vitesse+45, makecol(255, 255, 0), -1);
            textout_ex(page, arial_28, "creerent un jeu legendaire", 250-20, depart_texte-police+9*vitesse+50, makecol(255, 255, 0), -1);
        }
        else if (police <= 12*vitesse)
        {
            textout_ex(page, arial_8, "Realise par :", 250+80, depart_texte-police+vitesse+10, makecol(255, 255, 0), -1);
            textout_ex(page, arial_10, "Nathan Deprat", 300+70, depart_texte-police+2*vitesse+15, makecol(255, 255, 0), -1);
            textout_ex(page, arial_12, "Luc Renaud", 300+60, depart_texte-police+3*vitesse+20, makecol(255, 255, 0), -1);
            textout_ex(page, arial_14, "Ibrahim Diallo", 300+50, depart_texte-police+4*vitesse+25, makecol(255, 255, 0), -1);
            textout_ex(page, arial_16, "Maxime Maeder", 300+40, depart_texte-police+5*vitesse+30, makecol(255, 255, 0), -1);
            textout_ex(page, arial_20, "Il etait une fois", 300+20, depart_texte-police+6*vitesse+35, makecol(255, 255, 0), -1);
            textout_ex(page, arial_22, "dans une lointaine galaxie", 250+10, depart_texte-police+7*vitesse+40, makecol(255, 255, 0), -1);
            textout_ex(page, arial_24, "4 etudiants talentueux", 280, depart_texte-police+8*vitesse+45, makecol(255, 255, 0), -1);
            textout_ex(page, arial_26, "creerent un jeu legendaire", 250-10, depart_texte-police+9*vitesse+50, makecol(255, 255, 0), -1);
            textout_ex(page, arial_28, "ainsi naquit", 300-20, depart_texte-police+10*vitesse+55, makecol(255, 255, 0), -1);
        }
        else if (police <= 13*vitesse)
        {
            textout_ex(page, arial_8, "Nathan Deprat", 300+80, depart_texte-police+2*vitesse+15, makecol(255, 255, 0), -1);
            textout_ex(page, arial_10, "Luc Renaud", 300+70, depart_texte-police+3*vitesse+20, makecol(255, 255, 0), -1);
            textout_ex(page, arial_12, "Ibrahim Diallo", 300+60, depart_texte-police+4*vitesse+25, makecol(255, 255, 0), -1);
            textout_ex(page, arial_14, "Maxime Maeder", 300+50, depart_texte-police+5*vitesse+30, makecol(255, 255, 0), -1);
            textout_ex(page, arial_18, "Il etait une fois", 300+30, depart_texte-police+6*vitesse+35, makecol(255, 255, 0), -1);
            textout_ex(page, arial_20, "dans une lointaine galaxie", 250+20, depart_texte-police+7*vitesse+40, makecol(255, 255, 0), -1);
            textout_ex(page, arial_22, "4 etudiants talentueux", 280+10, depart_texte-police+8*vitesse+45, makecol(255, 255, 0), -1);
            textout_ex(page, arial_24, "creerent un jeu legendaire", 250, depart_texte-police+9*vitesse+50, makecol(255, 255, 0), -1);
            textout_ex(page, arial_26, "ainsi naquit", 300-10, depart_texte-police+10*vitesse+55, makecol(255, 255, 0), -1);
            textout_ex(page, arial_28, "ce jeu exceptionnel", 280-20, depart_texte-police+11*vitesse+60, makecol(255, 255, 0), -1);
        }
        else if (police <= 13*vitesse)
        {
            textout_ex(page, arial_8, "Luc Renaud", 300+80, depart_texte-police+3*vitesse+20, makecol(255, 255, 0), -1);
            textout_ex(page, arial_10, "Ibrahim Diallo", 300+70, depart_texte-police+4*vitesse+25, makecol(255, 255, 0), -1);
            textout_ex(page, arial_12, "Maxime Maeder", 300+60, depart_texte-police+5*vitesse+30, makecol(255, 255, 0), -1);
            textout_ex(page, arial_16, "Il etait une fois", 300+40, depart_texte-police+6*vitesse+35, makecol(255, 255, 0), -1);
            textout_ex(page, arial_18, "dans une lointaine galaxie", 250+30, depart_texte-police+7*vitesse+40, makecol(255, 255, 0), -1);
            textout_ex(page, arial_20, "4 etudiants talentueux", 280+20, depart_texte-police+8*vitesse+45, makecol(255, 255, 0), -1);
            textout_ex(page, arial_22, "creerent un jeu legendaire", 250+10, depart_texte-police+9*vitesse+50, makecol(255, 255, 0), -1);
            textout_ex(page, arial_24, "ainsi naquit", 300, depart_texte-police+10*vitesse+55, makecol(255, 255, 0), -1);
            textout_ex(page, arial_26, "ce jeu exceptionnel", 280-10, depart_texte-police+11*vitesse+60, makecol(255, 255, 0), -1);
        }
        else if (police <= 14*vitesse)
        {
            textout_ex(page, arial_8, "Ibrahim Diallo", 300+80, depart_texte-police+4*vitesse+25, makecol(255, 255, 0), -1);
            textout_ex(page, arial_10, "Maxime Maeder", 300+70, depart_texte-police+5*vitesse+30, makecol(255, 255, 0), -1);
            textout_ex(page, arial_14, "Il etait une fois", 300+50, depart_texte-police+6*vitesse+35, makecol(255, 255, 0), -1);
            textout_ex(page, arial_16, "dans une lointaine galaxie", 250+40, depart_texte-police+7*vitesse+40, makecol(255, 255, 0), -1);
            textout_ex(page, arial_18, "4 etudiants talentueux", 280+30, depart_texte-police+8*vitesse+45, makecol(255, 255, 0), -1);
            textout_ex(page, arial_20, "creerent un jeu legendaire", 250+20, depart_texte-police+9*vitesse+50, makecol(255, 255, 0), -1);
            textout_ex(page, arial_22, "ainsi naquit", 300+10, depart_texte-police+10*vitesse+55, makecol(255, 255, 0), -1);
            textout_ex(page, arial_24, "ce jeu exceptionnel", 280, depart_texte-police+11*vitesse+60, makecol(255, 255, 0), -1);
        }
        else if (police <= 15*vitesse)
        {
            textout_ex(page, arial_8, "Maxime Maeder", 300+80, depart_texte-police+5*vitesse+30, makecol(255, 255, 0), -1);
            textout_ex(page, arial_12, "Il etait une fois", 300+60, depart_texte-police+6*vitesse+35, makecol(255, 255, 0), -1);
            textout_ex(page, arial_14, "dans une lointaine galaxie", 250+50, depart_texte-police+7*vitesse+40, makecol(255, 255, 0), -1);
            textout_ex(page, arial_16, "4 etudiants talentueux", 280+40, depart_texte-police+8*vitesse+45, makecol(255, 255, 0), -1);
            textout_ex(page, arial_18, "creerent un jeu legendaire", 250+30, depart_texte-police+9*vitesse+50, makecol(255, 255, 0), -1);
            textout_ex(page, arial_20, "ainsi naquit", 300+20, depart_texte-police+10*vitesse+55, makecol(255, 255, 0), -1);
            textout_ex(page, arial_22, "ce jeu exceptionnel", 280+10, depart_texte-police+11*vitesse+60, makecol(255, 255, 0), -1);
        }
        else if (police <= 16*vitesse)
        {
            textout_ex(page, arial_10, "Il etait une fois", 300+70, depart_texte-police+6*vitesse+35, makecol(255, 255, 0), -1);
            textout_ex(page, arial_12, "dans une lointaine galaxie", 250+60, depart_texte-police+7*vitesse+40, makecol(255, 255, 0), -1);
            textout_ex(page, arial_14, "4 etudiants talentueux", 280+50, depart_texte-police+8*vitesse+45, makecol(255, 255, 0), -1);
            textout_ex(page, arial_16, "creerent un jeu legendaire", 250+40, depart_texte-police+9*vitesse+50, makecol(255, 255, 0), -1);
            textout_ex(page, arial_18, "ainsi naquit", 300+30, depart_texte-police+10*vitesse+55, makecol(255, 255, 0), -1);
            textout_ex(page, arial_20, "ce jeu exceptionnel", 280+20, depart_texte-police+11*vitesse+60, makecol(255, 255, 0), -1);
        }
        else if (police <= 17*vitesse)
        {
            textout_ex(page, arial_8, "Il etait une fois", 300+80, depart_texte-police+6*vitesse+35, makecol(255, 255, 0), -1);
            textout_ex(page, arial_10, "Il etait une fois", 250+70, depart_texte-police+7*vitesse+40, makecol(255, 255, 0), -1);
            textout_ex(page, arial_12, "4 etudiants talentueux", 280+60, depart_texte-police+8*vitesse+45, makecol(255, 255, 0), -1);
            textout_ex(page, arial_14, "creerent un jeu legendaire", 250+50, depart_texte-police+9*vitesse+50, makecol(255, 255, 0), -1);
            textout_ex(page, arial_16, "ainsi naquit", 300+40, depart_texte-police+10*vitesse+55, makecol(255, 255, 0), -1);
            textout_ex(page, arial_18, "ce jeu exceptionnel", 280+30, depart_texte-police+11*vitesse+60, makecol(255, 255, 0), -1);
        }
        else if (police <= 18*vitesse)
        {
            textout_ex(page, arial_8, "dans une lointaine galaxie", 250+80, depart_texte-police+7*vitesse+40, makecol(255, 255, 0), -1);
            textout_ex(page, arial_10, "4 etudiants talentueux", 280+70, depart_texte-police+8*vitesse+45, makecol(255, 255, 0), -1);
            textout_ex(page, arial_12, "creerent un jeu legendaire", 250+60, depart_texte-police+9*vitesse+50, makecol(255, 255, 0), -1);
            textout_ex(page, arial_14, "ainsi naquit", 300+50, depart_texte-police+10*vitesse+55, makecol(255, 255, 0), -1);
            textout_ex(page, arial_16, "ce jeu exceptionnel", 280+40, depart_texte-police+11*vitesse+60, makecol(255, 255, 0), -1);
        }
        else if (police <= 19*vitesse)
        {
            textout_ex(page, arial_8, "4 etudiants talentueux", 280+80, depart_texte-police+8*vitesse+45, makecol(255, 255, 0), -1);
            textout_ex(page, arial_10, "creerent un jeu legendaire", 250+70, depart_texte-police+9*vitesse+50, makecol(255, 255, 0), -1);
            textout_ex(page, arial_12, "ainsi naquit", 300+60, depart_texte-police+10*vitesse+55, makecol(255, 255, 0), -1);
            textout_ex(page, arial_14, "ce jeu exceptionnel", 280+50, depart_texte-police+11*vitesse+60, makecol(255, 255, 0), -1);
        }
        else if (police <= 20*vitesse)
        {
            textout_ex(page, arial_8, "creerent un jeu legendaire", 250+80, depart_texte-police+9*vitesse+50, makecol(255, 255, 0), -1);
            textout_ex(page, arial_10, "ainsi naquit", 300+70, depart_texte-police+10*vitesse+55, makecol(255, 255, 0), -1);
            textout_ex(page, arial_12, "ce jeu exceptionnel", 280+60, depart_texte-police+11*vitesse+60, makecol(255, 255, 0), -1);
        }
        else if (police <= 21*vitesse)
        {
            textout_ex(page, arial_8, "ainsi naquit", 300+80, depart_texte-police+10*vitesse+55, makecol(255, 255, 0), -1);
            textout_ex(page, arial_10, "ce jeu exceptionnel", 280+70, depart_texte-police+11*vitesse+60, makecol(255, 255, 0), -1);
        }
        else if (police <= 22*vitesse)
        {
            textout_ex(page, arial_8, "ce jeu exceptionnel", 280+80, depart_texte-police+11*vitesse+60, makecol(255, 255, 0), -1);
        }
        else if (police == 26*vitesse)
        {
            police = 0;
        }
        police++;




        return police;
}

/** pour les attaques **/

void afficheSouris_attaque(BITMAP* buffer,t_map carte, int zoneAttaque[20][16])
{
    /* Affiche un carré blanc a la position de la souris (si la souris se trouve dans la zone d'attaque)
    Prend en parametre la bitmap d'affichage, la carte et la zone de deplacement
    Ne renvoie rien */


    int i=0,j=0;
    int couleur_case=makecol(255,0,0);
    if(position_souris_colonne()!=-1 && position_souris_ligne()!=-1)
    {
        i= position_souris_colonne();
        j= position_souris_ligne();
        if(zoneAttaque[i][j]==1)
            rectfill(buffer,carte.tab_coordonnes[i][j].position_pixel_x+5, carte.tab_coordonnes[i][j].position_pixel_y+5, carte.tab_coordonnes[i][j].position_pixel_x +32-5,carte.tab_coordonnes[i][j].position_pixel_y+32-5, couleur_case);
    }
}

void SurbrillanceAttaque(BITMAP* buffer,t_map carte, int zoneAttaque[20][16])
{
    /* Affiche en rouge les cases sur lesqeuelles le joueur peut attaquer (ici une attaque de zone)
    Prend en parametre la bitmap d'affichage, la carte, la zone de deplacement
    Ne renvoie rien */

    int couleur_case=makecol(255,127,0);
    for(int i=0; i<20;i++)
    {

        for(int j=0;j<16;j++)
        {
            if(zoneAttaque[i][j]==1)
            {
                rectfill(buffer,carte.tab_coordonnes[i][j].position_pixel_x+5, carte.tab_coordonnes[i][j].position_pixel_y+5, carte.tab_coordonnes[i][j].position_pixel_x +32-5,carte.tab_coordonnes[i][j].position_pixel_y+32-5, couleur_case);
            }
        }
    }
    afficheSouris_attaque(buffer,carte,zoneAttaque);
}















