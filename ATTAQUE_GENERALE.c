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

void verif_en_feu(t_joueur* tab_j,int i,BITMAP* buffer,BITMAP* soldat,t_map carte,int nbJoueur, int respiration)
{
    int degat=20;
    if((tab_j[i].en_feu)&&(tab_j[i].tour_en_feu<tab_j[i].tour_en_feu_max))
    {
        tab_j[i].pv_actuel-=degat; //infilge 20 de degats a chaque tour que le joueur est en feu
        tab_j[i].tour_en_feu+=1;
        affichage_degat_soin(tab_j,i,buffer,degat,soldat,carte,nbJoueur,1, respiration);
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
                    indice_joueur_attaque=(joueur[k].numero_joueur); // car num de joueur de 1 a 4 mais indice de 0 a 3
                    return indice_joueur_attaque;
                }
            }
            affichage_attaque_impossible(buffer); //si on clique sur une casse ou personne n'est
        }
        return indice_joueur_attaque;
    }
    return indice_joueur_attaque;
}

void affichage_degat_soin(t_joueur* tab_j,int j,BITMAP* buffer,int degat,BITMAP* soldat,t_map carte,int nbJoueur,int verif,int  respiration)//j joueur attaqué
{
    /* j le joueur sur lequel on affiche le msg
    verif verifie si c'est une attaque, un soin, ou autre (bouvclier, pm, etc)*/
    int x=tab_j[j].position_colonne*32+97;
    int y=tab_j[j].position_ligne*32-12;
    int couleur_degats = makecol(255,0,0);
    int couleur_soins = makecol(0,255,255);
    int couleur_autre = makecol(0,0,255);
    if (verif==1)
    {
        for (int i = 0; i<100; i++)
        {
            textprintf_ex(buffer, font, x, y-10, couleur_degats, -1, "-%d PV", degat);
            rest(1);
            blit(buffer, screen, 0, 0, 0, 0, SCREEN_W,SCREEN_H);
            AffichePerso(buffer,soldat,carte,nbJoueur,tab_j,nbJoueur+1, respiration); //nb joueur+1 pr afficher tous les perso
        }
    }

    if (verif==2) //soin
    {
        for (int i = 0; i<100; i++)
        {
            textprintf_ex(buffer, font, x, y-10, couleur_soins, -1, "+%d PV", degat);
            rest(1);
            blit(buffer, screen, 0, 0, 0, 0, SCREEN_W,SCREEN_H);
            AffichePerso(buffer,soldat,carte,nbJoueur,tab_j,nbJoueur+1, respiration); //nb joueur+1 pr afficher tous les perso
        }
    }
    if (verif==3) //PM
    {
        for (int i = 0; i<100; i++)
        {
            textprintf_ex(buffer, font, x, y-10, couleur_autre, -1, "+%d PM", degat);
            rest(1);
            blit(buffer, screen, 0, 0, 0, 0, SCREEN_W,SCREEN_H);
            AffichePerso(buffer,soldat,carte,nbJoueur,tab_j,nbJoueur+1, respiration); //nb joueur+1 pr afficher tous les perso
        }
    }
    if (verif==4) //bouclier
    {
        for (int i = 0; i<100; i++)
        {
            textprintf_ex(buffer, font, x, y-10, couleur_autre, -1, "+%d bouclier", degat);
            rest(1);
            blit(buffer, screen, 0, 0, 0, 0, SCREEN_W,SCREEN_H);
            AffichePerso(buffer,soldat,carte,nbJoueur,tab_j,nbJoueur+1, respiration); //nb joueur+1 pr afficher tous les perso
        }
    }
}


/** fonction d'attaque globale **/

