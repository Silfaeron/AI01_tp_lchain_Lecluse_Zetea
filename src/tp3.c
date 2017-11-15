/* Auteurs : ZETEA Lucas & LÉCLUSE Thomas */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "tp3.h"

// Définition des fonctions de service utiles
bool is_list_empty(List *list) {
	return list->head == list->tail;
}

Element *cutNumber(char *str, int n) {
	// Découpe un nombre représenté par une chaîne de caractères en éléments de 5 charactères
	Element *new = malloc(sizeof(Element));
	new->data = malloc(sizeof(char)*5);
	new->next = malloc(sizeof(Element));

	if (n < strlen(str) && strlen(str) >= 5) {
		strncpy(new->data, str+n, 5);
		new->next = cutNumber(str, n+5);
	}
	else {
		Element *endNumber = malloc(sizeof(Element));
		endNumber->data = "\0";
		endNumber->next = NULL;

		new->data = str+n;
		new->next = endNumber;
	}

	return new;
}

Element *goToEnd(Element *e) {
	if (e->next != NULL) return goToEnd(e->next);
	return e;
}


// Définition des fonctions usuelles
void initialize(List *list) {
	Element *new = malloc(sizeof(Element));
	list->head = new;
	list->tail = new;
}

void insert_empty_list(List *list, char *str) {
	if (is_list_empty(list)) {
		list->head = cutNumber(str, 0);
		list->tail = goToEnd(list->head);
	}
}

void insert_begining_list(List *list, char *str) {
	if (is_list_empty(list)) {  // Si la liste est vide, on utilise la fonction pour insérer dans une liste vide
		insert_empty_list(list, str);
	} else {
		Element *new = cutNumber(str, 0);

		goToEnd(new)->next = list->head;
		list->head = new;
	}
}

void insert_end_list (List *list, char *str) {

}

int insert_after_position(List *list, char *str, int p) {
	return 0;
}

int main(int argc, char const *argv[])
{
	List *l = malloc(sizeof(List));
	initialize(l);

	insert_empty_list(l, "123456789");
	printf("%s.%s.%s.\n", l->head->data, l->head->next->data, l->tail->data);
	insert_begining_list(l, "987");

	printf("%s.%s.%s.%s.%s.\n", l->head->data, l->head->next->data, l->head->next->next->data, l->head->next->next->next->data, l->tail->data);

	return 0;
}
