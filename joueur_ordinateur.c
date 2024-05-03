#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*fichier qui concerne la deuxième partie joueur ordinateur implementant
une intelligence simple*/

typedef struct  {   /*initialisation d'une structure appelée coordonnées qui stocke deux valeurs l'abscisse et coordonne*/
    int abs;
    int ord;
}coordonnees;

/*cette fonction donne aléatoirement à chaque joueur une couleur du pion (noir ou blanc) par
l’appel de la fonction aléatoire rand() qui fait le choix entre 2 valeurs min=0 et max=1*/
int Randoms(int min, int max,int count, char *joueur,char *ordinateur )
{
    int i;
    int num;
    for (i = 0; i < count; i++) {
        int num = (rand() %(max - min + 1)) + min;
         /*si on affiche le 0 alors le joueur va jouer avec le noir et l'ordinateur va jouer avec le  blanc ;
        et si on s'affiche 1 le joueur va jouer en blanc  et l'ordinateur en noir*/

        if (num==0)
        {
            printf("vous etes le noir: N\n");
            *joueur= 'N';
            *ordinateur='B';
        }
        if (num==1)
        {
            printf("vous etes le blanc: B\n");
            *joueur= 'B';
            *ordinateur='N';
        }
}

return num;
}

/*elle permet de proposer au joueur en  trois options (commencer/aide/quitter)*/
void menu1()
{
    srand((time(NULL)));
    color(11,0);
    color(11,0);
    printf("\t\t\t\t _________________________\n");color(11,0);
    printf("\t\t\t\t|      1-COMMENCER        |\n");color(11,0);
    printf("\t\t\t\t|_________________________|\n");color(11,0);
    printf("\t\t\t\t _________________________\n");color(11,0);
    printf("\t\t\t\t|         2-Aide          |\n");color(11,0);
    printf("\t\t\t\t|_________________________|\n");color(11,0);
    printf("\t\t\t\t _________________________\n");color(11,0);
    printf("\t\t\t\t|        3-Quitter        |\n");color(11,0);
    printf("\t\t\t\t|_________________________|\n");color(6,0);

    int choix=0;
    int i, j;
    printf("Veuillez entrer un nombre: ");
    scanf("%d",&choix);
    if(choix==1)
    {
        joueur_ordinateur(); /*appel de la fonction joueur_joueur*/
    }

    if(choix==2)
    {
        printf("Veuillez entrer un chiffre entre 1 et 8 suivi d'une lettre entre 'a' et 'h'\n\n");
        printf("Veuillez entrer un chiffre entre 1 et 8 suivi d'une lettre entre 'a' et 'h'\n\n");
        printf("Pour gagner il faut avoir plus de pions de votre couleur  que l adversaire sur l othellier.\n\nAu debut de la partie, la position de depart  est indiquee.\n\n");
        printf("Le joueur avec le pion noir commence toujours.\n\nChaque joueur a son tour , pose un pion de sa  couleur sur une case vide, adjacente a un pion adverse.\n\n");
        printf("Cette pose doit encadrer le pion adverse ,\n\nc’est-a-dire deux pions de meme couleur encadre un pion de couleur opposante,\n\n");
        printf("Cet encadrement peut etre horizontale ,verticale, diagonale.\n\nOn peut encadrer plus qu’un seul pion.\n\n");
        printf("Apres cet encadrement un retournement s effectue.\n\n");
        printf("Si un joueur ne possede aucun coup permettant le retournement de pions adverses, celui-ci passe son tour et c'est a l'adversaire de jouer.\n\n");
        printf("La fin du jeu est lorsque l othellier est totalement remlpie.\n\n");
    }

    if(choix==3)
        {printf("A La Prochaine");}
}


/*Cette fonction sert à créer un tableau de cases qui contiennent une structure de couples
d’indices représentant les indices de colonnes et lignes des cases vides de la grille*/

