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

void AnimationDeplacement(BITMAP* buffer, BITMAP* soldat, t_map carte, int x_initial, int y_initial, t_joueur joueurActuel, coords chemin[], int PM)
{
    /* Permet d'animer le deplacement
    Prend en parametre la bitmap d'image, le skin du joueur, la carte, les coordonnées initial, le joueur qui joue, le chemin, les points de mouvement
    Ne renvoie rien */

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
            x=32;

            while(x1<x2)                                                                                                                                   //Aller a droite
            {
                blit(carte.fond_map,buffer,0,0, (SCREEN_W-carte.fond_map->w)/2, (SCREEN_H-carte.fond_map->h)/2, carte.fond_map->w, carte.fond_map->h);     //AfficheTout
                affichage_grille(buffer);
                masked_blit(soldat,buffer, x, 14, x1,y1-30, 32,64);
                x=x+96;
                if (x>=340)
                    x=32;
                x1+=8;
                blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                rest(100);
                clear(buffer);

            }
            while(y1>y2)                                                                                                                                    //Monter
            {
                blit(carte.fond_map,buffer,0,0, (SCREEN_W-carte.fond_map->w)/2, (SCREEN_H-carte.fond_map->h)/2, carte.fond_map->w, carte.fond_map->h);     //AfficheTout
                affichage_grille(buffer);
                masked_blit(soldat,buffer, x, 300, x1,y1-30, 32,64);
                x=x+96;
                if (x>=340)
                    x=32;
                y1-=8;
                blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                rest(100);
                clear(buffer);

            }
            while(x1>x2)                                                                                                                                   //Aller a gauche
            {
                blit(carte.fond_map,buffer,0,0, (SCREEN_W-carte.fond_map->w)/2, (SCREEN_H-carte.fond_map->h)/2, carte.fond_map->w, carte.fond_map->h);     //AfficheTout
                affichage_grille(buffer);
                masked_blit(soldat,buffer, x, 108, x1,y1-30, 32,64);
                x=x+96;
                if (x>=340)
                    x=32;
                x1-=8;
                blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                rest(100);
                clear(buffer);

            }
            while(y1<y2)                                                                                                                                    //Monter
            {
                blit(carte.fond_map,buffer,0,0, (SCREEN_W-carte.fond_map->w)/2, (SCREEN_H-carte.fond_map->h)/2, carte.fond_map->w, carte.fond_map->h);     //AfficheTout
                affichage_grille(buffer);
                masked_blit(soldat,buffer, x, 207, x1,y1-30, 32,64);
                x=x+96;
                if (x>=340)
                    x=32;
                y1+=8;
                blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                rest(100);
                clear(buffer);

            }



        }

}































