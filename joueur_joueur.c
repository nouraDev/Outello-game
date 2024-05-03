#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

/*fichier qui concerne la premiere partie humain-humain*/


/*C’est une fonction codée à l’aide de la bibliothèque Windows ,
elle permet de colorer l’arrière plan, les publipostages et tout texte souhaité*/
void color(int couleurDuTexte, int couleurDeFond)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurDeFond*16+couleurDuTexte);
}
/*C’est la fonction qui affiche(printf) le nom du jeu
« Othello » en couleur en utilisant la fonction void color.*/
void bienvenu(){
srand((time(NULL)));
color(14,4);
printf("\n\n");
color(1,0);
printf("\t  OOOOOOOOO      TTTTTTTTTTT   H        H    EEEEEEEE    L          L              OOOOOOOOO \n"); color(6,0);
printf("\t O         O          T        H        H    E           L          L             O         O \n");color(11,0);
printf("\tO           O         T        H        H    E           L          L            O           O \n");color(6,0);
printf("\tO           O         T        HHHHHHHHHH    EEEEEEEE    L          L            O           O \n");color(11,0);
printf("\tO           O         T        H        H    E           L          L            O           O \n");color(6,0);
printf("\t O         O          T        H        H    E           L          L             O         O \n");color(11,0);
printf("\t  OOOOOOOOO           T        H        H    EEEEEEEE    LLLLLLLL   LLLLLLLL       OOOOOOOOO\n\n\n\n");color(6,0);
}
/*elle permet d’orienter le joueur en donnant trois propositions (commencer/aide/quitter)*/
void menu()
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
        joueur_joueur(); /*appel de la fonction joueur_joueur*/
    }

    if(choix==2)
    {
        printf("Veuillez entrer un chiffre entre 1 et 8 suivi d'une lettre entre 'a' et 'h'\n");
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
        {printf("A La Prochaine\n");}
}

/*cette fonction donne aléatoirement à chaque joueur une couleur du pion (noir ou blanc) par
l’appel de la fonction aléatoire rand() qui fait le choix entre 2 valeurs min=0 et max=1*/
void printRandoms(int min, int max,int count)
{   int i;
    for (i = 0; i < count; i++)
    {
        int num = (rand() %

        (max - min + 1)) + min;
        /*si on affiche le 0 alors le joueur1  va jouer avec le noir et le joueur2  va jouer avec le  blanc ;
        et si on s'affiche 1 le joueur1 va jouer en blanc  et le joueur2 en noir*/

         if (num==0)
              printf("Le joueur 1 jouera avec: N\nLe joueur 2 jouera avec: B ");

         else
              printf("Le joueur 1 jouera avec: B\nLe joueur 2 jouera avec: N ");
    }

}

char grille[8][8] = { 0 };

/*fonction qui permet d'afficher la grille*/
void othellier(char grille[][8])
{
   int i = 0;          /*Pour parcourir la ligne*/
   int j = 0;          /* pour parcourir la colonne */
   char k = 'a';       /*  noms de colonne*/

   printf("\n ");

   for(j = 0 ; j<8 ;j++)
       printf("   %c", k+j); /* affichage des noms de colonne */

   printf("\n");
   /*dresser la grille*/

   for(i = 0; i < 8; i++)
   {
        printf("  *");
        for(j = 0; j<8; j++)
              printf("****");

        printf("\n%2d|",i + 1);  /* affichage des noms des lignes */

        for(j= 0; j<8; j++)
             printf(" %c |", grille[i][j]); /*pour differencier les colonnes et créer les cases*/
        printf("\n");
   }

   printf("  *"); /*tabulation pour decaller un peu la grille vers la droite*/

   for(j = 0 ; j<8 ;j++)

       printf("****"); /*les lignes de la grille*/

   printf("\n");

}
/*c'est une fonction qui permet d’effectuer un retournement des pions ,
lorsque deux pions de même couleur encadre horizontalement,
diagonalement  ou  verticalement  des pions de l’autre couleur  (Prise en Sandwich)*/
void retournement(char grille[][8], int ligne, int colonne, char joueur)

