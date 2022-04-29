#include "header.h"

t_personnage init_classes(char* nom_classe,int num_classe,int p_action_max, int p_vie_max,int p_mvt_max,BITMAP** skin)
{
    t_personnage c;

    //definit en fonction des differentes classes
    c.numero_classe=num_classe;

    c.pa_max=p_action_max;
    c.pa_actuel=c.pa_max;

    c.pm_max=p_mvt_max;
    c.pm_actuel=c.pm_max;

    c.pv_max=p_vie_max;
    c.pv_actuel=c.pv_max;

    //reste des variables

    c.max_meditation=3; //ne sert que au mages (jedi/sith)
    c.nom_classe[TAILLE_NOM_CLASSE]=nom_classe;
    c.PM_roule=false;

    c.bouclier=false;
    c.tour_bouclier=0;
    c.tour_bouclier_max=3; //nb de tours avec un bouclier au maximum

    c.en_feu=false;
    c.tour_en_feu=0;
    c.tour_en_feu_max=4; //nb de tours brulé au maximum

    c.skin[TAILLE_SKINS]=skin;

    return c;
}

void init_tab_skin(int nb_skin_total,char* nom_classe,BITMAP** tab_skin)
{
    int i;
    char nomfichier[256];

    for (i=0;i<nb_skin_total;i++)
    {
        // sprintf permet de faire un printf dans une chaine
        sprintf(nomfichier,"img/%s%d.bmp",nom_classe,i+1);

        tab_skin[i] = load_bitmap(nomfichier,NULL);
        if (!tab_skin[i]){
            allegro_message("pas pu trouver %s",nomfichier);
            exit(EXIT_FAILURE);
        }
    }
}
