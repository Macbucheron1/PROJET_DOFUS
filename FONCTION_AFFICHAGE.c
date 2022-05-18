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

void montre_curseur(BITMAP* page, BITMAP* curseur)
{
    /* Permet d'afficher un curseur personnalisé
    Prend en parametre la bitmap sur laquel affiché le curseur
    Ne renvoie rien*/
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

void AnimationDeplacement(BITMAP* buffer, BITMAP* soldat, t_map carte, int x_initial, int y_initial, int indiceActuel, coords chemin[], int PM, int nbJoueurs, t_joueur Joueurs[],BITMAP* fond_menu,BITMAP* avatar[],time_t temps1,time_t temps2, int affiche_on, int affiche_grille)
{
    /* Permet d'animer le deplacement
    Prend en parametre la bitmap d'image, le skin du joueur, la carte, les coordonnées initial, le joueur qui joue, le chemin, les points de mouvement
    Ne renvoie rien */
    AnimationClasse1(buffer, soldat, carte, x_initial, y_initial, indiceActuel, chemin, PM, nbJoueurs, Joueurs,fond_menu,avatar,temps1,temps2, affiche_on, affiche_grille);
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


void animation_decor_menu(BITMAP* soldat, t_acteur mesActeurs[], int* delay, t_decor* visuel_menu, BITMAP* tableau_map[], unsigned int* temps)
{
    /* Anime le decor du menu
    Prend en parametre la bitmap des personnages, le tableau d'acteurs, le delay, le decor du menu, le tableau de bitmap de map et le temps
    Ne Renvoie rien*/
        blit(tableau_map[2], visuel_menu->visuel, 0, 0, 2400, 0, 800, 600);
        blit(tableau_map[0], visuel_menu->visuel, 0, 0, 1600, 0, 800, 600);
        blit(tableau_map[1], visuel_menu->visuel, 0, 0, 800, 0, 800, 600);
        blit(tableau_map[2], visuel_menu->visuel, 0, 0, 0, 0, 800, 600);
        masked_blit(mesActeurs[0].skin, visuel_menu->visuel, mesActeurs[0].position_bitmap.x, mesActeurs[0].position_bitmap.y, mesActeurs[0].position.x, mesActeurs[0].position.y, 32,64);
        *delay = (*delay+1)%10;


        if (clock()-(*temps) <= 6000)
            animation_vers_gauche(*delay, &mesActeurs[0], 800, 1);
        else if (clock()-(*temps)<6030)
        {
            mesActeurs[0].position_bitmap.y = mesActeurs[0].debut_bitmap.base_bas.y;
            mesActeurs[0].position_bitmap.x = mesActeurs[0].debut_bitmap.base_bas.x;
            animation_vers_bas(*delay, &mesActeurs[0], 10, 500);
        }
        else if (clock()-(*temps)<7710)
            animation_vers_bas(*delay, &mesActeurs[0], 1, 800);
        else if (clock()-(*temps)<7760)
        {
            mesActeurs[0].position_bitmap.y = mesActeurs[0].debut_bitmap.base_gauche.y;
            mesActeurs[0].position_bitmap.x = mesActeurs[0].debut_bitmap.base_gauche.x;
            animation_vers_gauche(*delay, &mesActeurs[0], 800, 1);
        }
        else if (clock()-(*temps)<16000)
            animation_vers_gauche(*delay, &mesActeurs[0], 800, 1);
        else if (clock()-(*temps)<25000)
        {
            mesActeurs[0].respiration+=1;
            mesActeurs[0].position_bitmap.y = 14;
            if (mesActeurs[0].respiration <= 80)
                mesActeurs[0].position_bitmap.x = 409;
            else if (mesActeurs[0].respiration<=120)
                mesActeurs[0].position_bitmap.x = 409+94;
            else
                mesActeurs[0].respiration = 0;
        }
        else
        {
            *temps = clock();
            mesActeurs[0].position.y = 150;
            mesActeurs[0].position.x = 800;
            mesActeurs[0].position_bitmap.y = mesActeurs[0].debut_bitmap.base_gauche.y;
            mesActeurs[0].position_bitmap.x = mesActeurs[0].debut_bitmap.base_gauche.x;
        }

/*
        if (animation_vers_gauche(*delay, &mesActeurs[0], 800, 700) == 1)
        {
            mesActeurs[0].position_bitmap.y = mesActeurs[0].debut_bitmap.base_droite.y;
            mesActeurs[0].position_bitmap.x = mesActeurs[0].debut_bitmap.base_droite.x;
            animation_vers_droite(*delay, &mesActeurs[0], 700, 800);
        }*/

        if (visuel_menu->position_x >= 2399)
        {
            visuel_menu->position_x = 1;
        }
        visuel_menu->position_x += visuel_menu->avancement_x;
}



int animation_vers_gauche(int delay, t_acteur* monActeur, int position_debut_x, int position_final_x)
{
    /* Anime le joueur vers le gauche
    Prend en parametre le delay d'animation, un pointeur sur l'acteur, la position du debut et la position de fin
    Renvoie 0 si animation pas fini
    Renvoie 1 si animation fini */
    if (delay == 1)
    {
        if (monActeur->position.x>position_final_x)
        {
            monActeur->position_bitmap.x = monActeur->position_bitmap.x + monActeur->deplacement_bitmap.x;
            if (monActeur->position_bitmap.x >= monActeur->fin_bitmap.base_gauche.x)
                monActeur->position_bitmap.x = monActeur->debut_bitmap.base_gauche.x;
            monActeur->position.x -= monActeur->deplacement.x;
        }
        else
            return 1;
    }
    return 0;
}

int animation_vers_droite(int delay, t_acteur* monActeur, int position_debut_x, int position_final_x)
{
    /* Anime le joueur vers le droite
    Prend en parametre le delay d'animation, un pointeur sur l'acteur, la position du debut et la position de fin
    Renvoie 0 si animation pas fini
    Renvoie 1 si animation fini */
    if (delay == 1)
    {
        if (monActeur->position.x<position_final_x)
        {
            monActeur->position_bitmap.x = monActeur->position_bitmap.x + monActeur->deplacement_bitmap.x;
            if (monActeur->position_bitmap.x >= monActeur->fin_bitmap.base_droite.x)
                monActeur->position_bitmap.x = monActeur->debut_bitmap.base_droite.x;
            monActeur->position.x += monActeur->deplacement.x;
        }
        else
            return 1;
    }
    return 0;
}

int animation_vers_bas(int delay, t_acteur* monActeur, int position_debut_y, int position_final_y)
{
    /* Anime le joueur vers le bas
    Prend en parametre le delay d'animation, un pointeur sur l'acteur, la position du debut et la position de fin
    Renvoie 0 si animation pas fini
    Renvoie 1 si animation fini */
    if (delay == 1)
    {
        if (monActeur->position.y<position_final_y)
        {
            monActeur->position_bitmap.x = monActeur->position_bitmap.x + monActeur->deplacement_bitmap.x;
            if (monActeur->position_bitmap.x >= monActeur->fin_bitmap.base_bas.x)
                monActeur->position_bitmap.x = monActeur->debut_bitmap.base_bas.x;
            monActeur->position.y += monActeur->deplacement.y;
        }
        else
            return 1;
    }
    return 0;
}

int animation_vers_haut(int delay, t_acteur* monActeur, int position_debut_y, int position_final_y)
{
    /* Anime le joueur vers le haut
    Prend en parametre le delay d'animation, un pointeur sur l'acteur, la position du debut et la position de fin
    Renvoie 0 si animation pas fini
    Renvoie 1 si animation fini */
    if (delay == 1)
    {
        if (monActeur->position.y>position_final_y)
        {
            monActeur->position_bitmap.x = monActeur->position_bitmap.x + monActeur->deplacement_bitmap.x;
            if (monActeur->position_bitmap.x >= monActeur->fin_bitmap.base_haut.x)
                monActeur->position_bitmap.x = monActeur->debut_bitmap.base_haut.x;
            monActeur->position.y -= monActeur->deplacement.y;
        }
        else
            return 1;
    }
    return 0;
}

void affichage_en_jeu(BITMAP* buffer,BITMAP* fond_menu, BITMAP* avatar[])
{
    int i;
    draw_sprite(buffer, avatar[0],3,90);
    draw_sprite(buffer, avatar[1],10,20);
    draw_sprite(buffer, avatar[2],33,90);
    draw_sprite(buffer, avatar[3],63,90);


    for(i = 0; i<3; i++)
    {
        rectfill(buffer, 750+2*i, 10+2*i, 790-2*i, 50-2*i, makecol(190-15*i,190-15*i,190-15*i));
        //rectfill(buffer, 18+2*i, 20+2*i, 78-2*i, 80-2*i, makecol(190-15*i,190-15*i,190-15*i));
    }
    for(i = 0; i<3; i++)
    {
        hline(buffer, 760, 22+8*i,780,makecol(96,96,96));
    }
    for(i = 0;i<5;i++)
    {
        for(int j=0;j<3;j++)
        {
            rectfill(buffer, 100+108*i+2*j, 555+2*j, 200+108*i-2*j, 585-2*j, makecol(190-15*j,190-15*j,190-15*j));
        }
    }
    for(int j=0;j<3;j++)
    {
        rectfill(buffer, 100+108*5+2*j, 555+2*j, 200+108*5-2*j, 585-2*j, makecol(240-15*j,0 ,0));
    }
    textout_ex(buffer, font, "Fin de tour", 100+108*5+2*3, 555+2*5, makecol(10, 10, 10), -1);
    for(i = 0; i<3;i++)
    {
        for(int j = 0; j<3;j++)
        {
            //rectfill(buffer, 10+26*i+2*j, 180+2*j, 35+26*i-2*j, 205-2*j, makecol(190-15*j,190-15*j,190-15*j));
        }
    }
}


void AffichePerso(BITMAP* buffer, BITMAP* soldat, t_map carte, int nbJoueurs, t_joueur Joueurs[], int exception){       //Affiche tous les Perso sauf l'indice exception
    for(int i=0; i<nbJoueurs;i++)
            if(i!=exception)
               {
                    masked_blit(Joueurs[i].skin, buffer, Joueurs[i].position_bitmap.x+48, Joueurs[i].position_bitmap.y+128, carte.tab_coordonnes[Joueurs[i].position_colonne][Joueurs[i].position_ligne].position_pixel_x-8, carte.tab_coordonnes[Joueurs[i].position_colonne][Joueurs[i].position_ligne].position_pixel_y-40, 48,64);
               }
}

void AnimationClasse1(BITMAP* buffer, BITMAP* soldat, t_map carte, int x_initial, int y_initial, int indiceActuel, coords chemin[], int PM, int nbJoueurs, t_joueur Joueurs[],BITMAP* fond_menu,BITMAP* avatar[],time_t temps1,time_t temps2, int affiche_on, int affiche_grille)
{
    int x1 = carte.tab_coordonnes[x_initial][y_initial].position_pixel_x;    //On recupere les coordonnées en pixels de la case initial
    int y1 = carte.tab_coordonnes[x_initial][y_initial].position_pixel_y;

    int x2;
    int y2;

    int x;
    rest(500);
        for(int i=0; i<PM;i++)
        {
            x2 = carte.tab_coordonnes[chemin[i].x][chemin[i].y].position_pixel_x;    //On recupere les coordonnées en pixels de la case suivante
            y2 = carte.tab_coordonnes[chemin[i].x][chemin[i].y].position_pixel_y;
            x=0;

            while(x1<x2)                                                                                                                                   //Aller a droite
            {
                AfficheTout(buffer, soldat, carte, nbJoueurs, Joueurs,fond_menu,avatar,temps1,temps2, affiche_on, affiche_grille);
                AffichePerso(buffer, soldat, carte, nbJoueurs, Joueurs, indiceActuel);
                masked_blit(soldat, buffer, Joueurs[indiceActuel].position_bitmap.x+x, Joueurs[indiceActuel].position_bitmap.y+64, x1-2, y1-40, 48, 64);
                x=x+48;
                if (x>96)
                    x=0;
                x1+=8;
                blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                rest(100);
                clear(buffer);

            }
            while(y1>y2)                                                                                                                                    //Monter
            {
                AfficheTout(buffer, soldat, carte, nbJoueurs, Joueurs,fond_menu,avatar,temps1,temps2, affiche_on, affiche_grille);
                AffichePerso(buffer, soldat, carte, nbJoueurs, Joueurs, indiceActuel);
                masked_blit(soldat,buffer, Joueurs[indiceActuel].position_bitmap.x+x, Joueurs[indiceActuel].position_bitmap.y, x1-8,y1-40, 48,64);
                x=x+48;
                if (x>96)
                    x=0;
                y1-=8;
                blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                rest(100);
                clear(buffer);

            }
            while(x1>x2)                                                                                                                                   //Aller a gauche
            {
                AfficheTout(buffer, soldat, carte, nbJoueurs, Joueurs,fond_menu,avatar,temps1,temps2, affiche_on, affiche_grille);
                AffichePerso(buffer, soldat, carte, nbJoueurs, Joueurs, indiceActuel);
                masked_blit(soldat,buffer,Joueurs[indiceActuel].position_bitmap.x+x, Joueurs[indiceActuel].position_bitmap.y+192, x1-2,y1-40, 48,64);
                x=x+48;
                if (x>96)
                    x=0;
                x1-=8;
                blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                rest(100);
                clear(buffer);

            }
            while(y1<y2)                                                                                                                                    //Descendre
            {
                AfficheTout(buffer, soldat, carte, nbJoueurs, Joueurs,fond_menu,avatar,temps1,temps2, affiche_on, affiche_grille);
                AffichePerso(buffer, soldat, carte, nbJoueurs, Joueurs, indiceActuel);
                masked_blit(soldat,buffer,Joueurs[indiceActuel].position_bitmap.x+x, Joueurs[indiceActuel].position_bitmap.y+128, x1-8,y1-40, 48,64);
                x=x+48;
                if (x>96)
                    x=0;
                y1+=8;
                blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                rest(100);
                clear(buffer);

            }



        }
    blit(carte.fond_map,buffer,0,0, (SCREEN_W-carte.fond_map->w)/2, (SCREEN_H-carte.fond_map->h)/2, carte.fond_map->w, carte.fond_map->h);     //AfficheTout
}

void AnimationClasse2(BITMAP* buffer, BITMAP* soldat, t_map carte, int x_initial, int y_initial, int indiceActuel, coords chemin[], int PM, int nbJoueurs, t_joueur Joueurs[],BITMAP* fond_menu,BITMAP* avatar[],time_t temps1,time_t temps2, int affiche_on, int affiche_grille){
    int x1 = carte.tab_coordonnes[x_initial][y_initial].position_pixel_x;    //On recupere les coordonnées en pixels de la case initial
    int y1 = carte.tab_coordonnes[x_initial][y_initial].position_pixel_y;

    int x2;
    int y2;

    int x;
    x1+=8;
        for(int i=0; i<PM;i++)
        {
            x2 = carte.tab_coordonnes[chemin[i].x][chemin[i].y].position_pixel_x;    //On recupere les coordonnées en pixels de la case suivante
            y2 = carte.tab_coordonnes[chemin[i].x][chemin[i].y].position_pixel_y;
            x=630;

            while(x1<x2)                                                                                                                                   //Aller a droite
            {
                AfficheTout(buffer, soldat, carte, nbJoueurs, Joueurs,fond_menu,avatar,temps1,temps2, affiche_on, affiche_grille);
                AffichePerso(buffer, soldat, carte, nbJoueurs, Joueurs, indiceActuel);
                masked_blit(soldat,buffer, x, 7, x1,y1-30, 36,64);
                x=x+77;
                if (x>=890)
                    x=630;
                x1+=8;
                blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                rest(100);
                clear(buffer);

            }
            while(y1>y2)                                                                                                                                    //Monter
            {
                AfficheTout(buffer, soldat, carte, nbJoueurs, Joueurs,fond_menu,avatar,temps1,temps2, affiche_on, affiche_grille);
                AffichePerso(buffer, soldat, carte, nbJoueurs, Joueurs, indiceActuel);
                masked_blit(soldat,buffer, x, 247, x1,y1-30, 36,64);
                x=x+77;
                if (x>=890)
                    x=630;
                y1-=8;
                blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                rest(100);
                clear(buffer);

            }
            while(x1>x2)                                                                                                                                   //Aller a gauche
            {
                AfficheTout(buffer, soldat, carte, nbJoueurs, Joueurs,fond_menu,avatar,temps1,temps2, affiche_on, affiche_grille);
                AffichePerso(buffer, soldat, carte, nbJoueurs, Joueurs, indiceActuel);
                masked_blit(soldat,buffer, x, 85, x1,y1-30, 36,64);
                x=x+77;
                if (x>=890)
                    x=630;
                x1-=8;
                blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                rest(100);
                clear(buffer);

            }
            while(y1<y2)                                                                                                                                    //Descendre
            {
                AfficheTout(buffer, soldat, carte, nbJoueurs, Joueurs,fond_menu,avatar,temps1,temps2, affiche_on, affiche_grille);
                AffichePerso(buffer, soldat, carte, nbJoueurs, Joueurs, indiceActuel);
                masked_blit(soldat,buffer, x, 166, x1,y1-30, 36,64);
                x=x+77;
                if (x>=890)
                    x=630;
                y1+=8;
                blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                rest(100);
                clear(buffer);

            }



        }
    blit(carte.fond_map,buffer,0,0, (SCREEN_W-carte.fond_map->w)/2, (SCREEN_H-carte.fond_map->h)/2, carte.fond_map->w, carte.fond_map->h);     //AfficheTout
}

void AnimationClasse3(BITMAP* buffer, BITMAP* soldat, t_map carte, int x_initial, int y_initial, int indiceActuel, coords chemin[], int PM, int nbJoueurs, t_joueur Joueurs[],BITMAP *fond_menu, BITMAP* avatar[],time_t temps1, time_t temps2, int affiche_on, int affiche_grille){
    int x1 = carte.tab_coordonnes[x_initial][y_initial].position_pixel_x;    //On recupere les coordonnées en pixels de la case initial
    int y1 = carte.tab_coordonnes[x_initial][y_initial].position_pixel_y;

    int x2;
    int y2;

    int x;
    x1+=8;
        for(int i=0; i<PM;i++)
        {
            x2 = carte.tab_coordonnes[chemin[i].x][chemin[i].y].position_pixel_x;    //On recupere les coordonnées en pixels de la case suivante
            y2 = carte.tab_coordonnes[chemin[i].x][chemin[i].y].position_pixel_y;
            x=630;

            while(x1<x2)                                                                                                                                   //Aller a droite
            {
                AfficheTout(buffer, soldat, carte, nbJoueurs, Joueurs,fond_menu,avatar,temps1,temps2, affiche_on, affiche_grille);
                AffichePerso(buffer, soldat, carte, nbJoueurs, Joueurs, indiceActuel);
                masked_blit(soldat,buffer, x, 417, x1,y1-30, 33,64);
                x=x+75;
                if (x>=870)
                    x=630;
                x1+=8;
                blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                rest(100);
                clear(buffer);

            }
            while(y1>y2)                                                                                                                                    //Monter
            {
                AfficheTout(buffer, soldat, carte, nbJoueurs, Joueurs,fond_menu,avatar,temps1,temps2, affiche_on, affiche_grille);
                AffichePerso(buffer, soldat, carte, nbJoueurs, Joueurs, indiceActuel);
                masked_blit(soldat,buffer, x, 566, x1,y1-30, 33,64);
                x=x+75;
                if (x>=870)
                    x=630;
                y1-=8;
                blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                rest(100);
                clear(buffer);

            }
            while(x1>x2)                                                                                                                                   //Aller a gauche
            {
                AfficheTout(buffer, soldat, carte, nbJoueurs, Joueurs,fond_menu,avatar,temps1,temps2, affiche_on, affiche_grille);
                AffichePerso(buffer, soldat, carte, nbJoueurs, Joueurs, indiceActuel);
                masked_blit(soldat,buffer, x, 340, x1,y1-30, 33,64);
                x=x+75;
                if (x>=870)
                    x=630;
                x1-=8;
                blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                rest(100);
                clear(buffer);

            }
            while(y1<y2)                                                                                                                                    //Descendre
            {
                AfficheTout(buffer, soldat, carte, nbJoueurs, Joueurs,fond_menu,avatar,temps1,temps2, affiche_on, affiche_grille);
                AffichePerso(buffer, soldat, carte, nbJoueurs, Joueurs, indiceActuel);
                masked_blit(soldat,buffer, x, 492, x1,y1-30, 33,64);
                x=x+75;
                if (x>=870)
                    x=630;
                y1+=8;
                blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                rest(100);
                clear(buffer);

            }



        }
    blit(carte.fond_map,buffer,0,0, (SCREEN_W-carte.fond_map->w)/2, (SCREEN_H-carte.fond_map->h)/2, carte.fond_map->w, carte.fond_map->h);     //AfficheTout
    affichage_grille(buffer);
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


void AfficheTout(BITMAP* buffer, BITMAP* soldat, t_map carte, int nbJoueurs, t_joueur Joueurs[], BITMAP* fond_menu, BITMAP* avatar[], time_t temps1, time_t temps2, int affiche_son, int affiche_grille){
    blit(carte.fond_map,buffer,0,0, (SCREEN_W-carte.fond_map->w)/2, (SCREEN_H-carte.fond_map->h)/2, carte.fond_map->w, carte.fond_map->h);  //carte
   if (affiche_grille == 1)
        affichage_grille(buffer);   //grille
    rect(buffer,230, 5, 630,25,makecol(0,0,0));                 //Affichage de la barre de temps restant
    rectfill(buffer,232, 7, (temps2-temps1)*400/15000+232,23,makecol(0,255,0));

    affichage_en_jeu(buffer,fond_menu,avatar);

}