{
   int vois_ligne = 0;                   /* indice des lignes voisines */
   int vois_colonne = 0;                  /* indice des colonnes voisines*/
   int x1=0;                              /* parcours de ligne pour rechercher */
   int y1=0;                              /* parcours de colonne pour rechercher */
   char  adversaire= (joueur == 'N')? 'B' : 'N';  /* L'adversaire du joueur qui a le tour*/
   grille[ligne][colonne] = joueur;           /* La pose*/

   /*chercher dans les cases voisines les pions de l'adversaire*/

    for( vois_ligne = -1; vois_ligne  <= 1; vois_ligne ++)
        for(vois_colonne = -1; vois_colonne<= 1; vois_colonne++)
          {
              /* pour ne pas chercher hors l'othellier,ou dans la position choisie*/
              if(ligne + vois_ligne  < 0 || ligne + vois_ligne  >= 8 ||
                 colonne + vois_colonne < 0 || colonne + vois_colonne >= 8||(vois_ligne ==0 && vois_colonne== 0))
                    continue;

              /* on verfie l'existance du pion adverse*/
              /* s'il trouve un pion adversaire on continue à chercher dans la meme
                 direction un pion du joueur qui a le tour*/
              if(grille[ligne + vois_ligne ][colonne + vois_colonne] == adversaire)
                {
                  /*on se deplace à la position du pion adversaire*/
                  x1 = ligne + vois_ligne ;
                  y1 = colonne + vois_colonne;
                  for(;;)
                    {   /*on passe à la case suivante*/
                      x1 += vois_ligne ;
                      y1 += vois_colonne;
                      /* s'il depasse la grille on stoppe*/
                      if(x1 < 0 || x1 >= 8 || y1 < 0 || y1 >= 8)
                          break;
                      /*si on trouve une case vide on stoppe*/
                      if(grille[x1][y1] == ' ')
                          break;
                      /* si on trouve un pion du joueur,on revient dans la meme direction
                      pour changer tout les pions de l'adversaire en pions du joueur */
                      if(grille[x1][y1] == joueur)
                      {
                       while(grille[x1-=vois_ligne ][y1-=vois_colonne]==adversaire)
                            grille[x1][y1] = joueur;    /* on change les pions adversaires*/
                            break;
                      }
                    }
               }
        }
}
/*fonction qui permet de calculer le score ,de l'afficher et d'afficher le gagnant*/
void score()
{
int i=0; /* parcours des lignes*/
int j=0;/* parcours des colonnes*/
int score_blanc=0;
int score_noir=0;
{
   for(i=0;i<8;i++)      /*on parcours la grille*/
        {for(j=0;j<8;j++)
           {
            if (grille[i][j]=='N')/* si on trouve un pion noir on ajoute 1 au score_noir*/
               {
                   score_noir=score_noir+1;
               }
            if (grille[i][j]=='B')/* si on trouve un pion blanc on ajoute 1 au score_blanc*/
               {
                   score_blanc=score_blanc+1;
               }
           }
        }
}
/*affichage du score*/
printf("Le score du joueur noir est %d\n",score_noir);
printf("Le score du joueur blanc est %d\n",score_blanc);
/*affichage du gangnat*/
if(score_blanc>score_noir)/*sile score blanc est le supperieur le blanc est gagnant*/
    {printf("Le blanc est le gagnant ! \n");
    printf("\t\t\t\tYYY    YYY  OOOOO    U     U    W       W       W    IIIIIII   N    N \n ");color(11,0);
    printf("\t\t\t\t  YY  YY   O     O   U     U     W     W W     W        I      N N  N  \n");color(6,0);
    printf("\t\t\t\t    YY     O     O   U     U      W   W   W   W         I      N  N N  \n");color(11,0);
    printf("\t\t\t\t    YY     O     O   U     U       W W     W W          I      N    N  \n");color(6,0);
    printf("\t\t\t\t    YY      OOOOO     UUUUU         W       W        IIIIIII   N    N  \n");color(11,0);
    }
else
    {printf("Le noir est le gagnant !\n");/*sile score blanc est le supperieur le noir est gagnant*/
    printf("\t\t\t\tYYY    YYY  OOOOO    U     U    W       W       W    IIIIIII   N    N \n ");color(11,0);
    printf("\t\t\t\t  YY  YY   O     O   U     U     W     W W     W        I      N N  N  \n");color(6,0);
    printf("\t\t\t\t    YY     O     O   U     U      W   W   W   W         I      N  N N  \n");color(11,0);
    printf("\t\t\t\t    YY     O     O   U     U       W W     W W          I      N    N  \n");color(6,0);
    printf("\t\t\t\t    YY      OOOOO     UUUUU         W       W        IIIIIII   N    N  \n");color(11,0);
    }

}

