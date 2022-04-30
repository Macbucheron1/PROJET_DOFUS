#include "header.h"

t_personnage init_classes(char* nom_classe,int num_classe,int p_action_max, int p_vie_max,int p_mvt_max,int nb_skin_total)
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

    //reste des variables (ne seront utilis� que pour certaines classes)

    c.max_meditation=3; //ne sert que au mages (jedi/sith)
    strcpy(c.nom_classe,nom_classe);
    c.PM_roule=false;

    c.bouclier=false; //ne sert que au tank (droideka)
    c.tour_bouclier=0;
    c.tour_bouclier_max=3; //nb de tours avec un bouclier au maximum

    c.en_feu=false; //pour tous
    c.tour_en_feu=0;
    c.tour_en_feu_max=4; //nb de tours brul� au maximum

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

    //on return la structure cr�e
    return c;
}
