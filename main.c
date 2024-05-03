#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

/*remarque: pour jouer une deuxième fois dans un  mode de jeu diférent
veuillez reexécutez le programme et rechoisir le mode de jeu */
int main()
{
        bienvenu(); /*appel de la fonction bienvenu*/
        srand((time(NULL)));
         color(11,0);/*fonction C’est une fonction codée à l’aide de la bibliothèque Windows ,
                      elle permet de colorer l’arrière plan, les publipostages et tout texte souhaité*/
         printf("\t\t\t\t _________________________\n");color(11,0);
         printf("\t\t\t\t|     1-joueur-joueur     |\n");color(11,0);
         printf("\t\t\t\t|_________________________|\n");color(11,0);
         printf("\t\t\t\t _________________________\n");color(11,0);
         printf("\t\t\t\t|    2-joueur-ordinateur  |\n");color(11,0);
         printf("\t\t\t\t|         facile          |\n");color(11,0);
         printf("\t\t\t\t|_________________________|\n");color(11,0);
         printf("\t\t\t\t _________________________\n");color(11,0);
         printf("\t\t\t\t|   3-joueur-ordinateur   |\n");color(11,0);
         printf("\t\t\t\t|          moyen          |\n");color(11,0);
         printf("\t\t\t\t|_________________________|\n");color(6,0);

    int jouer=0;
    int i, j;
    printf("Veuillez entrer un nombre: ");
    scanf("%d",&jouer);/*lire et stocker le choix du joueur dans la variable jouer*/
    if(jouer==1)
    {
        menu();           /*appel de la fonction menu pour afficher le menu de joueur_joueur*/
        joueur_joueur(); /*appel de la fonction joueur_joueur*/
    }

    if(jouer==2)
    {
        menu1();/*appel de la fonction menu1 pour afficher le menu de joueur-ordinateur facile*/
        joueur_ordinateur();/*appel de la fonction joueur_ordinateur*/
    }

    if(jouer==3)
    {

        menu2();/*appel de la fonction menu2 pour afficher le menu de joueur-ordinateur moyen*/
        joueur_ordi_moy();/*appel de la fonction joueur_ordinateur-moyen*/
    }

return 0;
}
