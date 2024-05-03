#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*fichier qui concerne la troisième  partie joueur ordinateur implementant
une intelligence moyenne*/

typedef struct {   /*initialisation d'une structure appelée
                 coordonnées qui stocke deux valeurs l'abscisse et coordonne*/
    int abs;
    int ord;
}coordonnees;

/*cette fonction donne aléatoirement à chaque joueur une couleur du pion (noir ou blanc)
par l’appel de la fonction aléatoire rand() qui fait le choix entre 2
valeurs min=0 et max=1*/
int Randoms1(int min, int max,int count, char *joueur,char *ordinateur )
{
    int i;
    int num;
    for (i = 0; i < count; i++) {
        int num = (rand() %(max - min + 1)) + min;
        /*si on affiche le 0 alors le joueur va jouer avec le noir et l'ordinateur va jouer
        avec le  blanc ;et si on s'affiche 1 le joueur va jouer en blanc  et l'ordinateur en noir*/

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
void menu2()
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
    printf("Veuillez entrer un nombre: \n");
    scanf("%d",&choix);
    if(choix==1)
    {
        joueur_ordi_moy(); /*appel de la fonction joueur_joueur*/
    }

    if(choix==2)
    {
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

/*La fonction bonne_position permet de trouver
les bonnes positions pour que l'ordinateur gagne au moins
un pion c'est à dire retourne au moins un pion du joueur ,et s'il ne trouve
pas de positions gagnantes il joue aléatoirement*/

void bonne_position(char grille[][8],int joueur)
{
   int vois_ligne = 0;            /* indice des lignes voisines  */
   int vois_colonne = 0;          /*indice des colonnes voisines */
   int ligne = 0;                 /* indice de la ligne de la case traitée*/
   int colonne = 0;               /* indice de la colonne de la case traitée*/
   int x = 0;                     /* parcours de ligne pour rechercher */
   int y = 0;                     /* parcours de colonne pour rechercher */
   char  ordinateur= (joueur == 'N')? 'B' : 'N'; /*connaitre le pion de l'ordinateur*/
   int nbr=0;                /*Conteur de bonne position*/



   /* on trouve les bonnes positions pour que l'ordinateur gangne au moins un pion*/
   /* une bonne position doit etre vide et doit encadrer au moins un pion
   du joueur ente deux pions de l'ordinateur */
   for(ligne = 0; ligne < 8; ligne++)
   {
     for(colonne = 0; colonne < 8; colonne++)
     {
       if(grille [ligne][colonne] != '\0')   /* on verifie que c'est une case vide*/
         continue;

       /*on cherche dans les cases voisines de cette case vide un pion du joueur */
       for(vois_ligne = -1; vois_ligne <= 1; vois_ligne++)
         for(vois_colonne = -1; vois_colonne <= 1; vois_colonne++)
         {
           /* pour ne pas chercher hors grille */
           if(ligne+ vois_ligne < 0 || ligne + vois_ligne >= 8||
              colonne + vois_colonne < 0 || colonne + vois_colonne >= 8 ||(vois_ligne==0 && vois_colonne==0))
                    continue;

           /* Si on trouve un pion joueur on continue a chercher dans la meme direction les pions du joueur */
           if(grille[ligne + vois_ligne][colonne + vois_colonne] ==joueur)
           {
             x =ligne + vois_ligne;                /* on passe a la case du pion joueur*/
             y = colonne + vois_colonne;

             /* on cherche dans la meme direction un pion du joueur*/
             for(;;)
             {
               x += vois_ligne;                  /*on passe a la case suivante*/
               y += vois_colonne;
               /* on ne doit pas sortir de la grille*/
               if(x < 0 || x >= 8 || y < 0 || y >= 8)
                 break;

               /*si on trouve une case vide on stoppe*/
               if(grille[x][y] == '\0')
                 break;

                /*si on trouve un pion de l'ordinateur alors c'est une bonne position */
               if(grille[x][y] == ordinateur)
               {
                 grille[ligne][colonne]=ordinateur;/*on pose le pion de l'ordinateur*/
                 retournement(grille,ligne,colonne,ordinateur);/*on fait le retournement*/
                 othellier(grille);/*on affiche la grille*/
                 nbr=1;            /*on affecte à nbr 1 c'est à dire on a
                                    trouver une bonne position,le retournement est assuré*/
                 break;
               }
             }
           }

         }
        if (nbr==1) /*si on a trouver une bonne position on arrete de chercher*/
             break;
      }
      if (nbr==1) /*si on a trouver une bonne position on arrete de chercher*/
             break;

    }
  if (nbr==0) /*si on ne trouve pas aucune bonne position qui assure
                     un retournement alors on choisit une case aléatoire*/
  { coordonnees position[64];
    int k = remplir_tab(position, grille);  /*indice de parcours des lignes du tableau*/

    int indiceAleat=rand()%k;/*choisir une ligne aléatoire du tableau c'est à dire une case vide aléatoire*/
    grille[position[indiceAleat].abs][position[indiceAleat].ord]=ordinateur;/*on affecte à la grille la position choisie par l'ordinateur*/
    retournement(grille,position[indiceAleat].abs,position[indiceAleat].ord,ordinateur);/*on fait le retournement s'il exite*/
    othellier(grille);/*affichage du nouveau othellier avec
                                       les nouvelles modifications*/

        }
  nbr=0;
  return 0;

}

/*fonction principle de la partie joueur_ordinateur implementant
une intelligence artificielle moyenne*/
void joueur_ordi_moy()
{
  printf("Veuillez entrer un chiffre entre 1 et 8 suivi d'une lettre entre 'a' et 'h'\n");
  char grille[8][8] = { 0 };
  int ligne = 0;                    /*indice de la ligne */
  int colonne = 0;                  /*indice de la colonne*/
  int nbr_fin = 0;                  /*variable pour indiquer la fin*/
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
  nbr=Randoms1(min, max, count,&joueur,&ordinateur);

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

    bonne_position(grille,'N');
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
   bonne_position(grille,'B');
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
     menu2();/*appel de la fonction menu*/

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
     joueur_ordi_moy();/*appel de la fonction joueur_ordi_moy */
}
return 0;
}

