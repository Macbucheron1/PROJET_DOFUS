#include "header.h"

/** fonctions dinitialisation **/

t_personnage init_classes(char* nom_classe,int num_classe,int p_action_max, int p_vie_max,int p_mvt_max,int nb_skin_total)
{
    t_personnage c;

    //definit en fonction des differentes classes

    c.numero_classe=num_classe;

    c.pa_max=p_action_max;
    c.pm_max=p_mvt_max;
    c.pv_max=p_vie_max;

    strcpy(c.nom_classe,nom_classe);

    //initialisation du tableau de bitmap qu'on utilisera pour les animation
    int i;
    char nomfichier[256]; //pour charger la bmp que nous voulons utiliser

    for (i=0; i<nb_skin_total; i++)
    {
        // sprintf permet de faire un printf dans une chaine
        sprintf(nomfichier,"img/%s%d.bmp",nom_classe,i+1); //exemple: img/mage1

        c.skin[i] = load_bitmap(nomfichier,NULL);
        if (!c.skin[i])
        {
            allegro_message("pas pu trouver %s",nomfichier);
            exit(EXIT_FAILURE);
        }
    }

    //on return la structure crée
    return c;
}

t_joueur init_joueur(char* nom_joueur,int num_joueur,t_personnage classe_choisie)
{
    t_joueur j;

    //variables propre a chaque joueur

    strcpy(j.nom_joueur,nom_joueur);
    j.numero_joueur=num_joueur;
    j.classe=classe_choisie;

    //variable utilise en jeu

    j.pa_actuel=j.classe.pa_max;

    if(j.classe.numero_classe==0) //pour les mages car leur PM max = 6 avc la mediatation
    {
        j.pm_actuel=3;
    }
    else
    {
        j.pm_actuel=j.classe.pm_max;
    }
    j.pv_actuel=j.classe.pv_max;

    j.pm_max_actu_mage=j.pm_actuel; //les pm de depart à l'initialisation
    //permet de limiter le nb de meditation utilisé (peut pas depasser les pm_max de la classe mage

    //reste des variables (ne seront utilisé que pour certaines classes)
    j.PM_roule=false;

    j.bouclier=false; //ne sert que au tank (droideka)
    j.tour_bouclier=0;
    j.tour_bouclier_max=2; //nb de tours avec un bouclier au maximum

    j.en_feu=false; //pour tous
    j.tour_en_feu=0;
    j.tour_en_feu_max=4; //nb de tours brulé au maximum

    //pour les chasseurs de prime
    j.nb_bacta=0;
    j.nb_bacta_max=5; //peux n'utiliser que 5 seringue au max

    //on return le joueur crée
    return j;
}


/** fonction pour les attaques **/

bool action_possible(t_joueur* tab_j,int i,int point_de_laction) //verifie si laction est possible avec les point daction restant
{
    if ((tab_j[i].pa_actuel-point_de_laction)>=0) //action possible
    {
        return true;
    }
    else //laction coute trop de point = pas posible de la realiser
    {
        return false;
    }
}

/** attaque individuelle **/

//attaque du mage

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

/** pas finie **/ //quoi faire si action pas possible
void guerison_mage(t_joueur* tab_j,int i) //permet au mage de se soigner
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
        //pas encore reflechit a ca
        //ptetre afficher un texte : "vous n'avez pas assez de PA pr realiser l'action"
    }
}

/** pas finie **/ //quoi faire si action pas possible
void meditation_mage(t_joueur* tab_j,int i) //permet au mage de gagner des pm
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
void etranglement(t_joueur* tab_j,int i,int j) //attaque a distance du mage (attaque longiligne) (i indice du joueur qui joue ; j celui attaqué)
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

//attaque de l'archer

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
//attaque du guerrier

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

//attaque du tank

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

/** pas finie **/ //quoi faire si action pas possible
void roulement(t_joueur* tab_j,int i)//permet pendant un tour (le tour suivant) d'augmenter les PM du tank à 4
{
    int PA=4; //cout en point d'action

    if (action_possible(tab_j,i,PA))
    {
        tab_j[i].PM_roule=true;
        tab_j[i].pa_actuel-=PA;
    }
    else
    {
        //pas encore reflechit a ca
        //ptetre afficher un texte : "vous n'avez pas assez de PA pr realiser l'action"
    }
}

/** pas finie **/ //quoi faire si action pas possible
void bouclier(t_joueur* tab_j,int i)
{
    int PA=6; //cout en point d'action

    if (action_possible(tab_j,i,PA))
    {
        tab_j[i].bouclier=true;
        tab_j[i].pa_actuel-=PA;
    }
    else
    {
        //pas encore reflechit a ca
        //ptetre afficher un texte : "vous n'avez pas assez de PA pr realiser l'action"
    }
}

/** copier tir basique (ladapter en PA et degat) **/

/** pas finie **/ //integrer la gestion de distance avant la verification de PA + quoi faire si action pas possible
void lance_flammes(t_joueur* tab_j,int i,int j)
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
        //pas encore reflechit a ca
        //ptetre afficher un texte : "vous n'avez pas assez de PA pr realiser l'action"
    }
}

/** fonction d'attaque globale **/

void attaque(t_joueur* tab_j,int i,int j,BITMAP* buffer, BITMAP* page) //on affiche sur la page les icones d'attaques et sur le buffer la detection de clic
{
    /** a faire **/
    //doit gerer chaque attaque en fonction des classes (4 grnads if) puis affichage des logos des attaques et detection du clic
}
