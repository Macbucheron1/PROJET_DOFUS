#include "header.h"

int main()
{
    allegro_init();
    install_keyboard();

    //initialisation des skins

    BITMAP* skin_mage[TAILLE_SKINS];
    BITMAP* skin_archer[TAILLE_SKINS];
    BITMAP* skin_guerrier[TAILLE_SKINS];
    BITMAP* skin_tank[TAILLE_SKINS];

    init_tab_skin(1,"mage",skin_mage);
    init_tab_skin(1,"archer",skin_archer);
    init_tab_skin(1,"guerrier",skin_guerrier);
    init_tab_skin(1,"tank",skin_tank);

    //initialisation des classes

    t_personnage mage;
    t_personnage archer;
    t_personnage guerrier;
    t_personnage tank;

    mage=init_classes("mage",1,6,2000,3,skin_mage);
    archer=init_classes("archer",2,6,1700,5,skin_archer);
    guerrier=init_classes("guerrier",3,6,2500,4,skin_guerrier);
    tank=init_classes("tank",4,6,4800,2,skin_tank);

    return 0;
}
END_OF_MAIN();
