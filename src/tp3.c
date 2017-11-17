/* Auteurs : ZETEA Lucas & LÉCLUSE Thomas */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "tp3.h"

// Définition des fonctions de service utiles
bool is_list_empty(List *list) {  // Renvoie si la liste d'éléments est vide (si tête=queue)
	return list->head == list->tail;
}

Element *cutNumber(char *str, int n) {
	// Découpe un nombre représenté par une chaîne de caractères en éléments de 5 charactères
	Element *new = malloc(sizeof(Element));
	new->data = malloc(sizeof(char)*5);
	new->next = malloc(sizeof(Element));

	// Si il y a plus de 5 chiffres de str, il faut découper la chaîne
	if (n < strlen(str) && strlen(str) >= 5) {
		strncpy(new->data, str+n, 5);  // Permet de copier le contenu de str à partir du nième charactère et sur une longueur de 5 dans new->data
		new->next = cutNumber(str, n+5);  // On réitère l'opération pour placer tous les chiffres dans les éléments
	}
	else {  // Quand on arrive à la fin de la chaîne (il y a moins de 5 chiffres)
		new->data = "/";
		new->next = NULL;
	}

	return new;
}

Element *goToEnd(Element *e) {  // Renvoie un pointeur sur le dernier élément d'une chaîne d'éléments
	if (e->next != NULL) return goToEnd(e->next);
	return e;
}

void freeElements(Element *e) {
	if (e) {
		freeElements(e->next);
		free(e);
	}
}


// Définition des fonctions usuelles
void initialize(List *list) {
	Element *new = malloc(sizeof(Element));
	list->head = new;
	list->tail = new;
}

void insert_empty_list(List *list, char *str) {
	if (is_list_empty(list)) {
		Element *new = cutNumber(str, 0);  // On est obligé de stoquer le résultat afin de pouvoir le libérer par la suite

		list->head = new;
		list->tail = goToEnd(list->head);
	}
}

void insert_begining_list(List *list, char *str) {
	if (is_list_empty(list)) {  // Si la liste est vide, on utilise la fonction pour insérer dans une liste vide
		insert_empty_list(list, str);
	} else {
		Element *new = cutNumber(str, 0);  // On formate le nombre (pas + de 5 chiffres par éléments)

		goToEnd(new)->next = list->head;  // On définit la suite du dernier élément qui représente notre nombre comme étant la liste précédente
		list->head = new;  // On fait pointer la tête de la liste sur notre nouvel élément.
	}
}

void insert_end_list (List *list, char *str) {
	if (is_list_empty(list)) {  // Si la liste est vide, on insère au début.
		insert_empty_list(list, str);
	} else {
		Element *new = cutNumber(str, 0);  // On formate le nombre de la même manière que pour l'insertion au début.

		list->tail->next = new;  // On se place à la fin de la liste et on ajoute le nouvel élément comme suivant
		list->tail = goToEnd(new);  // On n'oublie pas de placer la queue de liste à la fin du nouvel élément, qui correspond à la fin de la liste
	}
}

int insert_after_position(List *list, char *str, int p) {
	return 0;
}

void display(List *list) {
	if (is_list_empty(list)) {
		printf("EMPTY LIST\n");
	} else {
		for (Element *e = list->head; e; e=e->next) {
			printf("%s ", e->data);
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
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
