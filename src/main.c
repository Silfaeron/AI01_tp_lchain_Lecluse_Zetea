#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"

void getInput(char *chaine){
  if(chaine != NULL) free(chaine);

  chaine = malloc(sizeof(char));
  char c;
  int i = 0;

  printf("Veuillez entrer votre nombre : \n");

  while(*(chaine+i) != '\n'){
    c = getchar();
    i++;
    *(chaine+i) = c;
    chaine = realloc(chaine, i+1);
  }
  chaine[i] = '\0';
}

int askPos(int n, int *p){
  printf("\nVeuillez indiquer la position souhaitee : ");
  scanf("%d", p);

  if(*p > n || *p < 0 ||)
}


int main(int argc, char const *argv[]){
  /*
  printf("\n\n################### TP Listes Chainees ###################\n\t~~~~ by Thomas LECLUSE & Lucas ZETEA ~~~~\n\n");
	List *l = malloc(sizeof(List));
	initialize(l);

	insert_empty_list(l, "123456789");
	printf("\nFirst :\n");
	display(l);
	//printf("%s.%s.%s.\n", l->head->data, l->head->next->data, l->tail->data);
	insert_begining_list(l, "8888888");
	printf("\nSecond :\n");
	display(l);

	//printf("\nTST\n%s.%s.%s.%s.%s.\n", l->head->data, l->head->next->data, l->head->next->next->data, l->head->next->next->next->data, l->tail->data);
	insert_end_list(l, "1357902468387738573875982305920586028602964862");
	//printf("%s.%s.%s.%s.%s.%s.%s.%s.\n", l->head->data, l->head->next->data, l->head->next->next->data, l->head->next->next->next->data, l->head->next->next->next->next->data, l->head->next->next->next->next->next->data, l->head->next->next->next->next->next->next->data, l->tail->data);
	printf("\nThird :\n");
	display(l);

	insert_after_position(l, "123456", 2);
	printf("\nFourth :\n");
	display(l);

	//removeElement(l, 4);
	printf("\nFifth :\n");
	display(l);

	insert_after_position(l, "12345764376", 3);
	printf("\nSixth :\n");
	display(l);

	insert_after_position(l, "99382974123456", 2);
	printf("\nSeventh :\n");
	display(l);

	insert_after_position(l, "2450123456", 5);
	printf("\nEighth :\n");
	display(l);

	insert_after_position(l, "12", 1);
	printf("\nNineth :\n");
	display(l);

	printf("\n\n\n\n");

  display(l);

	sort(l);
  display(l);

	destruct(l);*/

  List *l = malloc(sizeof(List));
  initialize(l);

  int choice = 1;
  int pos = 0;
  char *chaine = NULL;

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
      printf("\nArret en cours...destruction de la liste....\n");
      break;
    case 1 :
      getInput(chaine);
      insert_begining_list(l, chaine);
      break;
    case 2 :
      getInput(chaine);
      insert_end_list(l, chaine);
      break;
    case 3 :
      getInput(chaine);
      if(askPos(countElements(l), &pos) == 1){
        printf("\nInsertion en cours....\n");
        insert_after_position(l, chaine, pos);
      }else printf("Position non valide, retour au menu principal...\n");
      break;
    case 4 :
      getInput(chaine);
      if(askPos(countElements(l), &pos) == 1){
        printf("\nSuppression en cours...\n");
        removeElement(l, pos);
      }else printf("Position non valide, retour au menu principal...\n");
      printf("You passed\n" );
      break;
    case 5 :
      printf("\nTri en cours...\n" );
      sort(l);
      break;
    case 6 :
      printf("\nEtat de la liste :\n" );
      display(l);
      break;
    case 7 :
      printf("\nDestruction de la liste...\n" );
      destruct(l);
      break;
    default :
      printf("Votre choix n'est pas valide...reaffichage du menu principal...\n" );
    }
    display(l);
  }

  destruct(l);
	return 0;
}
