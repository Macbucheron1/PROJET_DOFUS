#include "HEADER.h"

/* ------------------------------------- SOUS PROGRAMME -------------------------------------
    Les fontions présente dans ce fichier sont des fonctions de calcul. Elles sont utilitaire
*/


void remplir_tab_coordonnes(t_map* carte)
{
    /* Permet de remplir le tableau de coordonnées de la map
    Prend en parametre un pointeur sur la map
    Ne renvoie rien*/
    int x = 96;
    int y = 32;
    for (int colonne = 0; colonne < COLONNE_TABLEAU; colonne++)
    {
        for (int ligne = 0; ligne < LIGNE_TABLEAU; ligne++)
        {
            carte->tab_coordonnes[colonne][ligne].position_pixel_x = x + 32 * colonne;
            carte->tab_coordonnes[colonne][ligne].position_pixel_y = y + 32 * ligne;
        }
    }
}

void remplir_map_obstacle(t_map* carte)
{
    /* Permet de remplir la matrice contenant la valeur de chaque case. Avec chaque numero represantant soit un obstacle soit un element de decor
    Prend en parametre un pointeur sur une map
    Ne renvoie rien*/
    int terrain [COLONNE_TABLEAU][LIGNE_TABLEAU] = {
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 2, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
        { 0, 1, 1, 1, 0, 2, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0},
        { 0, 0, 2, 2, 0, 2, 2, 2, 1, 1, 1, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 2, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
        { 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1},
        { 2, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1},
        { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 2, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 2, 2, 2, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
        { 0, 2, 2, 2, 1, 1, 0, 0, 0, 0, 2, 1, 1, 0, 0, 0},
        { 0, 2, 2, 2, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        { 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
        { 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
    // On créée cette variable temporaire afin de pouvoir modifier facilement le tableau

    for (int colonne = 0; colonne < COLONNE_TABLEAU; colonne++)
    {
        for (int ligne = 0; ligne < LIGNE_TABLEAU; ligne++)
        {
            carte->map_obstacle[colonne][ligne] = terrain[colonne][ligne];
        }
    }
}

int position_souris_colonne(void)
{
/* Permet de savoir dans quelle colonne se situe la souris
    Ne prend pas de parametre
    Renvoie la colonne dans laquelle la souris se situe. -1 si la souris n'est pas dans une colonne*/
    int debut_tableau_x = 96;
    for (int colonne = 0; colonne < COLONNE_TABLEAU; colonne++)
    {
        if ((mouse_x >= debut_tableau_x + 32 * colonne) && (mouse_x <= debut_tableau_x + 32 * (colonne+1)))
        {
            return colonne;
        }
    }
    return -1;
}

int position_souris_ligne(void)
{
/* Permet de savoir dans quelle ligne se situe la souris
    Ne prend pas de parametre
    Renvoie la ligne dans laquelle la souris se situe. -1 si la souris n'est pas dans une ligne*/
    int debut_tab_y = 32;
    for (int ligne = 0; ligne < LIGNE_TABLEAU; ligne++)
    {
        if ((mouse_y >= debut_tab_y + 32 * ligne) && (mouse_y <= debut_tab_y + 32 * (ligne+1)))
        {
            return ligne;
        }
    }
    return -1;
}


void prepa_alleg(void)
{
    /* Lance alleg init et verifie qu'il fonctionne bien
    Ne prend de parametre
    Ne renvoie rien */
    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(24);
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}

void erreur_chargement_image(BITMAP* image)
{
    /*Vérification que l'image est bien chargée (dans le cas contraire image vaut NULL)
    TOUJOURS LE FAIRE CAR ON N'EST JAMAIS CERTAIN DE BIEN TROUVER L'IMAGE
    Prend en parametre l'image a testé
    Ne renvoie rien */
    if (!image)
    {
        allegro_message("pas pu trouver/charger mon_image.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}

//
void CalculDeplacement(BITMAP* buffer, t_map carte, int x_soldat,int y_soldat, int zoneDeplacement[20][16], int PM_restant) // a definir
{
    /* Calcule les zones sur lesqeuelles peut aller le perso et appelle les fonctions d'affichages
    Prend en parametre la bitmap d'affichage, la carte, la position du soldat, la zone de deplacement, les PM restants
    Ne renvoie rien */

    int i,j,tmp;
    int x=x_soldat;
    int y=y_soldat-PM_restant;
    int continuer=1;
    int continuer1=1;
    coords chemin[PM_restant];

    for(i=0; i<20;i++)                  //Iniitialisation du tableau avec des 0
    {
        for(j=0; j<16;j++)
        {
            zoneDeplacement[i][j]=0;
        }
    }
    //La zone de deplacement correspond a un losange que l'on sép   re en 2 parties (2 grandes boucles for)
    for(i=0;i<PM_restant+1 && continuer1;i++)
    {
        tmp=x;
        for(j=0; j<i*2+1;j++)
        {
            if(x>=0 && y>=0){
                if(!(i==PM_restant && j==PM_restant) && carte.map_obstacle[x][y]==0 && CalculChemin(carte, x_soldat,y_soldat,x,y, 3,chemin)!=-1) // Verifie si la case est accessible
                {

                    zoneDeplacement[x][y]=1;                                                           //Si c'est le cas, las case=1 dans le tableau
                }
            }
                if(x<19)
                    x=x+1;
                else
                {
                    break;
                }
        }

        x=tmp-1;
        if(y<15)
            y=y+1;
        else
            continuer=0;
    }
    x=x+2;
    if(continuer){
        for(i=0;i<PM_restant;i++)
        {
            tmp=x;
            for(j=0; j<2*PM_restant-(i*2+1);j++)
            {
                if(x>=0 && y>=0){
                    if(carte.map_obstacle[x][y]==0 && CalculChemin(carte, x_soldat,y_soldat,x,y, 3,chemin)!=-1)
                        zoneDeplacement[x][y]=1;
                }
                if(x<19)
                    x=x+1;
            }

            x=tmp+1;
            if(y<15)
                y=y+1;
        }
    }
    SurbrillanceDeplacement(buffer,carte,zoneDeplacement);
}

int Deplacement(t_map carte, int zoneDeplacement[20][16], t_joueur* joueurActuel, BITMAP* buffer, BITMAP* soldat ) //position du click
{
    /* Recupere dans la struct position, la position finale du deplacement
    Prend en parametre la carte, la zone de deplacement, le joueur actuel, la bitmap, et le skin du joueur
    renvoie le nb de PM utilisés */

    int i=0,j=0;
    int PM_utilises=0;


    if(position_souris_colonne()!=-1 && position_souris_ligne()!=-1)                    //Si le curseur et sur la map
    {
        i= position_souris_colonne();
        j= position_souris_ligne();
        int x_initial=joueurActuel->position_colonne;
        int y_initial=joueurActuel->position_ligne;

        if(mouse_b && zoneDeplacement[i][j]==1)                                         //Si le joueur click sur une zone de deplacement
        {
            PM_utilises=abs(joueurActuel->position_colonne-position_souris_colonne())+ abs(joueurActuel->position_ligne-position_souris_ligne());   //Calcul du nb de PM utilisés et actualisation de la position du joueur
            joueurActuel->position_colonne=position_souris_colonne();
            joueurActuel->position_ligne=position_souris_ligne();
            coords chemin[PM_utilises];
            CalculChemin(carte, x_initial,y_initial,joueurActuel->position_colonne,joueurActuel->position_ligne, PM_utilises,chemin);
            AnimationDeplacement(buffer,soldat,carte,x_initial,y_initial, *joueurActuel, chemin,PM_utilises);
        }
    }

    return PM_utilises;
}


int CalculChemin( t_map carte, int x1,int y1,int x2,int y2, int PM_restant,coords chemin[])
{
    /* Stock le chemin dans le tableau chemin si il est possible
    Prend en parametre la carte, les coordonnées de depart et d'arrivé, le nombre de PM disponible et un tableau de coordonnées
    Renvoie -1 si chemin imposible, 1 si non */
    int chemin1=1, chemin2=1;
    coords pos;
    int cpt=0;

        if( x1<=x2 && y1>y2)
        {
            for(int i=x1+1;i<=x2;i++)
            {
                if( carte.map_obstacle[i][y1]==1)
                    chemin1=0;
            }

            for(int i=y1-1;i>=y2 && chemin1!=0;i--)
            {
                if( carte.map_obstacle[x2][i]==1)
                    chemin1=0;
            }

            for(int i=y1-1;i>=y2 ;i--)
            {
                if( carte.map_obstacle[x1][i]==1)
                    chemin2=0;
            }

            for(int i=x1+1;i<=x2 && chemin2!=0;i++)
            {
                if( carte.map_obstacle[i][y2]==1)
                    chemin2=0;
            }
            if(chemin1)
                {
                    for(int i=x1+1;i<=x2;i++)
                    {
                        pos.x=i;
                        pos.y=y1;
                        chemin[cpt]=pos;
                        cpt++;
                    }
                    for(int i=y1-1;i>=y2;i--)
                    {
                        pos.x=x2;
                        pos.y=i;
                        chemin[cpt]=pos;
                        cpt++;
                    }
                    cpt=0;
                }
            else if(chemin2)
                {
                    for(int i=y1-1;i>=y2;i--)
                    {
                        pos.x=x1;
                        pos.y=i;
                        chemin[cpt]=pos;
                        cpt++;
                    }
                    for(int i=x1+1;i<=x2;i++)
                    {
                        pos.x=i;
                        pos.y=y2;
                        chemin[cpt]=pos;
                        cpt++;
                    }

                    cpt=0;
                }
            else
            {
                return -1;
            }

        }
        chemin1=1, chemin2=1;
        ////////////////////////////////////////////////////////////////////////////////////
        if( x1>x2 && y1>=y2)
        {
            for(int i=x1-1;i>=x2;i--)
            {
                if( carte.map_obstacle[i][y1]==1)
                    chemin1=0;
            }

            for(int i=y1-1;i>=y2 && chemin1!=0;i--)
            {
                if( carte.map_obstacle[x2][i]==1)
                    chemin1=0;
            }

            for(int i=y1-1;i>=y2 ;i--)
            {
                if( carte.map_obstacle[x1][i]==1)
                    chemin2=0;
            }

            for(int i=x1-1;i>=x2 && chemin2!=0;i--)
            {
                if( carte.map_obstacle[i][y2]==1)
                    chemin2=0;
            }

            if(chemin1)
                {
                    for(int i=x1-1;i>=x2;i--)
                    {
                        pos.x=i;
                        pos.y=y1;
                        chemin[cpt]=pos;
                        cpt++;
                    }
                    for(int i=y1-1;i>=y2;i--)
                    {
                        pos.x=x2;
                        pos.y=i;
                        chemin[cpt]=pos;
                        cpt++;
                    }
                    cpt=0;
                }
            else if(chemin2)
                {
                    for(int i=y1-1;i>=y2;i--)
                    {
                        pos.x=x1;
                        pos.y=i;
                        chemin[cpt]=pos;
                        cpt++;
                    }
                    for(int i=x1-1;i>=x2;i--)
                    {
                        pos.x=i;
                        pos.y=y2;
                        chemin[cpt]=pos;
                        cpt++;
                    }

                    cpt=0;
                }
            else
            {
                return -1;
            }

        }
        chemin1=1, chemin2=1;
        ////////////////////////////////////////////////////////////////////////
        if( x1>=x2 && y1<y2)
        {
            for(int i=x1-1;i>=x2;i--)
            {
                if( carte.map_obstacle[i][y1]==1)
                    chemin1=0;
            }

            for(int i=y1+1;i<=y2 && chemin1!=0;i++)
            {
                if( carte.map_obstacle[x2][i]==1)
                    chemin1=0;
            }

            for(int i=y1+1;i<=y2 ;i++)
            {
                if( carte.map_obstacle[x1][i]==1)
                    chemin2=0;
            }

            for(int i=x1-1;i>=x2 && chemin2!=0;i--)
            {
                if( carte.map_obstacle[i][y2]==1)
                    chemin2=0;
            }

            if(chemin1)
                {
                    for(int i=x1-1;i>=x2;i--)
                    {
                        pos.x=i;
                        pos.y=y1;
                        chemin[cpt]=pos;
                        cpt++;
                    }
                    for(int i=y1+1;i<=y2 ;i++)
                    {
                        pos.x=x2;
                        pos.y=i;
                        chemin[cpt]=pos;
                        cpt++;
                    }
                    cpt=0;
                }
            else if(chemin2)
                {
                    for(int i=y1+1;i<=y2 ;i++)
                    {
                        pos.x=x1;
                        pos.y=i;
                        chemin[cpt]=pos;
                        cpt++;
                    }
                    for(int i=x1-1;i>=x2;i--)
                    {
                        pos.x=i;
                        pos.y=y2;
                        chemin[cpt]=pos;
                        cpt++;
                    }

                    cpt=0;
                }
            else
            {
                return -1;
            }

        }
        chemin1=1, chemin2=1;
        ///////////////////////////////////////////////////////////////////////
        if( x1<x2 && y1<=y2)
        {
            for(int i=x1+1;i<=x2;i++)
            {
                if( carte.map_obstacle[i][y1]==1)
                    chemin1=0;
            }

            for(int i=y1+1;i<=y2 && chemin1!=0;i++)
            {
                if( carte.map_obstacle[x2][i]==1)
                    chemin1=0;
            }

            for(int i=y1+1;i<=y2 ;i++)
            {
                if( carte.map_obstacle[x1][i]==1)
                    chemin2=0;
            }

            for(int i=x1+1;i<=x2 && chemin2!=0;i++)
            {
                if( carte.map_obstacle[i][y2]==1)
                    chemin2=0;
            }

            if(chemin1)
                {

                    for(int i=x1+1;i<=x2;i++)
                    {
                        pos.x=i;
                        pos.y=y1;
                        chemin[cpt]=pos;
                        cpt++;
                    }
                    for(int i=y1+1;i<=y2 ;i++)
                    {
                        pos.x=x2;
                        pos.y=i;
                        chemin[cpt]=pos;
                        cpt++;
                    }
                    cpt=0;
                }
            else if(chemin2)
                {
                    for(int i=y1+1;i<=y2 ;i++)
                    {
                        pos.x=x1;
                        pos.y=i;
                        chemin[cpt]=pos;
                        cpt++;
                    }
                    for(int i=x1+1;i<=x2;i++)
                    {
                        pos.x=i;
                        pos.y=y2;
                        chemin[cpt]=pos;
                        cpt++;
                    }

                    cpt=0;
                }
            else
            {
                return -1;
            }

        }

    return 1; // Pour ne pas avoir de warning
}


int Star (t_star TabStar[LIMIT_STAR], int Stardelay, int i,BITMAP * backscreen) {
    int color5 = makecol(50,50,50);  //gris foncé
        if (Stardelay == 10) {

            i = 0;
            while (TabStar[i].posY != 1000) {
                i++;
            }
            TabStar[i].posX = 160 + rand()%500;
            TabStar[i].posY = 110;
            Stardelay--;
        }
        if (Stardelay != 10) {
            if (Stardelay < 6) {
                Stardelay = 10;
            }
            else {
                Stardelay--;
            }
        }
        for (int j=0 ; j<LIMIT_STAR ; j++) {

            if (TabStar[j].posY != 1000) {
                if (TabStar[j].posY > 490) {
                    TabStar[j].posY = 1000;
                }
                else {
                    TabStar[j].posY = TabStar[j].posY+20;   //vitesse
                    ellipsefill(backscreen,TabStar[j].posX+5,TabStar[j].posY,2,10,color5);
                }
            }
        }
    return Stardelay;
}













