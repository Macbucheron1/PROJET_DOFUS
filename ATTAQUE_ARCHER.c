#include "HEADER.h"

/** pas finie **/ //integrer la gestion de distance avant la verification de PA + quoi faire si action pas possible
void c_a_c_archer(t_joueur* tab_j,int i,int j) //attaque au corps a corps (i indice du joueur qui joue ; j celui attaqué)
{
    int PA=2; //cout en point d'action
    int degat=80; //PV enlever a ladversaire

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

/** pas finie **/ //integrer la gestion de distance avant la verification de PA + quoi faire si action pas possible
void lancer_grenade_thermique(t_joueur* tab_j,int i,int j) //attaque a distance du mage (attaque de zone) (i indice du joueur qui joue ; j celui attaqué)
{
    int PA=4; //cout en point d'action
    int degat=180; //PV enlever a ladversaire
    int distance=4; //distance d'attaque

    if (action_possible(tab_j,i,PA))
    {
        //il faudrait recuperer l'indice du joueur (au clic ptetre) que l'on attaque pour lui enlever les pv
        //de plus il faut verifier si l'attaque est possible en terme de distance
        //et afficher les cases possible a attaquer
        tab_j[j].pv_actuel-=degat;
        tab_j[i].pa_actuel-=PA;
    }
    else
    {
        //si c les PA afficher un texte : "vous n'avez pas assez de PA pr realiser l'action"
        //si c la distance
    }
}

/** pas finie **/ //integrer la gestion de distance avant la verification de PA + quoi faire si action pas possible
void tir_lourd(t_joueur* tab_j,int i,int j) //attaque a distance qui inflige bcp de degat (courte distance)
{
    int PA=6; //cout en point d'action
    int degat=300; //PV enlever a ladversaire
    int distance=3; //distance d'attaque

    if (action_possible(tab_j,i,PA))
    {
        //il faudrait recuperer l'indice du joueur (au clic ptetre) que l'on attaque pour lui enlever les pv
        //de plus il faut verifier si l'attaque est possible en terme de distance
        //et afficher les cases possible a attaquer
        tab_j[j].pv_actuel-=degat;
        tab_j[i].pa_actuel-=PA;
    }
    else
    {
        //si c les PA afficher un texte : "vous n'avez pas assez de PA pr realiser l'action"
        //si c la distance
    }
}

/** pas finie **/ //integrer la gestion de distance avant la verification de PA + quoi faire si action pas possible
void tir_basique(t_joueur* tab_j,int i,int j) //attaque a distance qui inflige de leger de degat (moyenne distance)
{
    int PA=2; //cout en point d'action
    int degat=80; //PV enlever a ladversaire
    int distance=5; //distance d'attaque

    if (action_possible(tab_j,i,PA))
    {
        //il faudrait recuperer l'indice du joueur (au clic ptetre) que l'on attaque pour lui enlever les pv
        //de plus il faut verifier si l'attaque est possible en terme de distance
        //et afficher les cases possible a attaquer
        tab_j[j].pv_actuel-=degat;
        tab_j[i].pa_actuel-=PA;
    }
    else
    {
        //si c les PA afficher un texte : "vous n'avez pas assez de PA pr realiser l'action"
        //si c la distance
    }
}

/** pas finie **/ //integrer la gestion de distance avant la verification de PA + quoi faire si action pas possible
void tir_de_precision(t_joueur* tab_j,int i,int j) //attaque a distance qui inflige de moyen de degat (longue distance)
{
    int PA=4; //cout en point d'action
    int degat=150; //PV enlever a ladversaire
    int distance=7; //distance d'attaque

    if (action_possible(tab_j,i,PA))
    {
        //il faudrait recuperer l'indice du joueur (au clic ptetre) que l'on attaque pour lui enlever les pv
        //de plus il faut verifier si l'attaque est possible en terme de distance
        //et afficher les cases possible a attaquer
        tab_j[j].pv_actuel-=degat;
        tab_j[i].pa_actuel-=PA;
    }
    else
    {
        //si c les PA afficher un texte : "vous n'avez pas assez de PA pr realiser l'action"
        //si c la distance
    }
}
