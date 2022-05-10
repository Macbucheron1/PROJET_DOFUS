#include "HEADER.h"

/** pas finie **/ //integrer la gestion de distance avant la verification de PA + quoi faire si action pas possible
void c_a_c_tank(t_joueur* tab_j,int i,int j) //attaque au corps a corps (i indice du joueur qui joue ; j celui attaqué)
{
    int PA=5; //cout en point d'action
    int degat=420; //PV enlever a ladversaire

    if (action_possible(tab_j,i,PA))
    {
        //il faudrait recuperer l'indice du joueur (au clic ptetre) que l'on attaque pour lui enlever les pv
        //de plus il faut verifier si l'attaque est possible en terme de distance
        tab_j[j].pv_actuel-=degat;
        tab_j[i].pa_actuel-=PA;
    }
    else
    {
        //si c les PA afficher un texte : "vous n'avez pas assez de PA pr realiser l'action"
        //si c la distance
    }
}

/** pas finie **/ //gestion booleen (dans attaque generale)
void roulement(t_joueur* tab_j,int i,BITMAP* page)//permet pendant un tour (le tour suivant) d'augmenter les PM du tank à 4
{
    int PA=4; //cout en point d'action

    if (action_possible(tab_j,i,PA))
    {
        tab_j[i].PM_roule=true;
        tab_j[i].pa_actuel-=PA;
    }
    else
    {
        affichage_action_impossible(page); //pas assez de PA -> msg
    }
}

/** pas finie **/ //gestion booleen + nb de tour avc le bouclier (dans attaque generale)
void bouclier(t_joueur* tab_j,int i,BITMAP* page)
{
    int PA=6; //cout en point d'action

    if (action_possible(tab_j,i,PA))
    {
        tab_j[i].bouclier=true;
        tab_j[i].pa_actuel-=PA;
    }
    else
    {
        affichage_action_impossible(page); //pas assez de PA -> msg
    }
}

/** copier tir basique (ladapter en PA et degat) **/

/** pas finie **/ //integrer la gestion de distance avant la verification de PA + quoi faire si action pas possible
void lance_flammes(t_joueur* tab_j,int i,int j,BITMAP* page)
{
    int PA=2; //cout en point d'action
    int degat=60; //PV enlever a ladversaire

    if (action_possible(tab_j,i,PA))
    {
        tab_j[j].pv_actuel-=degat;
        tab_j[j].en_feu=true;
        tab_j[i].pa_actuel-=PA;
    }
    else
    {
        affichage_action_impossible(page); //pas assez de PA -> msg
    }
}