/*Cette fonction principale dans laquelle se déroule la partie joueur vs joueur*/
void joueur_joueur()
{

  printf("Veuillez entrer un chiffre entre 1 et 8 suivi d'une lettre entre 'a' et 'h'\n");

  int ligne = 0;                    /*indice de la ligne */
  int colonne = 0;                  /*indice de la colonne*/
  int nbr_poses = 2;                /*nombre des cases remplies*/
  char y = 0;                       /* lettre de la colonne choisie du joueur1 */
  int x = 0;                        /* nombre de la ligne choisie du joueur1 */
  char z=0;                         /* lettre de la colonne choisie du joueur2 */
  int w=0;                          /* nombre de la ligne choisie du joueur2 */
  int min = 0, max = 1, count = 1;
  int i, j;
  int choix2=0;

  /*utuliser le temp comme origine de random*/
  srand(time(0));
  printRandoms(min, max, count);

  grille[3][3] = grille[4][4] = 'B'; /*remplissage des quatres premieres cases de l'othellier*/
  grille[3][4] = grille[4][3] = 'N';

  othellier(grille); /*affichage initial de la grille*/

  do{

    nbr_poses=nbr_poses+1; /*on incremente le nombres de cases remplies par 1*/
    printf("Le noir veuillez choisir  une position : ");
    scanf("%d %c", &x, &y);       /* lire et stocker la position choisie en x et y */
    y = tolower(y) - 'a';         /* on convertit la lettre de colonne en indice de colonne */
    x--;                          /*on convertit le nombre choisie en indice de ligne */

    grille[x][y]='N';             /*affectation à la position choisie le pion noir*/
    retournement(grille,x,y,'N'); /*on fait le retournement s'il exite*/
    othellier(grille);            /*affichage du nouveau othellier avec
                                        les nouvelles modifications*/
    printf("Le blanc veuillez choisir  une position : ");
    scanf("%d %c", &w, &z);        /* lire et stocker la position choisie en w et z*/
    z = tolower(z) - 'a';          /* on convertit la lettre de colonne en indice de colonne */
    w--;                           /*on convertit le nombre choisie en indice de ligne */
    grille[w][z]='B';              /*affectation à la position choisie le pion noir*/
    retournement(grille,w,z,'B');  /*on fait le retournement s'il exite*/
    othellier(grille);              /*affichage du nouveau othellier avec
                                        les nouvelles modifications*/

  }while(nbr_poses< 32);

  score();
  printf("Si vous voulez revenir au menu tapez 1:\n");
  printf("Si vous voulez rejouer tapez 2:\n");
  scanf("%d",&choix2);/*stocker le choix du joueur dans la variable choix2*/
  if(choix2==1)
  {
     for (i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                grille[i][j]=' ';/*vidation de la grille*/
            }
        }
     menu();/*appel de la fonction menu*/

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
     joueur_joueur();/*appel de la fonction joueur_joueur*/
  }
}


