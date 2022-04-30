#include "header.h"

int main()
{
    allegro_init();
    install_keyboard();


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

    mage=init_classes("mage",1,6,2000,3,skin_mage_taille);
    archer=init_classes("archer",2,6,1700,5,skin_archer_taille);
    guerrier=init_classes("guerrier",3,6,2500,4,skin_guerrier_taille);
    tank=init_classes("tank",4,6,4800,2,skin_tank_taille);

    /** ----- test allegro d'affichage ----- **/

    // BITMAP servant de buffer d'affichage (double buffer)
    BITMAP *page;

    // Image de fond
    BITMAP *decor;

    //initialiser le screen
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,640,480,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    //double buffer
    page=create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(page);

    //initialiser le decor
    decor=load_bitmap("img/decor.bmp",NULL);
    if (!decor)
    {
        allegro_message("pas pu trouver img/decor.bmp");
        exit(EXIT_FAILURE);
    }

    while (!key[KEY_ESC])
    {
        // effacer buffer en appliquant décor  (pas de clear_bitmap)
        blit(decor,page,0,0,0,0,SCREEN_W,SCREEN_H);

        // afficher l'image de la classe mage
            draw_sprite(page,mage.skin[0],50,100);
            textprintf(page,font,150,150,makecol(255,0,0),"classe: %s",mage.nom_classe);

        // afficher l'image de la classe archer
            draw_sprite(page,archer.skin[0],100,200);

        // afficher l'image de la classe guerrier
            draw_sprite(page,guerrier.skin[0],150,300);

        // afficher l'image de la classe tank
            draw_sprite(page,tank.skin[0],200,400);

        // affichage du buffer à l'écran
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }

    return 0;
}
END_OF_MAIN();
