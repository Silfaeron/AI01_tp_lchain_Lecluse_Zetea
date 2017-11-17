#include <stdlib.h>
#include <stdio.h>
#include "tp3.h"


int main(int argc, char const *argv[])
{

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
	freeElements(l->head);
	free(l);
	return 0;
}