void attaque(t_joueur* tab_j,int i,BITMAP* buffer,t_map carte, int zoneAttaque[20][16], BITMAP* animation, int nbJoueurs, int *quelleAttaque,BITMAP* soldat, int respiration)
{
    int quelle_attaque=*quelleAttaque;
    int num_classe; //1 mage ; 2 archer ; 3 guerrier ; 4 tank
    num_classe=tab_j[i].classe.numero_classe;

    if(num_classe==1) //le joueur est un mage
    {
        if(quelle_attaque==1)
        {
            c_a_c_mage(tab_j,i,buffer,carte,zoneAttaque,animation,nbJoueurs,soldat, respiration);
        }
        if(quelle_attaque==2)
        {
            guerison_mage(quelleAttaque,tab_j,i,buffer,carte,zoneAttaque,animation,nbJoueurs,soldat, respiration);
        }
        if(quelle_attaque==3)
        {
            meditation_mage(tab_j,i,buffer,quelleAttaque,carte,zoneAttaque,animation,nbJoueurs,soldat, respiration);
        }
        if(quelle_attaque==4)
        {
            lancer_sabre(tab_j,i,buffer,carte,zoneAttaque,animation,nbJoueurs,soldat, respiration);
        }
        if(quelle_attaque==5)
        {
            etranglement(tab_j,i,buffer,carte,zoneAttaque,animation,nbJoueurs,soldat, respiration);
        }
    }

    else if(num_classe==2) //le joueur est un archer
    {
        if(quelle_attaque==1)
        {
            c_a_c_archer(tab_j,i,buffer,carte,zoneAttaque,animation,nbJoueurs,soldat, respiration);
        }
        if(quelle_attaque==2)
        {
            lancer_grenade_thermique_archer(tab_j,i,buffer,carte,zoneAttaque,animation,nbJoueurs,soldat,respiration);
        }
        if(quelle_attaque==3)
        {
            tir_lourd_archer(tab_j,i,buffer,carte,zoneAttaque,animation,nbJoueurs,soldat, respiration);
        }
        if(quelle_attaque==4)
        {
            tir_basique_archer(tab_j,i,buffer,carte,zoneAttaque,animation,nbJoueurs,soldat, respiration);
        }
        if(quelle_attaque==5)
        {
            tir_de_precision(tab_j,i,buffer,carte,zoneAttaque,animation,nbJoueurs,soldat, respiration);
        }
    }


    else if(num_classe==3) //le joueur est un guerrier
    {
        if(quelle_attaque==1)
        {
            c_a_c_guerrier(tab_j,i,buffer,carte,zoneAttaque,animation,nbJoueurs,soldat, respiration);
        }
        if(quelle_attaque==2)
        {
            lancer_grenade_thermique_guerrier(tab_j,i,buffer,carte,zoneAttaque,animation,nbJoueurs,soldat);
        }
        if(quelle_attaque==3)
        {
            guerison_guerrier(quelleAttaque,tab_j,i,buffer,carte,zoneAttaque,animation,nbJoueurs,soldat);
        }
        if(quelle_attaque==4)
        {
            tir_lourd_guerrier(tab_j,i,buffer,carte,zoneAttaque,animation,nbJoueurs,soldat);
        }
        if(quelle_attaque==5)
        {
            tir_basique_guerrier(tab_j,i,buffer,carte,zoneAttaque,animation,nbJoueurs,soldat);
        }
    }

    else if(num_classe==4) //le joueur est un tank
    {
        if(quelle_attaque==1)
        {
            c_a_c_tank(tab_j,i,buffer,carte,zoneAttaque,animation,nbJoueurs,soldat);
        }
        if(quelle_attaque==2)
        {
            roulement(tab_j,i,buffer,quelleAttaque,carte,zoneAttaque,animation,nbJoueurs,soldat);
        }
        if(quelle_attaque==3)
        {
            bouclier(tab_j,i,buffer,quelleAttaque,carte,zoneAttaque,animation,nbJoueurs,soldat);
        }
        if(quelle_attaque==4)
        {
            tir_basique_tank(tab_j,i,buffer,carte,zoneAttaque,animation,nbJoueurs,soldat);
        }
        if(quelle_attaque==5)
        {
            lance_flammes(tab_j,i,buffer,carte,zoneAttaque,animation,nbJoueurs,soldat);
        }
    }
    //rest(50);
}
