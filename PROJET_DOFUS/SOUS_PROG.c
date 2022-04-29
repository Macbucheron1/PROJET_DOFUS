#include "HEADER.h"

void init_map(t_map* carte)
{
    /* Permet d'initialiser une map
    Prend en parametre la carte qu'on doit remplir
    Ne renvoie rien*/
    carte->fond_map = load_bitmap("fond_jeu.bmp",NULL);
    erreur_chargement_image(carte->fond_map);
    remplir_tab_coordonnes(carte);
    remplir_map_obstacle(carte);
}

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
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
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

//Calcule les zones sur lesqeuelles peut aller le perso et appelle les fonctions d'affichages
void CalculDeplacement(BITMAP* buffer, t_map carte, int x_soldat,int y_soldat, int zoneDeplacement[20][16], int PM_restant)
{


    int i,j,tmp;
    int x=x_soldat;
    int y=y_soldat-PM_restant;
    int continuer=1;
    int continuer1=1;
    coords chemin[3];

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
                if(!(i==PM_restant && j==PM_restant) && carte.map_obstacle[x][y]!=1 && CalculChemin(carte, x_soldat,y_soldat,x,y, 3,chemin)!=-1) // Verifie si la case est accessible
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
                    if(carte.map_obstacle[x][y]!=1 && CalculChemin(carte, x_soldat,y_soldat,x,y, 3,chemin)!=-1)
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

//Recupere dans la struct position, la position finale du deplacement, renvoie le nb de PM utilisés
int Deplacement(t_map carte, int zoneDeplacement[20][16], t_joueur* joueurActuel) //position du click
{
    int i=0,j=0;
    int PM_utilises=0;


    if(position_souris_colonne()!=-1 && position_souris_ligne()!=-1)                    //Si le curseur et sur la map
    {
        i= position_souris_colonne();
        j= position_souris_ligne();
        if(mouse_b && zoneDeplacement[i][j]==1)                                         //Si le joueur click sur une zone de deplacement
        {
            PM_utilises=abs(joueurActuel->position_colonne-position_souris_colonne())+ abs(joueurActuel->position_ligne-position_souris_ligne());   //Calcul du nb de PM utilisés et actualisation de la position du joueur
            joueurActuel->position_colonne=position_souris_colonne();
            joueurActuel->position_ligne=position_souris_ligne();
        }
    }

    return PM_utilises;
}

//Stock le chemin dans le tableau chemin si il est possible, sinon renvoie -1
int CalculChemin( t_map carte, int x1,int y1,int x2,int y2, int PM_restant,coords chemin[])
{
    int chemin1=1, chemin2=1;
    coords pos;
    int cpt=0;

    if(PM_restant>=2)
    {
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

    }
}



