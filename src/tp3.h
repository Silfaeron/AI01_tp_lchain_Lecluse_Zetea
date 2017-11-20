/* Auteurs : ZETEA Lucas & LÉCLUSE Thomas */

typedef struct element {
	char *data;
	struct element *next;
} Element;

typedef struct list {
	Element *head;
	Element *tail;
} List;

void initialize(List *list);
int countElements(Element *e);
void insert_begining_list(List *list, char *str);
void insert_end_list (List *list, char *str);
int insert_after_position(List *list, char *str, int p);
int removeElement(List *list, int p);
int compare(char *str1, char *str2);
int sort(List *list);
void display (List *list);
void destruct(List *list);
