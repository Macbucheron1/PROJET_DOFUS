#include "HEADER.h"

/** pas finie **/ //integrer la gestion de distance avant la verification de PA + quoi faire si action pas possible
void c_a_c_guerrier(t_joueur* tab_j,int i,int j) //attaque au corps a corps (i indice du joueur qui joue ; j celui attaqué)
{
    int PA=3; //cout en point d'action
    int degat=200; //PV enlever a ladversaire

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

/** copier lancer de grenade thermique comme pr archer (l'adapter un peu) **/
/** copier soin mage (l'adapter un peu car limiter utilisation) **/
/** copier tir lourd (ladapter en PA et degat) **/
/** copier tir basique (ladapter en PA et degat) **/
