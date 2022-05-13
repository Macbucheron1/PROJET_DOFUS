#include "HEADER.h"

/** fonction etant utilisé dans chaque fichiers d'attaques **/

bool action_possible(t_joueur* tab_j,int i,int point_de_laction)
{
    /* Permet de savoir si une action est possible avec les point daction
    restant au joueur d'indice i*/

    if ((tab_j[i].pa_actuel-point_de_laction)>=0) //action possible
    {
        return true;
    }
    else //laction coute trop de point = pas posible de la realiser
    {
        return false;
    }
}

void affichage_action_impossible(BITMAP* page)
{
    /* affiche un msg quand un joueur ne peut pas
    effectuer d'action à cause de ses PA*/

    int couleur_fond=makecol(0,0,0);
    int couleur_texte=makecol(255,255,255);
    rectfill(page,140,300,655,315,couleur_fond);
    textprintf_ex(page,font,150,305,couleur_texte,-1,"Vous n'avez pas assez de point d'action pour realiser l'action");

}

void affichage_action_impossible_nb(BITMAP* page)
{
    /* affiche un msg quand un joueur ne peut pas
    effectuer d'action à cause de ses PA*/

    int couleur_fond=makecol(0,0,0);
    int couleur_texte=makecol(255,255,255);
    rectfill(page,140,300,645,315,couleur_fond);
    textprintf_ex(page,font,150,305,couleur_texte,-1,"Vous avez deja consomme toutes vos utilsation de cette action");
}

void affichage_attaque_impossible(BITMAP* page)
{
    /* affiche un msg quand un joueur ne peut pas
    effectuer d'action à cause de ses PA*/

    int couleur_fond=makecol(0,0,0);
    int couleur_texte=makecol(255,255,255);
    rectfill(page,280,300,530,315,couleur_fond);
    textprintf_ex(page,font,290,305,couleur_texte,-1,"Il n'y a personne sur la case");
}

void affichage_attaque_inefficace(BITMAP* page)
{
    /* affiche un msg quand un joueur ne peut pas
    effectuer d'action car un joueur a un bouclier*/

    int couleur_fond=makecol(0,0,0);
    int couleur_texte=makecol(255,255,255);
    rectfill(page,180,300,640,315,couleur_fond);
    textprintf_ex(page,font,190,305,couleur_texte,-1,"Cette attaque n'est pas efficace contre son bouclier !!");
}

void verif_bouclier(t_joueur* tab_j,int i)
{
    /* sert à verifier le nombre de tour durant lequel le bouclier est actif
    si la limite eest depasé, le sort se desactive */

    if ((tab_j[i].tour_bouclier<tab_j[i].tour_bouclier_max) && (tab_j[i].bouclier))
    {
        tab_j[i].tour_bouclier+=1;
    }
    else
    {
        tab_j[i].tour_bouclier=0;
        tab_j[i].bouclier=false;
    }
}

void verif_roulement(t_joueur* tab_j,int i)
{
    /* remise à false car le sort ne dure qu'un ne dure qu'un tour */
    if (tab_j[i].PM_roule)
    {
        tab_j[i].PM_roule=false;
    }
}

void verif_en_feu(t_joueur* tab_j,int i)
{
    if((tab_j[i].en_feu)&&(tab_j[i].tour_en_feu<tab_j[i].tour_en_feu_max))
    {
        tab_j[i].pv_actuel-=20; //infilge 20 de degats a chaque tour que le joueur est en feu
        tab_j[i].tour_en_feu+=1;
    }
    else
    {
        tab_j[i].tour_en_feu=0;
        tab_j[i].en_feu=false;
    }
}

int joueur_sur_case_ou_pas(t_map carte, int zoneAttaque[20][16], t_joueur* joueur, BITMAP* buffer, BITMAP* animation, int nbJoueurs )
{
    /*Verifie lors du clic si un joueur est sur la case ou non
    return l'indice du joueur (donc son numero-1) ou bien 4 si
    il n'y as personne sur la case*/

    int i=0,j=0;
    int indice_joueur_attaque=20; //personne n'a ete attaque car pas un indice de joueur

    //printf("id_j1:%d\n",indice_joueur_attaque);
    if(position_souris_colonne()!=-1 && position_souris_ligne()!=-1)                    //Si le curseur et sur la map
    {
        i= position_souris_colonne();
        j= position_souris_ligne();

        if(mouse_b && zoneAttaque[i][j]==1 )                                         //Si le joueur click sur une zone d'attaque
        {


            for(int k=0; k<nbJoueurs; k++)
            {
                if((joueur[k].position_colonne==i)&&(joueur[k].position_ligne==j))
                {

                    indice_joueur_attaque=(joueur[k].numero_joueur)-1; // car num de joueur de 1 a 4 mais indice de 0 a 3
                    rest(200);
                    return indice_joueur_attaque;
                }
            }

            affichage_attaque_impossible(buffer); //si on clique sur une casse ou personne n'est
            blit(buffer, screen,0,0,0,0,SCREEN_W,SCREEN_H);
            rest(500);
        }
        //printf("id_j3:%d\n",indice_joueur_attaque);
        return indice_joueur_attaque;
    }
    return indice_joueur_attaque;
}

/** fonction d'attaque globale **/

void attaque(t_joueur* tab_j,int i,int j,BITMAP* buffer, BITMAP* page) //on affiche sur la page les icones d'attaques et sur le buffer la detection de clic
{
    /** a faire **/
    //doit gerer chaque attaque en fonction des classes (4 grnads if) puis affichage des logos des attaques et detection du clic
    //faire la verification de bouclier a chaque fois car si actif le perso ne recoit pas de degats
    verif_bouclier(tab_j,i);//au debut de la fonction car doit savoir si le tank est protege ou pas
    verif_en_feu(tab_j,i); //au debut car si le joueur est en feu on lui inflige les degats a ce moment la

    verif_roulement(tab_j,i); //a metre a la fin car remise a false
}
