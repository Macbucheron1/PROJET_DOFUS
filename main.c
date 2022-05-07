#include "header.h"

int main()
{
    /** INITIALISATION DE ALLEGRO **/

    allegro_init(); //initialise les keyboard et mouse en meme temps

    /** INITIALISATION DES STRUCTURES **/

    //initialisation des skins (nb d'image composant nos skins)

    int skin_mage_taille;
    int skin_archer_taille;
    int skin_guerrier_taille;
    int skin_tank_taille;

    skin_mage_taille=1;
    skin_archer_taille=1;
    skin_guerrier_taille=1;
    skin_tank_taille=1;

    //initialisation des classes

    t_personnage mage;
    t_personnage archer;
    t_personnage guerrier;
    t_personnage tank;

    mage=init_classes("mage",1,6,2000,6,skin_mage_taille); //PM max 6 mais initialiser a 3 dns Joueur car mediatation
    archer=init_classes("archer",2,6,1700,5,skin_archer_taille);
    guerrier=init_classes("guerrier",3,6,2500,4,skin_guerrier_taille);
    tank=init_classes("tank",4,6,4800,2,skin_tank_taille);

    //initialisation des joueurs

    t_joueur j1;
    t_joueur j2;
    t_joueur j3;
    t_joueur j4;

    j1=init_joueur("luc",1,mage);
    j2=init_joueur("ibra",2,archer);
    j3=init_joueur("nathan",3,tank);
    j4=init_joueur("maxime",4,guerrier);

    /**  test allegro d'affichage  **/

    //fin
    return 0;
}
END_OF_MAIN();
