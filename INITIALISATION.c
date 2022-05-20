#include "HEADER.h"

/* ------------------------------------- INITIALISATION -------------------------------------
    Les fontions présente dans ce fichier sont des fonctions d'initialisation
*/

t_personnage init_classes(char* nom_classe,int num_classe,int p_action_max, int p_vie_max,int p_mvt_max, BITMAP* icone0_grand, BITMAP* icone0_petit, BITMAP* icone1_grand, BITMAP* icone1_petit) // a decrire
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

    c.icone[0].icone_grand = icone0_grand;
    c.icone[0].icone_petit = icone0_petit;
    c.icone[1].icone_grand = icone1_grand;
    c.icone[1].icone_petit = icone1_petit;

    strcpy(c.nom_classe,nom_classe);

    //on return la structure crée
    return c;
}

t_joueur init_joueur(char* nom_joueur,t_personnage classe_choisie,int num_joueur, int num_skin)
{
    t_joueur j;

    //variables propre a chaque joueur

    strcpy(j.nom_joueur,nom_joueur);
    j.classe=classe_choisie;
    j.numero_joueur=num_joueur;

    //variable utilise en jeu

    j.pa_actuel=j.classe.pa_max;
    j.num_skin = num_skin;

    if(j.classe.numero_classe==1) //pour les mages car leur PM max = 4 avc la mediatation
    {
        j.pm_actuel=2;
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

    //si le joueur est mort =1
    j.elimine=0;

    //pour les skins
    int num_classe; //1 mage ; 2 archer ; 3 guerrier ; 4 tank
    num_classe=j.classe.numero_classe;

    if(num_classe==1) //le joueur est un mage
    {
        if (num_skin == 0)
        {
            j.position_bitmap.x=144;
            j.position_bitmap.y=256;
            j.skin=load_bitmap("nv_perso1.bmp",NULL);
        }
        else
        {
            j.position_bitmap.x=0;
            j.position_bitmap.y=256;
            j.skin=load_bitmap("nv_perso1.bmp",NULL);
        }
        j.classe.image_attaque.attaque1 = load_bitmap("poing.bmp", NULL);
        j.classe.image_attaque.attaque2 = load_bitmap("soin.bmp", NULL);
        j.classe.image_attaque.attaque3 = load_bitmap("augmente_pm.bmp", NULL);
        j.classe.image_attaque.attaque4 = load_bitmap("sabre.bmp", NULL);
        j.classe.image_attaque.attaque5 = load_bitmap("etranglemlent.bmp", NULL);
    }

    else if(num_classe==2) //le joueur est un archer
    {
        if (num_skin == 0)
        {
            j.position_bitmap.x=432;
            j.position_bitmap.y=256;
            j.skin=load_bitmap("nv_perso1.bmp",NULL);
        }
        else
        {
            j.position_bitmap.x=384;
            j.position_bitmap.y=256;
            j.skin=load_bitmap("nv_perso1.bmp",NULL);
        }
        j.classe.image_attaque.attaque1 = load_bitmap("poing.bmp", NULL);
        j.classe.image_attaque.attaque2 = load_bitmap("grenade.bmp", NULL);
        j.classe.image_attaque.attaque3 = load_bitmap("bazouka.bmp", NULL);
        j.classe.image_attaque.attaque4 = load_bitmap("pistolet.bmp", NULL);
        j.classe.image_attaque.attaque5 = load_bitmap("sniper.bmp", NULL);
    }


    else if(num_classe==3) //le joueur est un guerrier
    {
        if (num_skin == 0)
        {
            j.position_bitmap.x=144;
            j.position_bitmap.y=0;
            j.skin=load_bitmap("nv_perso1.bmp",NULL);
        }
        else
        {
            j.position_bitmap.x=144+48*3;
            j.position_bitmap.y=0;
            j.skin=load_bitmap("nv_perso1.bmp",NULL);
        }
        j.classe.image_attaque.attaque1 = load_bitmap("poing.bmp", NULL);
        j.classe.image_attaque.attaque2 = load_bitmap("grenade.bmp", NULL);
        j.classe.image_attaque.attaque3 = load_bitmap("seringue.bmp", NULL);
        j.classe.image_attaque.attaque4 = load_bitmap("bazouka.bmp", NULL);
        j.classe.image_attaque.attaque5 = load_bitmap("pistolet.bmp", NULL);
    }

    else if(num_classe==4) //le joueur est un tank
    {
        if (num_skin == 0)
        {
            j.position_bitmap.x=144;
            j.position_bitmap.y=256;
            j.skin=load_bitmap("nv_perso2.bmp",NULL);
        }
        else
        {
            j.position_bitmap.x=0;
            j.position_bitmap.y=256;
            j.skin=load_bitmap("nv_perso2.bmp",NULL);
        }
        j.classe.image_attaque.attaque1 = load_bitmap("poing.bmp", NULL);
        j.classe.image_attaque.attaque2 = load_bitmap("bouclier.bmp", NULL);
        j.classe.image_attaque.attaque3 = load_bitmap("augmente_pm.bmp", NULL);
        j.classe.image_attaque.attaque4 = load_bitmap("pistolet.bmp", NULL);
        j.classe.image_attaque.attaque5 = load_bitmap("flamme.bmp", NULL);
    }
    erreur_chargement_image(j.skin);
    //on return le joueur crée
    return j;
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

void init_acteur(t_acteur* acteur, int position_x, int position_y, BITMAP* skin, int deplacement_x, int deplacement_y, int position_bitmap_x, int position_bitmap_y, int deplacement_bitmap_x, int deplacement_bitmap_y)
{
    acteur->respiration = 0;

    acteur->position.x = position_x;
    acteur->position.y = position_y;
    acteur->skin = skin;

    acteur->deplacement.x = deplacement_x;
    acteur->deplacement.y = deplacement_y;

    acteur->position_bitmap.x = position_bitmap_x;
    acteur->position_bitmap.y = position_bitmap_y;

    acteur->deplacement_bitmap.x = deplacement_bitmap_x;
    acteur->deplacement_bitmap.y = deplacement_bitmap_y;

    ///// FIN DE CAHQUE LIGNE /////


    acteur->debut_bitmap.base_droite.x = 32;
    acteur->debut_bitmap.base_droite.y = 14;

    acteur->debut_bitmap.base_gauche.x = 32;
    acteur->debut_bitmap.base_gauche.y = 108;

    acteur->debut_bitmap.base_bas.x = 32;
    acteur->debut_bitmap.base_bas.y = 202;

    acteur->debut_bitmap.base_haut.x = 32;
    acteur->debut_bitmap.base_haut.y = 296;

    ///// FIN DE CAHQUE LIGNE /////

    acteur->fin_bitmap.base_droite.x = 320;
    acteur->fin_bitmap.base_droite.y = 14;

    acteur->fin_bitmap.base_gauche.x = 320;
    acteur->fin_bitmap.base_gauche.y = 108;

    acteur->fin_bitmap.base_bas.x = 320;
    acteur->fin_bitmap.base_bas.y = 202;

    acteur->fin_bitmap.base_haut.x = 320;
    acteur->fin_bitmap.base_haut.y = 296;

}


