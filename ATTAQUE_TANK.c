#include "HEADER.h"

/**  finie sans animation **/ //rajouter verif bouclier

void c_a_c_tank(t_joueur* tab_j,int i,BITMAP* buffer,t_map carte,int zoneAttaque[20][16],BITMAP* animation,int nb_joueur)
{
    /*attaque au corps a corps
    (i indice du joueur qui joue)*/

    int PA=5; //cout en point d'action
    int degat=420; //PV enlever a ladversaire
    int distance = 1;//distance d'attaque
    int j=joueur_sur_case_ou_pas(carte,zoneAttaque,tab_j,buffer,animation,nb_joueur); //indice du joueur attaqué (4 si ce n'est personne)

    if (action_possible(tab_j,i,PA))
    {
        CalculAttaque_zone(buffer,carte,tab_j[i].position_colonne,tab_j[i].position_ligne,zoneAttaque,distance);
        SurbrillanceAttaque(buffer,carte,zoneAttaque);
        if((j>=0) && (j<=3)) //verifier que l'on clique sur un joueur lors de lattaque avec la fonction dans attaque generale
        {
           if(!(tab_j[j].bouclier)) //si le joueur ne se protege pas avec un bouclier
            {
                tab_j[j].pv_actuel-=degat; //retire les pv au joueur attaqué
                tab_j[i].pa_actuel-=PA; //retire les PA au joueur qui joue
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

/** pas finie **/ //verifier quon ne le fait qu'une fois par tour car si on active cette fonction, on fait indifiniment son action associé
void roulement(t_joueur* tab_j,int i,BITMAP* page)
{
    /*permet pendant un tour (le tour suivant) d'augmenter les PM du tank à 4*/

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

/** pas finie **/ //verifier quon ne le fait qu'une fois par tour car si on active cette fonction, on fait indifiniment son action associé
void bouclier(t_joueur* tab_j,int i,BITMAP* page)
{
    int PA=-6; //cout en point d'action

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

/** pas finie **/ //integrer la gestion de distance lineaire
void lance_flammes(t_joueur* tab_j,int i,BITMAP* buffer,t_map carte,int zoneAttaque[20][16],BITMAP* animation,int nb_joueur)
{
    int PA=2; //cout en point d'action
    int degat=60; //PV enlever a ladversaire
    int distance=2; //distance dattaque
    int j=joueur_sur_case_ou_pas(carte,zoneAttaque,tab_j,buffer,animation,nb_joueur); //indice du joueur attaqué (4 si ce n'est personne)

    if (action_possible(tab_j,i,PA))
    {
        CalculAttaque_ligne(buffer,carte,tab_j[i].position_colonne,tab_j[i].position_ligne,zoneAttaque,distance);
        SurbrillanceAttaque(buffer,carte,zoneAttaque);
        if((j>=0) && (j<=3)) //verifier que l'on clique sur un joueur lors de lattaque avec la fonction dans attaque generale
        {
            if(!(tab_j[j].bouclier)) //si le joueur ne se protege pas avec un bouclier
            {
                tab_j[j].pv_actuel-=degat; //retire les pv au joueur attaqué
                tab_j[j].en_feu=true; //le met en feu (perds 20pv en plus par tour)
                tab_j[i].pa_actuel-=PA; //retire les PA au joueur qui joue
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

