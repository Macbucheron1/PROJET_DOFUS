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
    c.pa_actuel=c.pa_max;

    c.pm_max=p_mvt_max;
    c.pm_actuel=c.pm_max;

    c.pv_max=p_vie_max;
    c.pv_actuel=c.pv_max;

    //reste des variables (ne seront utilisé que pour certaines classes)

    c.max_meditation=3; //ne sert que au mages (jedi/sith)
    strcpy(c.nom_classe,nom_classe);
    c.PM_roule=false;

    c.bouclier=false; //ne sert que au tank (droideka)
    c.tour_bouclier=0;
    c.tour_bouclier_max=3; //nb de tours avec un bouclier au maximum

    c.en_feu=false; //pour tous
    c.tour_en_feu=0;
    c.tour_en_feu_max=4; //nb de tours brulé au maximum

    //pour les chasseurs de prime
    c.nb_bacta=0;
    c.nb_bacta_max=5; //peux n'utiliser que 5 seringue au max

    //initialisation du tableau de bitmap qu'on utilisera pour les animation
    int i;
    char nomfichier[256]; //pour charger la bmp que nous voulons utiliser

    for (i=0;i<nb_skin_total;i++)
    {
        // sprintf permet de faire un printf dans une chaine
        sprintf(nomfichier,"img/%s%d.bmp",nom_classe,i+1); //exemple: img/mage1

        c.skin[i] = load_bitmap(nomfichier,NULL);
        if (!c.skin[i]){
            allegro_message("pas pu trouver %s",nomfichier);
            exit(EXIT_FAILURE);
        }
    }

    //on return la structure crée
    return c;
}

void init_decor(t_decor* decor)
{
    /* Permet d'inialiser le decor du menu
    Prend en parametre le decor
    ne renvoie rien*/

    BITMAP* tmp2 = load_bitmap("map_desert.bmp", NULL);
    erreur_chargement_image(tmp2);
    BITMAP* tmp3 = load_bitmap("map_neige.bmp", NULL);
    erreur_chargement_image(tmp3);
    BITMAP* tmp4 = load_bitmap("map_ville.bmp", NULL);
    erreur_chargement_image(tmp4);
    decor->visuel =  create_bitmap(3200, SCREEN_H);
    blit(tmp4, decor->visuel, 0, 0, 2400, 0, 800, 600);
    blit(tmp2, decor->visuel, 0, 0, 1600, 0, 800, 600);
    blit(tmp3, decor->visuel, 0, 0, 800, 0, 800, 600);
    blit(tmp4, decor->visuel, 0, 0, 0, 0, 800, 600);
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



