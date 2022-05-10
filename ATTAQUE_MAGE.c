#include "HEADER.h"

/** pas finie **/ //integrer la gestion de distance avant la verification de PA + quoi faire si action pas possible

void c_a_c_mage(t_joueur* tab_j,int i,int j) //attaque au sabre laser au corps a corps (i indice du joueur qui joue ; j celui attaqué)
{
    int PA=4; //cout en point d'action
    int degat=250; //PV enlever a ladversaire

    if (action_possible(tab_j,i,PA))
    {
        //il faudrait recuperer l'indice du joueur (au clic ptetre) que l'on attaque pour lui enlever les pv
        //de plus il faut verifier si l'attaque est possible en terme de distance
        tab_j[j].pv_actuel-=degat; //enleve les pv a l'ennemi attaquer
        tab_j[i].pa_actuel-=PA; //enleve les PA utilisé par le joueur qui joue au tour courant
    }
    else
    {
        //si c les PA afficher un texte : "vous n'avez pas assez de PA pr realiser l'action"
        //si c la distance
    }
}

/** finie **/
void guerison_mage(t_joueur* tab_j,int i, BITMAP* page) //permet au mage de se soigner
{
    int PA=4; //cout en point d'action
    int pv_restaure=180; //PV ajouter au mage

    if (action_possible(tab_j,i,PA))
    {
        if ((tab_j[i].pv_actuel+pv_restaure)<tab_j[i].classe.pv_max) //verifie quon ne rend pas plus de pv que le nb de pv max autorisé pour cette classe
        {
            tab_j[i].pv_actuel+=pv_restaure;
        }
        else
        {
            tab_j[i].pv_actuel=tab_j[i].classe.pv_max; //si l'on arrive au max en restaurant les pv alors on bloque le nb de pv au pv max
        }
        tab_j[i].pa_actuel-=PA;
    }
    else
    {
        affichage_action_impossible(page); //pas assez de PA -> msg
    }
}

/** finie **/
void meditation_mage(t_joueur* tab_j,int i, BITMAP* page) //permet au mage de gagner des pm
{
    int PA=5; //cout en point d'action

    if (action_possible(tab_j,i,PA)&&(tab_j[i].pm_max_actu_mage)<=(tab_j[i].classe.pm_max)) //on verifie aussi si l'on a pas fait trop de meditation car le sort est limité
    {
        tab_j[i].pm_max_actu_mage+=1;
        tab_j[i].pa_actuel-=PA;
    }
    else
    {
        //pas encore reflechit a ca
        //ptetre afficher un texte : "vous n'avez pas assez de PA pr realiser l'action"
        // et si c pas a cause des pa mais du nb d'utilisation on dit "vous avez deja utiliser toutes vos mediation"
        //dans la fonction generale dattaque faudarait faire un truc d'affichage pour montrer que lattaque a trop ete utilisé
        if(!(action_possible(tab_j,i,PA)))
        {
            affichage_action_impossible(page);
        }
        else
        {
            affichage_action_impossible_nb(page);
        }
    }
}

/** pas finie **/ //integrer la gestion de distance avant la verification de PA + quoi faire si action pas possible
void lancer_sabre(t_joueur* tab_j,int i,int j) //attaque a distance du mage (attaque longiligne) (i indice du joueur qui joue ; j celui attaqué)
{
    int PA=2; //cout en point d'action
    int degat=70; //PV enlever a ladversaire
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
void etranglement(t_joueur* tab_j,int i,int j) //attaque a distance du mage (attaque zone) (i indice du joueur qui joue ; j celui attaqué)
{
    int PA=3; //cout en point d'action
    int degat=130; //PV enlever a ladversaire
    int distance=2; //distance d'attaque

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

