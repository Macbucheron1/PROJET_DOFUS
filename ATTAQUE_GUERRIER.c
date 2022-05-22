#include "HEADER.h"

/** finie sans animation **/
void c_a_c_guerrier(t_joueur* tab_j,int i,BITMAP* buffer,t_map carte,int zoneAttaque[20][16],int nb_joueur,BITMAP* soldat, int respiration)
{
    /*attaque au corps a corps
    (i indice du joueur qui joue)*/
    int PA=3; //cout en point d'action
    int degat=200; //PV enlever a ladversaire
    int distance = 1;//distance d'attaque
    int j=joueur_sur_case_ou_pas(carte,zoneAttaque,tab_j,buffer,nb_joueur); //indice du joueur attaqué (4 si ce n'est personne)
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

void lancer_grenade_thermique_guerrier(t_joueur* tab_j,int i,BITMAP* buffer,t_map carte,int zoneAttaque[20][16],int nb_joueur,BITMAP* soldat, int respiration)
{
    /*attaque a distance de l'archer (attaque de zone)
    (i indice du joueur qui joue)*/

    int PA=4; //cout en point d'action
    int degat=180; //PV enlever a ladversaire
    int distance=4; //distance d'attaque
    int j=joueur_sur_case_ou_pas(carte,zoneAttaque,tab_j,buffer,nb_joueur); //indice du joueur attaqué (4 si ce n'est personne)

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

void guerison_guerrier(int *quelle_attaque,t_joueur* tab_j,int i,BITMAP* buffer,t_map carte,int zoneAttaque[20][16],int nb_joueur,BITMAP* soldat, int respiration)
{
    /*permet au mage de se soigner*/

    int PA=3; //cout en point d'action
    int pv_restaure=120; //PV ajouter au mage

    if ((action_possible(tab_j,i,PA))&&((tab_j[i].nb_bacta)<(tab_j[i].nb_bacta_max)))
    {
        *quelle_attaque=0;
        if ((tab_j[i].pv_actuel+pv_restaure)<tab_j[i].classe.pv_max) //verifie quon ne rend pas plus de pv que le nb de pv max autorisé pour cette classe
        {
            tab_j[i].pv_actuel+=pv_restaure;
            affichage_degat_soin(tab_j,i,buffer,pv_restaure,soldat,carte,nb_joueur,2, respiration);
        }
        else
        {
            tab_j[i].pv_actuel=tab_j[i].classe.pv_max; //si l'on arrive au max en restaurant les pv alors on bloque le nb de pv au pv max
            affichage_degat_soin(tab_j,i,buffer,pv_restaure,soldat,carte,nb_joueur,2, respiration);
        }
        tab_j[i].pa_actuel-=PA;
    }
    else
    {
       if(!(action_possible(tab_j,i,PA)))
        {
            affichage_action_impossible(buffer);
        }
        else
        {
            affichage_action_impossible_nb(buffer);
        }
    }
}

/** finie sans animation **/

void tir_lourd_guerrier(t_joueur* tab_j,int i,BITMAP* buffer,t_map carte,int zoneAttaque[20][16],int nb_joueur,BITMAP* soldat, int respiration)
{
    /*attaque a distance qui inflige bcp de degat (courte distance)*/

    int PA=4; //cout en point d'action
    int degat=250; //PV enlever a ladversaire
    int distance=3; //distance d'attaque
    int j=joueur_sur_case_ou_pas(carte,zoneAttaque,tab_j,buffer,nb_joueur); //indice du joueur attaqué (4 si ce n'est personne)

    if (action_possible(tab_j,i,PA))
    {
        CalculAttaque_ligne(buffer,carte,tab_j[i].position_colonne,tab_j[i].position_ligne,zoneAttaque,distance,tab_j,nb_joueur);
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

void tir_basique_guerrier(t_joueur* tab_j,int i,BITMAP* buffer,t_map carte,int zoneAttaque[20][16],int nb_joueur,BITMAP* soldat, int respiration)
{
    /*attaque a distance qui inflige de leger de degat (moyenne distance)*/

    int PA=2; //cout en point d'action
    int degat=80; //PV enlever a ladversaire
    int distance=5; //distance d'attaque
    int j=joueur_sur_case_ou_pas(carte,zoneAttaque,tab_j,buffer,nb_joueur); //indice du joueur attaqué (4 si ce n'est personne)

    if (action_possible(tab_j,i,PA))
    {
        CalculAttaque_ligne(buffer,carte,tab_j[i].position_colonne,tab_j[i].position_ligne,zoneAttaque,distance,tab_j,nb_joueur);
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
