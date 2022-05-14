#include "HEADER.h"

/** finie sans animation **/

void c_a_c_archer(t_joueur* tab_j,int i,BITMAP* buffer,t_map carte,int zoneAttaque[20][16],BITMAP* animation,int nb_joueur)
{
    /*attaque au corps a corps
    (i indice du joueur qui joue)*/

    int PA=2; //cout en point d'action
    int degat=80; //PV enlever a ladversaire
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

/** finie sans animation **/

void lancer_grenade_thermique_archer(t_joueur* tab_j,int i,BITMAP* buffer,t_map carte,int zoneAttaque[20][16],BITMAP* animation,int nb_joueur)
{
    /*attaque a distance de l'archer (attaque de zone)
    (i indice du joueur qui joue)*/

    int PA=4; //cout en point d'action
    int degat=180; //PV enlever a ladversaire
    int distance=4; //distance d'attaque
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

/** pas finie **/ //integrer la gestion de distance lineaire
void tir_lourd_archer(t_joueur* tab_j,int i,BITMAP* buffer,t_map carte,int zoneAttaque[20][16],BITMAP* animation,int nb_joueur)
{
    /*attaque a distance qui inflige bcp de degat (courte distance)*/

    int PA=6; //cout en point d'action
    int degat=300; //PV enlever a ladversaire
    int distance=3; //distance d'attaque
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

/** pas finie **/ //integrer la gestion de distance lineaire
void tir_basique_archer(t_joueur* tab_j,int i,BITMAP* buffer,t_map carte,int zoneAttaque[20][16],BITMAP* animation,int nb_joueur)
{
    /*attaque a distance qui inflige de leger de degat (moyenne distance)*/

    int PA=2; //cout en point d'action
    int degat=80; //PV enlever a ladversaire
    int distance=5; //distance d'attaque
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

/** pas finie **/ //integrer la gestion de distance lineaire
void tir_de_precision(t_joueur* tab_j,int i,BITMAP* buffer,t_map carte,int zoneAttaque[20][16],BITMAP* animation,int nb_joueur)
{
    /*attaque a distance qui inflige de moyen de degat (longue distance)*/
    int PA=4; //cout en point d'action
    int degat=150; //PV enlever a ladversaire
    int distance=7; //distance d'attaque
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
