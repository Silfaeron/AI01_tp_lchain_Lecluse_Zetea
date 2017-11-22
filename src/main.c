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

int getChoice(){ // Permet d'avoir une saisie correcte quant au choix de l'utilisateur
  char *ch = malloc(5*sizeof(char));
  int choice = -1;

  scanf("%s", ch);

  if(strlen(ch) > 1) return choice; // on retourne -1 si c'est une chaine de characteres qui a ete rentree
  if(*(ch)-'0' < 0 || *(ch)-'0' > 7) return choice; // on retourne -1 si le choix n'est pas dans l'intervalle adequat ou si ce n'est pas un chiffre

  choice = *(ch)-'0';
  free(ch);

  return choice; // le choix est correct, on le retourne sous forme d'int
}

// Cette fonction permet de récupérer la position que l'utilisateur veut indiquer
// Ici n est le nombre de nombres dans la liste
int askPos(int n, int *p){
  printf("\nVeuillez indiquer la position souhaitée : ");
  *p = getChoice();
  if(*p == -1) return 0; // l'input n'est pas valide, la saisie est invalidee

  if(*p > n-1 || *p < 0) return 0; // si la position n'est pas valide, la saisie est invalidee

  return 1;
}


int main(int argc, char const *argv[]){

  List *l = malloc(sizeof(List));
  initialize(l);

  int choice = 1;
  int pos = 0;

  printf("\n\n################### TP Listes Chainees ###################\n\t~~~~ by Thomas LECLUSE & Lucas ZETEA ~~~~\n\n");
  printf("Une liste a été initalisée pour vous (elle est vide)....\n");

  while (choice != 0){
    printf("\n\t---Menu principal---\n\t\t"\
        "1 - ajouter un nombre en début de liste\n\t\t" \
        "2 - ajouter un nombre en fin de liste\n\t\t" \
        "3 - ajouter un nombre à une certaine position\n\t\t" \
        "4 - supprimer le nombre à une certaine position\n\t\t" \
        "5 - trier la liste par ordre croissant\n\t\t" \
        "6 - afficher l'état actuel de la liste\n\t\t" \
        "7 - détruire la liste\n\t\t" \
        "0 - quitter\n\n\tVotre choix : ");

    choice = getChoice();

    switch(choice) {
      case 0 :
        printf("\nArrêt en cours...affichage de l'état puis destruction de la liste....\n");
        break;
      case 1 :
        insert_begining_list(l, getInput());
        printf("\nInsertion en début de liste...\n");
        break;
      case 2 :
        insert_end_list(l, getInput());
        printf("\nInsertion en fin de liste...\n");
        break;
      case 3 :
        if(!is_list_empty(l)){
          if(askPos(countElements(l->head)+1, &pos) == 1){
            insert_after_position(l, getInput(), pos);
            printf("\nInsertion en cours...\n");
          }else printf("Position non valide, retour au menu principal...\n");
        }else
          printf("\nLa liste étant vide, ce choix n'est pas possible pour le moment...\n");
        break;
      case 4 :
        if(!is_list_empty(l)){
          if(askPos(countElements(l->head), &pos) == 1){
            printf("\nSuppression en cours...\n");
            removeElement(l, pos);
            if (is_list_empty(l)) {
              destruct(l);
              l = malloc(sizeof(List));
              initialize(l);
            }
          }else printf("\nPosition non valide, retour au menu principal...\n");
        }else
          printf("\nLa liste étant vide, ce choix n'est pas possible pour le moment...\n");
        break;
      case 5 :
        if(!is_list_empty(l)){
          printf("\nTri en cours...\n" );
          sort(l);
        } else printf("\nLa liste étant vide, ce choix n'est pas possible pour le moment...\n");
        break;
      case 6 :
        printf("\nÉtat de la liste :\n" );
        break;
      case 7 :
        printf("\nDestruction de la liste...retour a l'état initial...\n" );
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
