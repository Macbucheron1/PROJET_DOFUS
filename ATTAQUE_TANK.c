#include "HEADER.h"

/**  finie sans animation **/

void c_a_c_tank(t_joueur* tab_j,int i,BITMAP* buffer,t_map carte,int zoneAttaque[20][16],BITMAP* animation,int nb_joueur,BITMAP* soldat)
{
    /*attaque au corps a corps
    (i indice du joueur qui joue)*/

    int PA=5; //cout en point d'action
    int degat=420; //PV enlever a ladversaire
    int distance = 1;//distance d'attaque
    int j=joueur_sur_case_ou_pas(carte,zoneAttaque,tab_j,buffer,animation,nb_joueur); //indice du joueur attaqu� (4 si ce n'est personne)

    if (action_possible(tab_j,i,PA))
    {
        CalculAttaque_zone(buffer,carte,tab_j[i].position_colonne,tab_j[i].position_ligne,zoneAttaque,distance);
        SurbrillanceAttaque(buffer,carte,zoneAttaque);
        if((j>=0) && (j<=3)) //verifier que l'on clique sur un joueur lors de lattaque avec la fonction dans attaque generale
        {
           if(!(tab_j[j].bouclier)) //si le joueur ne se protege pas avec un bouclier
            {
                tab_j[j].pv_actuel-=degat; //retire les pv au joueur attaqu�
                tab_j[i].pa_actuel-=PA; //retire les PA au joueur qui joue
                affichage_degat_soin(tab_j,j,buffer,degat,soldat,carte,nb_joueur,1);
            }
            else
            {
                affichage_attaque_inefficace(buffer);
                tab_j[i].pa_actuel-=PA; //retire les PA au joueur qui joue
            }
        }
    }
    else
    {
        affichage_action_impossible(buffer);
    }
}

/**  finie sans animation **/

void roulement(t_joueur* tab_j,int i,BITMAP* page,int *quelle_attaque,t_map carte,int zoneAttaque[20][16],BITMAP* animation,int nb_joueur,BITMAP* soldat)
{
    /*permet pendant un tour (le tour suivant) d'augmenter les PM du tank � 4*/

    int PA=4; //cout en point d'action

    if (action_possible(tab_j,i,PA))
    {
        *quelle_attaque=0;
        tab_j[i].PM_roule=true;
        tab_j[i].pa_actuel-=PA;
        affichage_degat_soin(tab_j,i,page,2,soldat,carte,nb_joueur,3);
    }
    else
    {
        affichage_action_impossible(page); //pas assez de PA -> msg
    }
}

/**  finie sans animation **/

void bouclier(t_joueur* tab_j,int i,BITMAP* page,int *quelle_attaque,t_map carte,int zoneAttaque[20][16],BITMAP* animation,int nb_joueur,BITMAP* soldat)
{
    int PA=6; //cout en point d'action

    if (action_possible(tab_j,i,PA))
    {
        *quelle_attaque=0;
        tab_j[i].bouclier=true;
        tab_j[i].pa_actuel-=PA;
        affichage_degat_soin(tab_j,i,page,1,soldat,carte,nb_joueur,4);
    }
    else
    {
        affichage_action_impossible(page); //pas assez de PA -> msg
    }
}

/**  finie sans animation **/

void tir_basique_tank(t_joueur* tab_j,int i,BITMAP* buffer,t_map carte,int zoneAttaque[20][16],BITMAP* animation,int nb_joueur,BITMAP* soldat)
{
    /*attaque a distance qui inflige de leger de degat (moyenne distance)*/

    int PA=4+1; //cout en point d'action
    int degat=200; //PV enlever a ladversaire
    int distance=3; //distance d'attaque
    int j=joueur_sur_case_ou_pas(carte,zoneAttaque,tab_j,buffer,animation,nb_joueur); //indice du joueur attaqu� (4 si ce n'est personne)

    if (action_possible(tab_j,i,PA))
    {
        printf("%d/%d\n",  tab_j[i].position_colonne,tab_j[i].position_ligne);
        CalculAttaque_ligne(buffer,carte,tab_j[i].position_colonne,tab_j[i].position_ligne,zoneAttaque,distance,tab_j,nb_joueur);
        SurbrillanceAttaque(buffer,carte,zoneAttaque);
        if((j>=0) && (j<=3)) //verifier que l'on clique sur un joueur lors de lattaque avec la fonction dans attaque generale
        {
            if(!(tab_j[j].bouclier)) //si le joueur ne se protege pas avec un bouclier
            {
                tab_j[j].pv_actuel-=degat; //retire les pv au joueur attaqu�
                tab_j[i].pa_actuel-=PA; //retire les PA au joueur qui joue
                affichage_degat_soin(tab_j,j,buffer,degat,soldat,carte,nb_joueur,1);
            }
            else
            {
                affichage_attaque_inefficace(buffer);
                tab_j[i].pa_actuel-=PA; //retire les PA au joueur qui joue
            }
        }
    }
    else
    {
        affichage_action_impossible(buffer);
    }
}


/**  finie sans animation **/

void lance_flammes(t_joueur* tab_j,int i,BITMAP* buffer,t_map carte,int zoneAttaque[20][16],BITMAP* animation,int nb_joueur,BITMAP* soldat)
{
    int PA=2+1; //cout en point d'action
    int degat=60; //PV enlever a ladversaire
    int distance=4; //distance dattaque
    int j=joueur_sur_case_ou_pas(carte,zoneAttaque,tab_j,buffer,animation,nb_joueur); //indice du joueur attaqu� (4 si ce n'est personne)

    if (action_possible(tab_j,i,PA))
    {
        printf("%d/%d\n",  tab_j[i].position_colonne,tab_j[i].position_ligne);
        CalculAttaque_ligne(buffer,carte,tab_j[i].position_colonne,tab_j[i].position_ligne,zoneAttaque,distance,tab_j,nb_joueur);
        SurbrillanceAttaque(buffer,carte,zoneAttaque);
        if((j>=0) && (j<=3)) //verifier que l'on clique sur un joueur lors de lattaque avec la fonction dans attaque generale
        {
            if(!(tab_j[j].bouclier)) //si le joueur ne se protege pas avec un bouclier
            {
                tab_j[j].pv_actuel-=degat; //retire les pv au joueur attaqu�
                tab_j[j].en_feu=true; //le met en feu (perds 20pv en plus par tour)
                tab_j[i].pa_actuel-=PA; //retire les PA au joueur qui joue
                affichage_degat_soin(tab_j,i,buffer,degat,soldat,carte,nb_joueur,1);
            }
            else
            {
                affichage_attaque_inefficace(buffer);
                tab_j[i].pa_actuel-=PA; //retire les PA au joueur qui joue
            }
        }
    }
    else
    {
        affichage_action_impossible(buffer); //pas assez de PA -> msg
    }
}