int remplir_tab(coordonnees *position, char grille[][8])
{
    int k=0; /*indice des lignes du tableau*/
    for (int i=0; i<8; i++)/*on parcours la grille*/
    {
      for(int j=0;j<8; j++)
        {
            if (grille[i][j]=='\0') /*si on trouve une case vide ajoute son abscisse
                                     et son coordonneau tableau dans une seule ligne*/
            {   position[k].abs=i;
                position[k].ord=j;
                k++;               /*on ajoute a K un pour savoir le nombre de lignes
                                   du tableau c'est à dire le nombre de cases vides */
            }
        }
    }
    return k;
}
void affiche_position(coordonnees *position, int nf)
{
    for(int i=0;i<nf;i++) {
            printf ("{%d,%d}\n",position[i].abs ,position[i].ord);
    }
}

/*fonction principal de jeu entre joueur ordinateur implementant une intelligence simple*/
void joueur_ordinateur()
{

  printf("Veuillez entrer un chiffre entre 1 et 8 suivi d'une lettre entre 'a' et 'h'\n");
  char grille[8][8] = { 0 };
  int ligne = 0;                    /*indice de la ligne */
  int colonne = 0;                  /*indice de la colonne*/
  int nbr_fin = 0;              /*nombre des cases remplies*/
  char y = 0;                       /* lettre de la colonne choisie du joueur*/
  int x = 0;                        /* nombre de la ligne choisie du joueur */
  char z=0;                         /* lettre de la colonne choisie du joueur*/
  int w=0;                          /* nombre de la ligne choisie du joueur */
  char ordinateur;                  /*represente le pion de l'ordinateur*/
  char joueur;                      /*represente le pion de l'ordinateur*/
  int min = 0, max = 1, count = 1;
  int score_blanc=0;
  int score_noir=0;
  int nbr;                   /*valeur choisie par la fonction aléatoire qui indique
                                     la couleurs du pion joueur et celui de l'ordinateur selon sa valeur*/
  int i=0;                           /*indice de parcours de la ligne */
  int j=0;                           /*indice de parcours de la colonne */
  int choix2=0;
  grille[3][3] = grille[4][4] = 'B'; /*remplissage des quatres premieres cases de l'othellier*/
  grille[3][4] = grille[4][3] = 'N';

  /*utuliser le temp comme origine de random*/
  srand(time(0));
  nbr=Randoms(min, max, count,&joueur,&ordinateur);



  othellier(grille); /*affichage initial de la grille*/

  nbr_fin=2;
  do{

   if (joueur=='N')  /*si le joueur joue avec le pion noir*/
    {
    nbr_fin= nbr_fin+1;   /*on incremente le nombres de cases remplies par 1*/
    printf(" Veuillez choisir  une position : ");
    scanf("%d %c", &x, &y);       /* lire et stocker la position choisie en x et y */
    y = tolower(y) - 'a';         /* on convertit la lettre de colonne en indice de colonne */
    x--;                          /*on convertit le nombre choisie en indice de ligne */
    grille[x][y]='N';             /*affectation à la position choisie le pion noir*/
    retournement(grille,x,y,'N'); /*on fait le retournement s'il exite*/
    othellier(grille);            /*affichage du nouveau othellier avec
                                        les nouvelles modifications*/

    coordonnees position[64];

    int k = remplir_tab(position, grille); /*indice de parcours des lignes du tableau*/
    int indiceAleat=rand()%k ; /*choisir une ligne aléatoire du tableau c'est à dire une case vide aléatoire*/
    grille[position[indiceAleat].abs][position[indiceAleat].ord]='B';/*on affecte à la grille la position choisie par l'ordinateur*/
    retournement(grille,position[indiceAleat].abs,position[indiceAleat].ord,'B');/*on fait le retournement s'il exite*/
    othellier(grille); /*affichage du nouveau othellier avec
                                        les nouvelles modifications*/
 }

 if (joueur=='B')  /*si le joueur joue avec le pion blanc*/
 {
    nbr_fin= nbr_fin+1;     /*on incremente le nombres de cases remplies par 1*/
    printf(" Veuillez choisir  une position : ");
    scanf("%d %c", &w, &z);         /* lire et stocker la position choisie en w et z */
    z = tolower(z) - 'a';           /* on convertit la lettre de colonne en indice de colonne */
    w--;                            /*on convertit le nombre choisie en indice de ligne */
    grille[w][z]='B';               /*affectation à la position choisie le pion noir*/
    retournement(grille,w,z,'B');   /*on fait le retournement s'il exite*/
    othellier(grille);              /*affichage du nouveau othellier avec
                                       les nouvelles modifications*/
    coordonnees position[64];
    int k = remplir_tab(position, grille);  /*indice de parcours des lignes du tableau*/

    int indiceAleat=rand()%k;/*choisir une ligne aléatoire du tableau c'est à dire une case vide aléatoire*/
    grille[position[indiceAleat].abs][position[indiceAleat].ord]='N';/*on affecte à la grille la position choisie par l'ordinateur*/
    retournement(grille,position[indiceAleat].abs,position[indiceAleat].ord,'N');/*on fait le retournement s'il exite*/
    othellier(grille);/*affichage du nouveau othellier avec
                                       les nouvelles modifications*/
  }

}while(nbr_fin < 32);

/*CALCUL DU SCORE;*/
 for(i=0;i<8;i++)     /*on parcours la grille*/
   {for(j=0;j<8;j++)
     {
        if (grille[i][j]=='N')
            score_noir=score_noir+1;/* si on trouve un pion noir on ajoute 1 au score_noir*/

        if (grille[i][j]=='B')
            score_blanc=score_blanc+1;/* si on trouve un pion blanc on ajoute 1 au score_blanc*/
     }
    }
    /*affichage du score*/
 if (joueur=='N') /*c'est à dire le pion joueur est noir*/
   {
       printf("Votre score est %d\n",score_noir);
       printf("Le score de l'ordinateur est %d\n",score_blanc);
   }
 if (joueur=='B')  /*c'est à dire le pion joueur est blanc*/
   {
       printf("Votre score est %d\n",score_blanc);
       printf("Le score de l'ordinateur est %d\n",score_noir);
   }

    /*affichage du gangnat*/
    /*sile score blanc est le grand et le pion joueur est blanc ,
    ou si le score noir est le grand et le pion joueur est noir le joueur gagne*/
 if(((score_blanc>score_noir)&&(joueur=='B'))||((score_noir>score_blanc)&&(joueur=='N')))
      {printf("Congratulations Vous avez gagne \n ");
       printf("\t\t\t\tYYY    YYY  OOOOO    U     U    W       W       W    IIIIIII   N    N \n ");color(11,0);
       printf("\t\t\t\t  YY  YY   O     O   U     U     W     W W     W        I      N N  N  \n");color(6,0);
       printf("\t\t\t\t    YY     O     O   U     U      W   W   W   W         I      N  N N  \n");color(11,0);
       printf("\t\t\t\t    YY     O     O   U     U       W W     W W          I      N    N  \n");color(6,0);
       printf("\t\t\t\t    YY      OOOOO     UUUUU         W       W        IIIIIII   N    N  \n");color(11,0);}


 else
      printf("Malheuresement vous avez perdu \n");
printf("Si vous voulez revenir au menu tapez 1:\n");
printf("Si vous voulez rejouer tapez 2:\n");
scanf("%d",&choix2);
if(choix2==1)
{
     for (i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                grille[i][j]=' ';/*vidation de la grille*/
            }
        }
     menu1(); /*appel de la fonction menu1 */

}
if(choix2==2)
{
        for (i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                grille[i][j]=' ';/*vidation de la grille*/
            }
        }
     joueur_ordinateur(); /*appel de la fonction joueur_ordinateur*/
}
return 0;
}



