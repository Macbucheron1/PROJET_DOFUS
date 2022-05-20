#include "HEADER.h"

/** finie sans animation **/
void c_a_c_guerrier(t_joueur* tab_j,int i,BITMAP* buffer,t_map carte,int zoneAttaque[20][16],BITMAP* animation,int nb_joueur,BITMAP* soldat, int respiration)
{
    /*attaque au corps a corps
    (i indice du joueur qui joue)*/


    int PA=3; //cout en point d'action
    int degat=200; //PV enlever a ladversaire
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
                affichage_degat_soin(tab_j,j,buffer,degat,soldat,carte,nb_joueur,1, respiration);
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

void lancer_grenade_thermique_guerrier(t_joueur* tab_j,int i,BITMAP* buffer,t_map carte,int zoneAttaque[20][16],BITMAP* animation,int nb_joueur,BITMAP* soldat)
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
                affichage_degat_soin(tab_j,j,buffer,degat,soldat,carte,nb_joueur,1, respiration);
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

/** copier lancer de grenade thermique comme pr archer (l'adapter un peu) **/
/** copier soin mage (l'adapter un peu car limiter utilisation) **/
/** copier tir lourd (ladapter en PA et degat) **/
/** copier tir basique (ladapter en PA et degat) **/
