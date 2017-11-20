/* Auteurs : ZETEA Lucas & LÉCLUSE Thomas */

#include "tp3.h"


// Permet de récupérer le nombre de l'utilisateur
// On ne connait pas forcément la taille de ce nombre, d'où l'intérêt d'avoir une telle fonction
char *getInput(){
  char *chaine = malloc(sizeof(char));
  int c;
  int i = 0;
  bool verif = true;
  printf("\nVeuillez entrer votre nombre : ");

  c = getchar();
  while((c = getchar()) != '\n' && c != EOF){ // tant que l'utilisateur n'a pas appuyé sur entrée, on continue de lire son input
    if(verif){
      if(c != '0' && c-'0'>=0 && c-'0'<=9){
        *(chaine+i) = c;
        i++;
        chaine = realloc(chaine, i+1);
        verif = false;
      }
    }else if(c-'0'>=0 && c-'0'<=9){
      *(chaine+i) = c;
      i++;
      chaine = realloc(chaine, i+1);
    }
  }
  *(chaine+i) = '\0'; // on rajoute à la fin de la chaine le charactere de terminaison (utile pour la suite)

  return chaine;
}

// Cette fonction permet de récupérer la position que l'utilisateur veut indiquer
// Ici n est le nombre de nombres dans la liste
int askPos(int n, int *p){
  printf("\nVeuillez indiquer la position souhaitee : ");
  if(scanf("%d", p) == 0) return 0; // si le scanf a détécté un char en début de saisie, la saisie est invalidée

  if(*p > n || *p < 0) return 0; // si la position n'est pas valide, la saisie est invalidée

  return 1;
  /* Ce bout de code peut être ammélioré car si par exemple l'utilisateur entre "1C2",
    on récupérera quand même 1. Pour l'amélioration, il faudrait récupérer une chaine de characteres
    et vérifier charactere par charactere pour s'assurer de la validité de l'input.
  */
}


int main(int argc, char const *argv[]){

  List *l = malloc(sizeof(List));
  initialize(l);

  int choice = 1;
  int pos = 0;

  printf("\n\n################### TP Listes Chainees ###################\n\t~~~~ by Thomas LECLUSE & Lucas ZETEA ~~~~\n\n");
  printf("Une liste a ete initalisee pour vous (elle est vide)....\n");

  while (choice != 0){
    printf("\n\t---Menu principal---\n\t\t"\
        "1 - ajouter un nombre en debut de liste\n\t\t" \
        "2 - ajouter un nombre en fin de liste\n\t\t" \
        "3 - ajouter un nombre a une certaine position\n\t\t" \
        "4 - supprimer le nombre a une certaine position\n\t\t" \
        "5 - trier la liste par ordre croissant\n\t\t" \
        "6 - afficher l'état actuel de la liste\n\t\t" \
        "7 - detruire la liste\n\t\t" \
        "0 - quitter\n\n\tVotre choix : ");

    scanf("%d", &choice);

    switch(choice) {
      case 0 :
        printf("\nArret en cours...affichage de l'etat puis destruction de la liste....\n");
        break;
      case 1 :
        insert_begining_list(l, getInput());
        break;
      case 2 :
        insert_end_list(l, getInput());
        break;
      case 3 :
        if(askPos(countElements(l->head), &pos) == 1){
          printf("\nInsertion en cours....\n");
          insert_after_position(l, getInput(), pos);
        }else printf("Position non valide, retour au menu principal...\n");
        break;
      case 4 :
        if(askPos(countElements(l->head), &pos) == 1){
          printf("\nSuppression en cours...\n");
          removeElement(l, pos);
        }else printf("Position non valide, retour au menu principal...\n");
        break;
      case 5 :
        printf("\nTri en cours...\n" );
        sort(l);
        break;
      case 6 :
        printf("\nEtat de la liste :\n" );
        break;
      case 7 :
        printf("\nDestruction de la liste...retour a l'etat initial...\n" );
        destruct(l);
        l = malloc(sizeof(List));
        initialize(l);
        break;
      default :
        printf("\nVotre choix n'est pas valide...reaffichage du menu principal...\n" );
        break;
      }
    display(l);
  }

  destruct(l);
}
