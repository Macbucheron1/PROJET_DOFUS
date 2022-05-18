
#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <stdbool.h>
#include <time.h>

#define LIGNE_TABLEAU 16
#define COLONNE_TABLEAU 20

#define TAILLE_NOM_CLASSE 15
#define TAILLE_SKINS 15
#define LIMIT_STAR 25

/* ----------- STRUCTURE DE DONNEES ----------- */

typedef struct{
    int x;
    int y;
}coords;

typedef struct Cases{
    int position_pixel_x;
    int position_pixel_y;
}t_cases;

typedef struct Map{
    int map_obstacle[COLONNE_TABLEAU][LIGNE_TABLEAU];
    BITMAP* fond_map;
    t_cases tab_coordonnes[COLONNE_TABLEAU][LIGNE_TABLEAU];
}t_map;

typedef struct Personnage{ //les classes
    int numero_classe; // de 1 � 4 pour differencier les classes plus facilement
    char nom_classe[TAILLE_NOM_CLASSE];
    int pv_max; //si soin ne pas depasser ce pv max
    int pm_max; // afin de remettre a ca a chaque tour
    int pa_max; // pareil
}t_personnage;

typedef struct Joueur{
	@@ -117,7 +116,7 @@ void montre_curseur(BITMAP* page, BITMAP* curseur); // Permet d'afficher un curs
void affichagePerso(BITMAP* buffer, BITMAP* soldat, t_map carte,int x,int y); //permet d'afficher un personnage
void SurbrillanceDeplacement(BITMAP* buffer,t_map carte, int tab[20][16]); //est appelé par CalculDeplacement, permet d'afficher des carres verts sur les cases contenant des 1 dans le tableau tab
void afficheSouris(BITMAP* buffer,t_map carte, int tab[20][16]); // est appelé par SurbrillanceDeplacement et affiche un carré bleu a la position de la souris (si la souris se trouve dans la zone de deplacement)
void AnimationDeplacement(BITMAP* buffer, BITMAP* soldat, t_map carte, int x_initial, int y_initial, int indiceActuel, coords chemin[], int PM, int nbJoueurs,t_joueur Joueurs[], BITMAP* fond_menu,BITMAP* avatar[],time_t temps1,time_t temps2, int affiche_on, int affiche_grille); // Fait l'animation de deplacement
void affichage_en_jeu(BITMAP* buffer,BITMAP* fond_menu, BITMAP* avatar[]); // A commenter
int menu_en_jeu(BITMAP* buffer, BITMAP* fond_menu, int* affiche_son, int* affiche_grille); // A commenter
void affichage_classe2(int* position_x_bitmap_soldat, int* nouvelle_affichage, int* direction_soldat, BITMAP* soldat, BITMAP* page, int position_affichage_x, int position_affichage_y, BITMAP* map_ville); // Affiche la classe clone
void affichage_classe3(int* position_x_bitmap_soldat, int* nouvelle_affichage, int* direction_soldat, BITMAP* soldat, BITMAP* page, int position_affichage_x, int position_affichage_y, BITMAP* map_neige); // Affiche la classe dark vador
void affichage_classe1(int* position_x_bitmap_soldat, int* nouvelle_affichage, int* direction_soldat, BITMAP* soldat, BITMAP* page, int position_affichage_x, int position_affichage_y, BITMAP* map_desert); // Affiche la classe jedi
int affichage_credit(int police, int vitesse, int depart_texte, BITMAP* page, FONT* arial_28, FONT* arial_26, FONT* arial_24, FONT* arial_22, FONT* arial_20,FONT* arial_18, FONT* arial_16, FONT* arial_14, FONT* arial_12, FONT* arial_10, FONT* arial_8); // Affiche les credits
void animation_decor_menu(BITMAP* soldat, t_acteur mesActeurs[], int* delay, t_decor* visuel_menu, BITMAP* tableau_map[], unsigned int* temps); // Anime tout le decor du mennu
int animation_vers_gauche(int delay, t_acteur* monActeur, int position_debut_x, int position_final_x); // Anime le personnage vers la gauche
int animation_vers_droite(int delay, t_acteur* monActeur, int position_debut_x, int position_final_x);// Anime le personnage vers la droite
int animation_vers_bas(int delay, t_acteur* monActeur, int position_debut_y, int position_final_y);// Anime le personnage vers le bas
int animation_vers_haut(int delay, t_acteur* monActeur, int position_debut_y, int position_final_y);// Anime le personnage vers le haut
void AffichePerso(BITMAP* buffer, BITMAP* soldat, t_map carte, int nbJoueurs, t_joueur Joueurs[], int exception);
void AfficheTout(BITMAP* buffer, BITMAP* soldat, t_map carte, int nbJoueurs, t_joueur Joueurs[], BITMAP* fond_menu, BITMAP* avatar[],time_t temps1,time_t temps2, int affiche_on, int affiche_grille);
void AnimationClasse1(BITMAP* buffer, BITMAP* soldat, t_map carte, int x_initial, int y_initial, int indiceActuel, coords chemin[], int PM, int nbJoueurs, t_joueur Joueurs[], BITMAP* fond_menu,BITMAP* avatar[],time_t temps1,time_t temps2, int affiche_on, int affiche_grille);
void AnimationClasse2(BITMAP* buffer, BITMAP* soldat, t_map carte, int x_initial, int y_initial, int indiceActuel, coords chemin[], int PM, int nbJoueurs, t_joueur Joueurs[], BITMAP* fond_menu,BITMAP* avatar[],time_t temps1,time_t temps2, int affiche_on, int affiche_grille);
void AnimationClasse3(BITMAP* buffer, BITMAP* soldat, t_map carte, int x_initial, int y_initial, int indiceActuel, coords chemin[], int PM, int nbJoueurs, t_joueur Joueurs[], BITMAP* fond_menu,BITMAP* avatar[],time_t temps1,time_t temps2, int affiche_on, int affiche_grille);       //Affiche tous les Perso szuf l'indice exception


/* ----------- SOUS PROGRAMME ----------- */
void remplir_tab_coordonnes(t_map* carte); // Permet de remplir les coordonnées de la map
void remplir_map_obstacle(t_map* carte); // Permet de remplir les types de chaque case
int position_souris_colonne(void); // Renvoie la colonne dans lequel se situe la souris, renvoie -1 si pas dans une colonne
int position_souris_ligne(void); // Renvoie la ligne dans lequel se situe la souris, renvoie -1 si pas dans une ligne
void prepa_alleg(void); // Lance alleg init et verifie qu'il fonctionne bien
void erreur_chargement_image(BITMAP* image); // Verifie qu'on a bien charger l'image
void CalculDeplacement(BITMAP* buffer, t_map carte, int x_soldat,int y_soldat, int zoneDeplacement[20][16], int PM_restant, t_joueur Joueurs[], int nbJoueurs,int indiceActuel, int affiche_on, int affiche_grille); //Remplis le tableau tab,avec des 1, sur les cases sur lesquelles peut aller le joueur
int Deplacement(t_map carte, int zoneDeplacement[20][16], int indiceActuel, BITMAP* buffer, BITMAP* personnage, int nbJoueurs, t_joueur Joueurs[],BITMAP* fond_menu,BITMAP* avatar[],time_t temps1,time_t temps2, int affiche_on, int affiche_grille); //Recupere dans la struct position, la position fde la souris lors du click, renvoie le nb de PM utilisés
int CalculChemin(t_map carte, int x1, int y1, int x2, int y2 , int PM, coords chemin1[], int* PM_utilises, t_joueur Joueurs[], int nbJoueurs );//Stock le chemin dans le tableau chemin si il est possible, sinon renvoie -1
int dijkstra(int G[320 + 1][320 + 1],int n,int startnode, int finishnode, int chemin[], int *distanceChemin, int PM); //Applique l'algorithme de dijkstra pour trouver le chemin le plus court d'une case à l'autre
void createAdjMatrix(int Adj[][320 + 1],int arr[][2],int N,int M);  //Créé une matrice d'adjacence grâce a un tableau contenant toutes les liaisons d'un graphe
int caseDisponible(t_map carte, int x, int y,t_joueur Joueurs[], int nbJoueurs);  // permet de determiner si une case est disponible (sans obstacle ou joueur) ou pas
int Star (t_star TabStar[LIMIT_STAR], int Stardelay, int i,BITMAP * backscreen);


int nouvellePartie(BITMAP* buffer, SAMPLE* musique, int* volume);
int saisie(BITMAP* buffer,int x,int y, char saisie[12+1]); // stockage de la totalité de la saisie
int nombreJoueurs(BITMAP* buffer);
int caseDisponible2(t_map carte, int x, int y,t_joueur Joueurs[], int nbJoueurs, int exception);


/* ----------- INITIALISATION ----------- */

t_personnage init_classes(char* nom_classe,int num_classe,int p_action_max, int p_vie_max,int p_mvt_max,int nb_skin_total); //initialise les differentes classes
t_joueur init_joueur(char* nom_joueur,int num_joueur,t_personnage classe_choisie); //initialise les joueurs
void init_map(t_map* carte); // Permet d'initaliser une map
void init_decor(t_decor* decor); // Initialise le decor
void init_acteur(t_acteur* acteur, int position_x, int position_y, BITMAP* skin, int deplacement_x, int deplacement_y, int position_bitmap_x, int position_bitmap_y, int deplacement_bitmap_x, int deplacement_bitmap_y); // Initialise un acteurs
/* ----------- PRINCIPALE ----------- */

void menu_principal(void); // Lance le menu principale
int jouer(t_joueur Joueurs[], int nbJoueurs, SAMPLE* musique, int* volume); // Permet de jouer
void credit_en_cours(BITMAP* page, t_decor* visuel_menu, BITMAP* soldat, t_acteur mesActeurs[], int* delay, unsigned int* temps, BITMAP* tab_bitmap[]) ; //Lance les credits
void parametre_en_cours(BITMAP* page, t_decor* visuel_menu, SAMPLE* musique, int* volume, BITMAP* soldat, t_acteur mesActeurs[], int* delay, BITMAP* tab_bitmap[], unsigned int* temps); // Lance les parametres
void apercu_classe_en_cours(BITMAP* page, t_decor* visuel_menu, BITMAP* soldat, int* delay, t_acteur mesActeurs[], BITMAP* tab_bitmap[],unsigned int* temps); // Lance l'apercu des classes
/* ----------- ATTAQUE ----------- */

/** SOUS-PROG **/

void CalculAttaque_zone(BITMAP* buffer, t_map carte, int x_soldat,int y_soldat, int zoneAttaque[20][16], int distance); //voir sur quelle case on peut attaquer (en zone)
void CalculAttaque_ligne(BITMAP* buffer, t_map carte, int x_soldat,int y_soldat, int zoneAttaque[20][16], int distance,t_joueur* tab_j,int nb_j)

/** AFFICHAGE **/
;
void afficheSouris_attaque(BITMAP* buffer,t_map carte, int zoneAttaque[20][16]); //change la couleur de la case quand on passe par dessus
void SurbrillanceAttaque(BITMAP* buffer,t_map carte, int zoneAttaque[20][16]); //colore les case ou l'on peut attaquer

/** GENERALE **/

bool action_possible(t_joueur* tab_j,int i,int point_de_laction); //verification de PA necessaire
void verif_bouclier(t_joueur* tab_j,int i); //remet a false si tour avc bouclier pass�
void verif_roulement(t_joueur* tab_j,int i); //remet a false apres un tour
void verif_en_feu(t_joueur* tab_j,int i); //si en feu met des degats
int joueur_sur_case_ou_pas(t_map carte, int zoneAttaque[20][16], t_joueur* joueur, BITMAP* buffer, BITMAP* animation, int nbJoueurs ); //verifie si on clique sur une case avc un joueur
void attaque(t_joueur* tab_j,int i,BITMAP* buffer, BITMAP* page,t_map carte, int zoneAttaque[20][16], BITMAP* animation, int nbJoueurs, int quelle_attaque ); //lance les attaques en fonction de la classe et de la case cliquée

//peut etre a mettre dans les fonctions d'affichages

void affichage_action_impossible(BITMAP* page); // pas assez de pa
void affichage_action_impossible_nb(BITMAP* page); //trop d'utilisation
void affichage_attaque_impossible(BITMAP* page); // personne sur la case
void affichage_attaque_inefficace(BITMAP* page); // joueur attaqu� a un bouclier

/// POUR VOIR A QUOI CORRESPOND CHAQUE ATTAQUE VEUILLEZ VOUS REFEREZ AU DIFFERENT .C ASSOCIE

/** MAGE **/

void c_a_c_mage(t_joueur* tab_j,int i,BITMAP* buffer,t_map carte,int zoneAttaque[20][16],BITMAP* animation,int nb_joueur);
void guerison_mage(t_joueur* tab_j,int i, BITMAP* page); //permet au mage de se soigner
void meditation_mage(t_joueur* tab_j,int i, BITMAP* page); //permet au mage de gagner des pm
void lancer_sabre(t_joueur* tab_j,int i,BITMAP* buffer,t_map carte,int zoneAttaque[20][16],BITMAP* animation,int nb_joueur);
void etranglement(t_joueur* tab_j,int i,BITMAP* buffer,t_map carte,int zoneAttaque[20][16],BITMAP* animation,int nb_joueur);

/** ARCHER **/

void c_a_c_archer(t_joueur* tab_j,int i,BITMAP* buffer,t_map carte,int zoneAttaque[20][16],BITMAP* animation,int nb_joueur);
void lancer_grenade_thermique_archer(t_joueur* tab_j,int i,BITMAP* buffer,t_map carte,int zoneAttaque[20][16],BITMAP* animation,int nb_joueur);
void tir_lourd_archer(t_joueur* tab_j,int i,BITMAP* buffer,t_map carte,int zoneAttaque[20][16],BITMAP* animation,int nb_joueur);
void tir_basique_archer(t_joueur* tab_j,int i,BITMAP* buffer,t_map carte,int zoneAttaque[20][16],BITMAP* animation,int nb_joueur);
void tir_de_precision(t_joueur* tab_j,int i,BITMAP* buffer,t_map carte,int zoneAttaque[20][16],BITMAP* animation,int nb_joueur);

/** GUERRIER **/

void c_a_c_guerrier(t_joueur* tab_j,int i,BITMAP* buffer,t_map carte,int zoneAttaque[20][16],BITMAP* animation,int nb_joueur);

/** TANK **/

void c_a_c_tank(t_joueur* tab_j,int i,BITMAP* buffer,t_map carte,int zoneAttaque[20][16],BITMAP* animation,int nb_joueur);
void roulement(t_joueur* tab_j,int i,BITMAP* page);
void bouclier(t_joueur* tab_j,int i,BITMAP* page);
void lance_flammes(t_joueur* tab_j,int i,BITMAP* buffer,t_map carte,int zoneAttaque[20][16],BITMAP* animation,int nb_joueur);

#endif // HEADER_H_INCLUDED
