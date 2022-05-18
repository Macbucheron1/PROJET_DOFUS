#include "HEADER.h"
#define INFINI 9999

/* ------------------------------------- SOUS PROGRAMME -------------------------------------
    Les fontions présente dans ce fichier sont des fonctions de calcul. Elles sont utilitaire
*/


void remplir_tab_coordonnes(t_map* carte)
{
    /* Permet de remplir le tableau de coordonnées de la map
    Prend en parametre un pointeur sur la map
    Ne renvoie rien*/
    int x = 96;
    int y = 32;
    for (int colonne = 0; colonne < COLONNE_TABLEAU; colonne++)
    {
        for (int ligne = 0; ligne < LIGNE_TABLEAU; ligne++)
        {
            carte->tab_coordonnes[colonne][ligne].position_pixel_x = x + 32 * colonne;
            carte->tab_coordonnes[colonne][ligne].position_pixel_y = y + 32 * ligne;
        }
    }
}

void remplir_map_obstacle(t_map* carte)
{
    /* Permet de remplir la matrice contenant la valeur de chaque case. Avec chaque numero represantant soit un obstacle soit un element de decor
    Prend en parametre un pointeur sur une map
    Ne renvoie rien*/
    int terrain [COLONNE_TABLEAU][LIGNE_TABLEAU] = {
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 2, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
        { 0, 1, 1, 1, 0, 2, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0},
        { 0, 0, 2, 2, 0, 2, 2, 2, 1, 1, 1, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 2, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
        { 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1},
        { 2, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1},
        { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 2, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 2, 2, 2, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
        { 0, 2, 2, 2, 1, 1, 0, 0, 0, 0, 2, 1, 1, 0, 0, 0},
        { 0, 2, 2, 2, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        { 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
        { 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
    // On créée cette variable temporaire afin de pouvoir modifier facilement le tableau

    for (int colonne = 0; colonne < COLONNE_TABLEAU; colonne++)
    {
        for (int ligne = 0; ligne < LIGNE_TABLEAU; ligne++)
        {
            carte->map_obstacle[colonne][ligne] = terrain[colonne][ligne];
        }
    }
}

int position_souris_colonne(void)
{
/* Permet de savoir dans quelle colonne se situe la souris
    Ne prend pas de parametre
    Renvoie la colonne dans laquelle la souris se situe. -1 si la souris n'est pas dans une colonne*/
    int debut_tableau_x = 96;
    for (int colonne = 0; colonne < COLONNE_TABLEAU; colonne++)
    {
        if ((mouse_x >= debut_tableau_x + 32 * colonne) && (mouse_x <= debut_tableau_x + 32 * (colonne+1)))
        {
            return colonne;
        }
    }
    return -1;
}

int position_souris_ligne(void)
{
/* Permet de savoir dans quelle ligne se situe la souris
    Ne prend pas de parametre
    Renvoie la ligne dans laquelle la souris se situe. -1 si la souris n'est pas dans une ligne*/
    int debut_tab_y = 32;
    for (int ligne = 0; ligne < LIGNE_TABLEAU; ligne++)
    {
        if ((mouse_y >= debut_tab_y + 32 * ligne) && (mouse_y <= debut_tab_y + 32 * (ligne+1)))
        {
            return ligne;
        }
    }
    return -1;
}


void prepa_alleg(void)
{
    /* Lance alleg init et verifie qu'il fonctionne bien
    Ne prend de parametre
    Ne renvoie rien */
    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(24);
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
	if (install_sound(DIGI_AUTODETECT, MIDI_NONE, 0) != 0) {
        printf("Error initialising sound: %s\n", allegro_error);
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}

void erreur_chargement_image(BITMAP* image)
{
    /*Vérification que l'image est bien chargée (dans le cas contraire image vaut NULL)
    TOUJOURS LE FAIRE CAR ON N'EST JAMAIS CERTAIN DE BIEN TROUVER L'IMAGE
    Prend en parametre l'image a testé
    Ne renvoie rien */
    if (!image)
    {
        allegro_message("pas pu trouver/charger mon_image.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}


void CalculDeplacement(BITMAP* buffer, t_map carte, int x_soldat,int y_soldat, int zoneDeplacement[20][16], int PM_restant, t_joueur Joueurs[], int nbJoueurs, int indiceActuel) // a definir
{
    /* Calcule les zones sur lesqeuelles peut aller le perso et appelle les fonctions d'affichages
    Prend en parametre la bitmap d'affichage, la carte, la position du soldat, la zone de deplacement, les PM restants
    Ne renvoie rien */
    int i,j,tmp,inutile;
    int x=x_soldat;
    int y=y_soldat-PM_restant;
    int continuer=1;
    int continuer1=1;
    coords chemin[PM_restant];
    for(i=0; i<20;i++)                  //Iniitialisation du tableau avec des 0
    {
        for(j=0; j<16;j++)
        {
            zoneDeplacement[i][j]=0;
        }
    }
    //La zone de deplacement correspond a un losange que l'on sép   re en 2 parties (2 grandes boucles for)
    for(i=0;i<PM_restant+1 && continuer1;i++)
    {
        tmp=x;
        for(j=0; j<i*2+1;j++)
        {
            if(x>=0 && y>=0){

                if(!(i==PM_restant && j==PM_restant) && caseDisponible2(carte, x, y, Joueurs, nbJoueurs, indiceActuel)  && CalculChemin(carte,x_soldat,y_soldat,x,y,PM_restant,chemin,&inutile, Joueurs, nbJoueurs)!=-1 ) // Verifie si la case est accessible
                {
                    zoneDeplacement[x][y]=1;                                                           //Si c'est le cas, las case=1 dans le tableau
                }
            }
                if(x<19)
                    x=x+1;
                else
                {
                    break;
                }
        }
        x=tmp-1;
        if(y<15)
            y=y+1;
        else
            continuer=0;
    }
    x=x+2;
    if(continuer){
        for(i=0;i<PM_restant;i++)
        {
            tmp=x;
            for(j=0; j<2*PM_restant-(i*2+1);j++)
            {
                if(x>=0 && y>=0){
                    if(caseDisponible2(carte, x, y, Joueurs, nbJoueurs, indiceActuel)  && CalculChemin(carte,x_soldat,y_soldat,x,y,PM_restant,chemin,&inutile, Joueurs, nbJoueurs)!=-1)
                        zoneDeplacement[x][y]=1;
                }
                if(x<19)
                    x=x+1;
            }
            x=tmp+1;
            if(y<15)
                y=y+1;
        }
    }

}

int Deplacement(t_map carte, int zoneDeplacement[20][16], int indiceActuel, BITMAP* buffer, BITMAP* personnage, int nbJoueurs, t_joueur Joueurs[],BITMAP* fond_menu,BITMAP* avatar[],time_t temps1,time_t temps2 ) //position du click
{
    /* Recupere la position initiale et finale du deplacement
    Prend en parametre la carte, la zone de deplacement, le joueur actuel, la bitmap, et le skin du joueur
    renvoie le nb de PM utilisés */
    int i=0,j=0;
    int PM_utilises=0;

    if(position_souris_colonne()!=-1 && position_souris_ligne()!=-1)                    //Si le curseur et sur la map
    {
        i= position_souris_colonne();
        j= position_souris_ligne();
        int x_initial=Joueurs[indiceActuel].position_colonne;
        int y_initial=Joueurs[indiceActuel].position_ligne;

        if(mouse_b && zoneDeplacement[i][j]==1)                                         //Si le joueur click sur une zone de deplacement
        {
            Joueurs[indiceActuel].position_colonne=position_souris_colonne();
            Joueurs[indiceActuel].position_ligne=position_souris_ligne();
            coords chemin[10];
            CalculChemin(carte, x_initial,y_initial,Joueurs[indiceActuel].position_colonne,Joueurs[indiceActuel].position_ligne, 6,chemin,&PM_utilises, Joueurs, nbJoueurs); //A la place de 6 mettre joueurActuel->classe.pm_max
            AnimationDeplacement(buffer,personnage,carte,x_initial,y_initial, indiceActuel, chemin,PM_utilises ,nbJoueurs,Joueurs,fond_menu,avatar,temps1,temps2);
        }
    }

    return PM_utilises;
}

int CalculChemin(t_map carte, int x1, int y1, int x2, int y2 , int PM, coords chemin1[], int* PM_utilises, t_joueur Joueurs[], int nbJoueurs )
{
    /* Permet de cree une liste contenant toutes les aretes du graphe (representant la map)
    Prend en parametre la carte, le chemin (vide), la position finale/initiale du joueur et le nombre de pm (determiner par cette fonction)
     modifie le tableau chemin et le nombre de PM utilisés
     renvoie -1 si le chemin est invalide, sinon renvoie 1 */

    int nbSommets,nbAretes;
    int tab[20][16]={   {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},                                //Defini tous les sommets du graphe
                        {16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31},
                        {32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47},
                        {48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63},
                        {64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79},
                        {80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95},
                        {96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111},
                        {112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127},
                        {128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143},
                        {144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159},
                        {160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175},
                        {176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191},
                        {192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207},
                        {208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223},
                        {224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239},
                        {240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255},
                        {256,257,258,259,260,261,262,263,264,265,266,267,268,269,270,271},
                        {272,273,274,275,276,277,278,279,280,281,282,283,284,285,286,287},
                        {288,289,290,291,292,293,294,295,296,297,298,299,300,301,302,303},
                        {304,305,306,307,308,309,310,311,312,313,314,315,316,317,318,319} };



    nbSommets = 320;            //nombre de sommet
    int edges[384][2];      //Tous les angles reliant les sommets du graphe (cases)
    int ajout=0;

    for(int i=0; i<20; i++)                                             //bouvle permettant d'initialiser chaques angles du graphe
    {
        for(int j=0; j<16;j++)
        {

            if(caseDisponible(carte, i, j, Joueurs, nbJoueurs))
            {
                if(j<15 && caseDisponible(carte,i, j+1,Joueurs,nbJoueurs))                   //case de droite du tab        en dessous(sur la map)
                {
                    edges[ajout][0]=tab[i][j];
                    edges[ajout][1]=tab[i][j+1];
                    ajout++;
                }
                if(i<19 && caseDisponible(carte,i+1, j, Joueurs, nbJoueurs))                   //case d'en dessous du tab     a droite(sur la map)
                {
                    edges[ajout][0]=tab[i][j];
                    edges[ajout][1]=tab[i+1][j];
                    ajout++;
                }

            }

        }
    }

    nbAretes = ajout;                  //nombre d'angles
    int Adj[nbSommets + 1][nbSommets + 1];      //matrice d'adjacence

    createAdjMatrix(Adj, edges,nbSommets,nbAretes);

    int chemin[PM];             //tableau contenant le chemin dans le graphe
    int start,finish,distance;

    start=tab[x1][y1];          //point de depart ppiur le calcul du chemin
    finish=tab[x2][y2];         //point d'arivée pour le calcul du chemin

    int chemin_valide=dijkstra(Adj,nbSommets+1,start,finish,chemin, &distance,PM);    //variable qui =-1 si le chemin est invalide
    *PM_utilises=distance;      //PM utilisees pour parcourir le chemin
    for(int i=0;i<PM;i++)           //Pour chaque sommet du chemin, on va chercher ses coordonées en (x,y) car plus adapté au tableau (map)
    {
        for(int x=0;x<20;x++)
        {
            for(int y=0;y<16;y++)
            {
                if(tab[x][y]==chemin[i])
                {
                    chemin1[i].x=x;
                    chemin1[i].y=y;
                }
            }
        }

    }
    return chemin_valide;

}

int caseDisponible(t_map carte, int x, int y,t_joueur Joueurs[], int nbJoueurs)
{
    /* permet de determiner si une case est disponible (sans obstacle ou joueur) ou pas
    Prend en parametre la carte et la position de la case
     modifie le tableau chemin et le nombre de PM utilisés
     renvoie 1 si la case est valide, sinon renvoie 0 */
    if(carte.map_obstacle[x][y]==0 )  //Verifie si la case cotient un obstacle
    {
        /*for(int i=0;i<nbJoueurs;i++)
            if(i!=exception && Joueurs[i].position_colonne==x && Joueurs[i].position_ligne==y)      //verifie si un joueur est déjà sur la case => A mettre en place, a la fin
                {
                    return 0;                                                                           //exception sert à éviter de comptabiliser le joueur actuel comme un joueur adverse sur la meme case
                }*/
        return 1;
    }

    return 0;
}

int caseDisponible2(t_map carte, int x, int y,t_joueur Joueurs[], int nbJoueurs, int exception)
{
    /* permet de determiner si une case est disponible (sans obstacle ou joueur) ou pas
    Prend en parametre la carte et la position de la case
     modifie le tableau chemin et le nombre de PM utilisés
     renvoie 1 si la case est valide, sinon renvoie 0 */

    if(carte.map_obstacle[x][y]==0 )  //Verifie si la case cotient un obstacle
    {
        for(int i=0;i<nbJoueurs;i++)
            if(i!=exception && Joueurs[i].position_colonne==x && Joueurs[i].position_ligne==y)      //verifie si un joueur est déjà sur la case => A mettre en place, a la fin
                {
                    return 0;                                                                           //exception sert à éviter de comptabiliser le joueur actuel comme un joueur adverse sur la meme case
                }
        return 1;
    }

    return 0;
}
void createAdjMatrix(int Adj[][320 + 1],int aretes[][2],int nbSommets,int nbAretes)
{
    /*Créé une matrice d'adjacence grâce a un tableau contenant toutes les liaisons d'un graphe
    Prend en parametre une matrice d'adjacence, une liste contenant toutes les arêtes du graphe, le nombre de sommet et d'arretes
    ne renvoie rien*/
	// Initialise toutes les valeurs à 0
	for (int i = 0; i < nbSommets + 1; i++) {
		for (int j = 0; j < nbSommets + 1; j++) {
			Adj[i][j] = 0;
		}
	}
	// recupere les angles et créer la matrice d'adjacence
	for (int i = 0; i < nbAretes; i++) {
		int x = aretes[i][0];
		int y = aretes[i][1];
		Adj[x][y] = 1;
		Adj[y][x] = 1;
	}
}
int dijkstra(int Adj[320 + 1][320 + 1],int n,int startnode, int finishnode, int chemin[], int *distanceChemin, int PM)
{
    /*Applique l'algorithme de dijkstra pour trouver le chemin le plus court d'une case à l'autre
    prend en parametre la matrice d'adjacence, le nombre de sommet, le sommet initial/final, le tableau chemin à rempliir, la distance du chemin à determiner, et le nombre de PM disponible
    renvoie 1 si le chemin est possible sinon renvoie -1*/

    int cout[320 + 1][320 + 1],distance[320 + 1],pred[320 + 1];
    int visited[320 + 1],count,mindistance,nextnode,i,j;
    //pred[] stocke le predescesseur de chaque sommet
    //count contient le nombre de sommet vu

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(Adj[i][j]==0)
            {

                cout[i][j]=INFINI;
            }
            else
                cout[i][j]=Adj[i][j];
    //initialisation pred[],distance[] et visited[]
    for(i=0; i<n; i++)
    {
        distance[i]=cout[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }
    distance[startnode]=0;
    visited[startnode]=1;
    count=1;

    while(count<n-1)
    {
        mindistance=INFINI;
    //On récupère le sommet le plus proche grace à nextnode
        for(i=0; i<n; i++)
            if(distance[i]<mindistance && !visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }
        //On verifie si un plus court chemin existe
        visited[nextnode]=1;
        for(i=0; i<n; i++)
            if(!visited[i])
                if(mindistance+cout[nextnode][i]<distance[i])
                {
                    distance[i]=mindistance+cout[nextnode][i];
                    pred[i]=nextnode;
                }
        count++;
    }


    for(i=0; i<n; i++)
        if(i==finishnode){          //On cherche le sommet de destination
                if(distance[i]>PM)      //on verifie si le nombre de PM suffit
                    return -1;

                int cpt= distance[i]-1;
                chemin[cpt]=i;                  //on stocke le sommet de destination à la derniere place du tableau chemin
                j=i;
                *distanceChemin=distance[i];
                do                                //Puis on stocke les autres sommets du chemin dans l'orde suivant debut >...>fin
                {
                    j=pred[j];
                    cpt--;
                    chemin[cpt]=j;

                }
                while(j!=startnode);
            }
    return 1;
}

int Star (t_star TabStar[LIMIT_STAR], int Stardelay, int i,BITMAP * backscreen) {
    int color5 = makecol(100,100,100);  //gris foncé
        if (Stardelay == 10) {

            i = 0;
            while (TabStar[i].posY != 1000) {
                i++;
            }
            TabStar[i].posX = 160 + rand()%500;
            TabStar[i].posY = 110;
            Stardelay--;
        }
        if (Stardelay != 10) {
            if (Stardelay < 6) {
                Stardelay = 10;
            }
            else {
                Stardelay--;
            }
        }
        for (int j=0 ; j<LIMIT_STAR ; j++) {
            if (TabStar[j].posY != 1000) {
                if (TabStar[j].posY > 490) {
                    TabStar[j].posY = 1000;
                }
                else {
                    TabStar[j].posY = TabStar[j].posY+20;   //vitesse
                    ellipsefill(backscreen,TabStar[j].posX+5,TabStar[j].posY,2,10,color5);
                }
            }
        }
    return Stardelay;
}

int nouvellePartie(BITMAP* buffer)
{

    BITMAP *personnage=load_bitmap("personnage.bmp", NULL);
    erreur_chargement_image(personnage);
    int nbJoueurs=nombreJoueurs(buffer);
    t_joueur Joueurs[nbJoueurs];

   int classe[nbJoueurs];
    int x,y,i,cpt;
    char pseudos[nbJoueurs][13];
    int nbPseudos=0;
    int longueurPseudos[4];             ///contient la longueur de chaque pseudo
     int modifier[nbJoueurs];           ///tableau conteant des 0 quand un pseudo n'a pas été initialisé, 1 pour le contraire
     int quitter;
    for(i=0;i<nbJoueurs;i++)
    {
        classe[i]=1;
        modifier[i]=0;
    }
    color couleur_click[2* nbJoueurs];   //une couleur pour chaque triangle
    for(i=0;i<2*nbJoueurs;i++)
        {
            couleur_click[i].r=i*30+40;
            couleur_click[i].g=i*10+100;
            couleur_click[i].b=i*20+100;
        }


    FONT* arial_28 = load_font("arial_28.pcx", NULL, NULL);

    int continuer=1;

    while(1){


        //rectfill(buffer, 0,500,800,600, makecol(0,255, 127));                     //Fais crash

        textprintf_ex(buffer, arial_28, 325, 530, makecol(255,255,255),-1, "JOUER");



        for(int i=200;i<=nbJoueurs*200;i+=200)
        {
            if(modifier[i/200-1]==1)
                textprintf_ex(buffer, font, i-170, 40, makecol(255, 255,255),-1,"%s",pseudos[i/200-1]);
            else{
                textprintf_ex(buffer, font, i-170, 40, makecol(125,125,125),-1,"Pseudo joueur %d",i/200);
            }
        }

        show_mouse(buffer);

       for(x=200; x<=800;x+=200)                                                       //Dessin des demarcations des persp
        {
            line(buffer,x,0,x,500, makecol(0,0,255));
            rect(buffer, x-180, 30,x-20,70,makecol(0,0,255));
        }
        line(buffer,0,500,800,500, makecol(0,0,255));                                   //Dessin de la demarcation avec le bouton jouer

        cpt=0;
        for(x=200; x<=200*nbJoueurs;x+=200)
        {
            int points[6] = { x-180, 207,   x-160, 197,  x-160, 217};
            int points2[6]= {x-40, 197,   x-40, 217,  x-20, 207};
            polygon(buffer, 3, points, makecol(couleur_click[cpt].r, couleur_click[cpt].g, couleur_click[cpt].b));
            polygon(buffer, 3, points2, makecol(couleur_click[cpt+1].r, couleur_click[cpt+1].g, couleur_click[cpt+1].b));

            cpt+=2;
        }

        cpt=0;
        for(i=200; i<=nbJoueurs*200;i+=200)
        {
            if(classe[cpt]==1 || classe[cpt]==4)
            {

                x=811;
                y=33;
            }
            else if(classe[cpt]==2)   //stormtrooper
            {

                x=1881;
                y=327;

            }
            else if(classe[cpt]==3)   //dark vador
            {
                x=1860;
                y=820;
            }

            masked_blit(personnage,buffer, x, y, i-140,150, 75,115);

            cpt++;
        }
        ;
        if(mouse_b)                                     //Si le clic gauche est enfoncé
        {
            if(mouse_x>=0 && mouse_x<=800 && mouse_y>=500 && mouse_y<=600){  //Si on clique sur "jouer"
                for(int i=0;i<nbJoueurs;i++)
                {
                    if(longueurPseudos[i]<1)                //verifie si tous les joueurs ont un pseudos de minimum 1 caractere
                        continuer=0;
                }

                if(!continuer){
                    allegro_message("Vous devez écrire les %d pseudos", nbJoueurs );
                }
                else
                {
                    for(int i=0; i<nbJoueurs;i++)
                    {
                        Joueurs[i].classe.numero_classe=classe[i];
                        strcpy(Joueurs[i].nom_joueur, pseudos[i]);
                    }
                    destroy_bitmap(personnage);
                    rest(100);
                    quitter=jouer(Joueurs,nbJoueurs);
                    return quitter;
                        //menu_prin;
                }
                continuer=1;
            }

            for(x=200; x<=200*nbJoueurs;x+=200)                         //Si on clique sur une des zone de saisie
            {
                if(mouse_x>=x-180 && mouse_x<=x-20 && mouse_y>=30 && mouse_y<=70)
                {

                    longueurPseudos[x/200-1]=saisie(buffer,x-180+10,40,pseudos[x/200 -1]);      //On recupere la longueur du pseudo
                    if(modifier[x/200-1]==0){
                        nbPseudos++;
                        modifier[x/200-1]=1;
                    }

                }
                cpt++;
            }

            int couleur=getpixel(buffer,mouse_x,mouse_y);
            int r=getr(couleur);
            int g=getg(couleur);
            int b=getb(couleur);

            for(i=0;i<nbJoueurs;i++)
            {

                if(r==couleur_click[2*i].r && g==couleur_click[2*i].g && b==couleur_click[2*i].b && classe[i]>1)    //Fleche de gauche
                    {
                        classe[i]--;
                        rest(100);
                    }
                if(r==couleur_click[2*i+1].r && g==couleur_click[2*i+1].g && b==couleur_click[2*i+1].b && classe[i]<4)  //fleche de droite
                    {
                        classe[i]++;
                        rest(100);
                    }

            }

            rest(100);
        }

        show_mouse(buffer);
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        clear(buffer);

    }

}

int saisie(BITMAP* buffer,int x,int y, char saisie[12+1]) // stockage de la totalité de la saisie
{
  int touche, touche1, touche2;
  int i=0;              //position curseur
  int saisie_max=12;
    int tailleLettre=9;
  char derniereSaisie[2];    // stockage la derniere touche saisie
  saisie[saisie_max]=0;
  derniereSaisie[1]=0;
  clear_keybuf();
  rectfill(buffer,x-10+2,y-10+2,x-10+160-2,y-10+40-2, makecol(0,0,0));
  textprintf(buffer,font,x+tailleLettre*(i+1),y+10,makecol(0,255,255),"_"); //Affivhage du curseur
    blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

  while(!key[KEY_ENTER] && !key[KEY_ENTER_PAD])     //La touche entree permet de valider le pseudo
  {

    touche=readkey();
    touche1=touche & 0xFF; // code ASCII
    touche2=touche >> 8;   // scancode


    if (( touche1>31 && touche1<58) || ( touche1>64 && touche1<123))    //Si la touche est une lettre
    {
      if (i>=saisie_max)
       i=saisie_max;
      else
      {
        saisie[i]=touche1;
        derniereSaisie[0]=touche1;
        saisie[i+1]=0;

        /*  on affiche la touche saisie */
        textprintf(buffer,font,x+tailleLettre*i,y+10,makecol(0,255,255),"%s",derniereSaisie);
        i++;
        textprintf(buffer,font,x+tailleLettre*i,y+10,makecol(0,255,255),"_");
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
      }
    }

    if ( touche2==KEY_BACKSPACE )   //Effacer
    {
        rectfill(buffer,x+(tailleLettre)*i+tailleLettre,y+10,x+i*tailleLettre+2*tailleLettre, y+20, makecol(0,0,0)); //Rectangle noir recouvrant la surface effacée
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

      i--;
      if ( i<0 )
        i=0;


      textprintf(buffer,font,x+tailleLettre*i,y+10,makecol(0,255,255),"_");
      textprintf(buffer,font,x+tailleLettre*(i+1),y+10,makecol(0,255,255)," ");
    }
    //* si validation
    if ( (touche2==KEY_ENTER_PAD) || (touche2==KEY_ENTER) )
    {
      textprintf(buffer,font,x+tailleLettre*i,y+10,makecol(0,0,255)," ");
      if (i==0)
        saisie[0]=32; // space
      saisie[i+1]=0;
    }
  }
    clear_keybuf();
  return i;     //taille du pseudo



}

int nombreJoueurs(BITMAP* buffer)
{
    FONT* arial_28 = load_font("arial_28.pcx", NULL, NULL);
    FONT* arial_20 = load_font("arial_20.pcx", NULL, NULL);
    BITMAP* menuDeroulant=load_bitmap("nbJoueurs.bmp", NULL);
    erreur_chargement_image(menuDeroulant);
    int deploye=0;
    int nbJoueurs=0;
    int continuer=1;
    while(continuer)
    {
        if(nbJoueurs!=0 && mouse_b && mouse_x>=250 && mouse_x<=600 && mouse_y>=350 && mouse_y<=400 && deploye==0)
        {
            continuer=0;
        }
        rectfill(buffer, 250, 350,600,400, makecol(0,0,255));
        textprintf_ex(buffer,arial_20,290,360,makecol(255,255,255),-1," Choix des classes ");
        textprintf(buffer,arial_28,100,150,makecol(0,0,255)," Veuillez saisir le nombre de joueurs : ");

        if(nbJoueurs!=0)
        {
            textprintf(buffer,arial_20,260,260,makecol(0,0,255),"%d JOUEURS ",nbJoueurs);       //Affichage du nombre de joueurs
        }
        rect(buffer,250,250,600,300, makecol(0,0,255));         //Zone de selection

        int points[6]= {570, 265,   590, 265,  580, 285};               //triangle
        polygon(buffer, 3, points, makecol(0,0,255));
        //masked_blit(menuDeroulant,screen,0,0,250,250,350,156);
        //rest(1000);
        if(mouse_b && mouse_x>=250 && mouse_x<=600 && mouse_y>=250 && mouse_y<=300 && deploye==0)
        {
            deploye=1;
            for(int i=0; i<118;i++)                                     //Animation du menu Deroulant
            {
                textprintf(buffer,arial_28,100,150,makecol(0,0,255)," Veuillez saisir le nombre de joueurs : ");    ///On reaffiche tout
                rect(buffer,250,250,600,300, makecol(0,0,255));
                int points[6]= {570, 265,   590, 265,  580, 285};
                polygon(buffer, 3, points, makecol(0,0,255));

                masked_blit(menuDeroulant,buffer,0,0,250,300,350,i);
                blit(buffer, screen,0,0,0,0,SCREEN_W,SCREEN_H);
                clear_bitmap(buffer);
                rest(0.1);
            }
            rest(200);
        }

        if(deploye==1)
        {

            masked_blit(menuDeroulant,buffer,0,0,250,300,350,118);
            if(mouse_b && mouse_x>=250 && mouse_x<=600 && mouse_y>300 && mouse_y<=338)   //2 JOUEURS
            {
                for(int i=118; i>0;i--)                                     //Animation inverse du menu Deroulant
                {
                    textprintf(buffer,arial_28,100,150,makecol(0,0,255)," Veuillez saisir le nombre de joueurs : ");    ///On reaffiche tout
                    rect(buffer,250,250,600,300, makecol(0,0,255));
                    int points[6]= {570, 265,   590, 265,  580, 285};
                    polygon(buffer, 3, points, makecol(0,0,255));

                    masked_blit(menuDeroulant,buffer,0,0,250,300,350,i);
                    blit(buffer, screen,0,0,0,0,SCREEN_W,SCREEN_H);
                    clear_bitmap(buffer);
                    rest(0.1);
                    deploye=0;
                }
                nbJoueurs=2;
                rest(200);
            }
            else if(mouse_b && mouse_x>=250 && mouse_x<=600 && mouse_y>338 && mouse_y<=378)   //3 JOUEURS
            {
                for(int i=118; i>0;i--)                                     //Animation inverse du menu Deroulant
                {
                    textprintf(buffer,arial_28,100,150,makecol(0,0,255)," Veuillez saisir le nombre de joueurs : ");    ///On reaffiche tout
                    rect(buffer,250,250,600,300, makecol(0,0,255));
                    int points[6]= {570, 265,   590, 265,  580, 285};
                    polygon(buffer, 3, points, makecol(0,0,255));

                    masked_blit(menuDeroulant,buffer,0,0,250,300,350,i);
                    blit(buffer, screen,0,0,0,0,SCREEN_W,SCREEN_H);
                    clear_bitmap(buffer);
                    rest(0.1);
                    deploye=0;
                }
                nbJoueurs=3;
                rest(200);
            }

            else if(mouse_b && mouse_x>=250 && mouse_x<=600 && mouse_y>378 && mouse_y<=418)   //4 JOUEURS
            {
                for(int i=118; i>0;i--)                                     //Animation inverse du menu Deroulant
                {
                    textprintf(buffer,arial_28,100,150,makecol(0,0,255)," Veuillez saisir le nombre de joueurs : ");    ///On reaffiche tout
                    rect(buffer,250,250,600,300, makecol(0,0,255));
                    int points[6]= {570, 265,   590, 265,  580, 285};
                    polygon(buffer, 3, points, makecol(0,0,255));

                    masked_blit(menuDeroulant,buffer,0,0,250,300,350,i);
                    blit(buffer, screen,0,0,0,0,SCREEN_W,SCREEN_H);
                    clear_bitmap(buffer);
                    rest(0.1);
                    deploye=0;
                }
                nbJoueurs=4;
                rest(200);
            }

            if(mouse_b && mouse_x>=250 && mouse_x<=600 && mouse_y>=250 && mouse_y<=300)   //Faire derouler, sans selectionner le nombre de joueur
            {
                for(int i=118; i>0;i--)                                     //Animation inverse du menu Deroulant
                {
                    textprintf(buffer,arial_28,100,150,makecol(0,0,255)," Veuillez saisir le nombre de joueurs : ");    ///On reaffiche tout
                    rect(buffer,250,250,600,300, makecol(0,0,255));
                    int points[6]= {570, 265,   590, 265,  580, 285};
                    polygon(buffer, 3, points, makecol(0,0,255));

                    masked_blit(menuDeroulant,buffer,0,0,250,300,350,i);
                    blit(buffer, screen,0,0,0,0,SCREEN_W,SCREEN_H);
                    clear_bitmap(buffer);
                    rest(0.1);
                    deploye=0;
                }
                rest(200);
            }
            show_mouse(buffer);

        }
        show_mouse(buffer);
        blit(buffer, screen,0,0,0,0,SCREEN_W,SCREEN_H);
        clear_bitmap(buffer);
    }
    return nbJoueurs;
}

/** pour les attaques **/

void CalculAttaque_zone(BITMAP* buffer, t_map carte, int x_soldat,int y_soldat, int zoneAttaque[20][16], int distance)
{
    /* Calcule les zones sur lesqeuelles peut aller le perso et appelle les fonctions d'affichages
    Prend en parametre la bitmap d'affichage, la carte, la position du soldat, la zone de deplacement, les PM restants
    Ne renvoie rien */
    int i,j,tmp;
    int x=x_soldat;
    int y=y_soldat-distance;
    int continuer=1;
    int continuer1=1;

    for(i=0; i<20;i++)                  //Iniitialisation du tableau avec des 0
    {
        for(j=0; j<16;j++)
        {
            zoneAttaque[i][j]=0;
        }
    }
    //La zone de deplacement correspond a un losange que l'on sép   re en 2 parties (2 grandes boucles for)
    for(i=0;i<distance+1 && continuer1;i++)
    {
        tmp=x;
        for(j=0; j<i*2+1;j++)
        {
            if(x>=0 && y>=0){
                if(!(i==distance && j==distance) && carte.map_obstacle[x][y]==0) // Verifie si la case est accessible
                {

                    zoneAttaque[x][y]=1;                                                           //Si c'est le cas, las case=1 dans le tableau
                }
            }
                if(x<19)
                    x=x+1;
                else
                {
                    break;
                }
        }

        x=tmp-1;
        if(y<15)
            y=y+1;
        else
            continuer=0;
    }
    x=x+2;
    if(continuer){
        for(i=0;i<distance;i++)
        {
            tmp=x;
            for(j=0; j<2*distance-(i*2+1);j++)
            {
                if(x>=0 && y>=0){
                    if(carte.map_obstacle[x][y]==0)
                        zoneAttaque[x][y]=1;
                }
                if(x<19)
                    x=x+1;
            }

            x=tmp+1;
            if(y<15)
                y=y+1;
        }
    }

}

void CalculAttaque_ligne(BITMAP* buffer, t_map carte, int x_soldat,int y_soldat, int zoneAttaque[20][16], int distance,t_joueur* tab_j,int nb_j)
{
    /* Calcule les zones sur lesqeuelles peut aller le perso et appelle les fonctions d'affichages
    Prend en parametre la bitmap d'affichage, la carte, la position du soldat, la zone de deplacement, les PM restants
    Ne renvoie rien */
    int i,j;
    //int tmp;
    int x=x_soldat;
    int y=y_soldat-1;

    for(i=0; i<20;i++)                  //Iniitialisation du tableau avec des 0
    {
        for(j=0; j<16;j++)
        {
            zoneAttaque[i][j]=0;
        }
    }

    while(y>y_soldat-distance && y>=0 && caseDisponible(carte,x,y,tab_j,nb_j))
    {
        zoneAttaque[x][y]=1;
        if(y>0)
            y--;
    }
    y=y_soldat+1;

    while(y<y_soldat+distance && y<=15 && caseDisponible(carte,x,y,tab_j,nb_j))
    {
        zoneAttaque[x][y]=1;
        if(y<150)
            y++;
    }
    y=y_soldat;
    x--;
    while(x>x_soldat-distance && x>=0 && caseDisponible(carte,x,y,tab_j,nb_j))
    {
        printf("%d/%d\n", x,y);
        zoneAttaque[x][y]=1;
        if(x>0)
            x--;
    }
    x=x_soldat+1;;
    while(x<x_soldat+distance && x<=19 && caseDisponible(carte,x,y,tab_j,nb_j))
    {
        zoneAttaque[x][y]=1;
        if(x<19)
            x++;
    }
    printf("\n");



    }


