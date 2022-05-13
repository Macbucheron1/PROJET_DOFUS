#include "HEADER.h"

/* ------------------------------------- INITIALISATION -------------------------------------
    Les fontions présente dans ce fichier sont des fonctions d'initialisation
*/

t_personnage init_classes(char* nom_classe,int num_classe,int p_action_max, int p_vie_max,int p_mvt_max,int nb_skin_total) // a decrire
{
    /* Permet d'initaliser les classes
    Prend en parametre le nom de classe, le numero de classe, les points d'action max, les points vie max, les points mvt max, le nb skin total
    Renvoie la structure créée*/

    t_personnage c;

    //definit en fonction des differentes classes

    c.numero_classe=num_classe;

    c.pa_max=p_action_max;
    c.pm_max=p_mvt_max;
    c.pv_max=p_vie_max;

    strcpy(c.nom_classe,nom_classe);

/**
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
    }**/
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

void init_decor(t_decor* decor)
{
    /* Permet d'inialiser le decor du menu
    Prend en parametre le decor
    ne renvoie rien*/

    BITMAP* tmp1 = load_bitmap("grandfond_decor.bmp", NULL);
    erreur_chargement_image(tmp1);
    BITMAP* tmp2 = load_bitmap("map_desert.bmp", NULL);
    erreur_chargement_image(tmp2);
    BITMAP* tmp3 = load_bitmap("map_neige.bmp", NULL);
    erreur_chargement_image(tmp3);
    decor->visuel =  create_bitmap(3200, SCREEN_H);
    blit(tmp1, decor->visuel, 0, 0, 0, 0, 1600, 600);
    blit(tmp1, decor->visuel, 0, 0, 1600, 0, 1600, 600);
    blit(tmp2, decor->visuel, 0, 0, 1600, 0, 800, 600);
    blit(tmp3, decor->visuel, 0, 0, 800, 0, 800, 600);
    decor->avancement_x = 1;
    decor->avancement_y = 1;
    decor->position_x = 0;
    decor->position_y = 0;
}

void init_map(t_map* carte)
{
    /* Permet d'initialiser une map
    Prend en parametre la carte qu'on doit remplir
    Ne renvoie rien*/
    carte->fond_map = load_bitmap("map_desert.bmp",NULL);
    erreur_chargement_image(carte->fond_map);
    remplir_tab_coordonnes(carte);
    remplir_map_obstacle(carte);
}



