#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"


void initialize(List *list)
{
    list = malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
}

void insert_empty_list(List *list, char *str)
{
    int i, k, n=0, nbr_ele, modulo;
    Element* temp = malloc(sizeof(Element));
    temp = NULL;
    n=strlen(str);
    modulo=n%MAX;
    nbr_ele=n/MAX;
    for (i=nbr_ele ; i >= 0 ; i++) {
        Element* Nouvel_Element = malloc(sizeof(Element));
        if (nbr_ele-i > 0)
            strncpy(Nouvel_Element->data, str, MAX);
        else
            strncpy(Nouvel_Element->data, str, modulo);

        if (i==0)
            list->head = Nouvel_Element;
        else if (i==nbr_ele)
            list->tail = Nouvel_Element;

        Nouvel_Element->next = temp;
        temp->next = Nouvel_Element;
    }
    free(temp);
}

/*void insert_begining_list(List *list, char *str){
=======
void insert_begining_list(List *list, char *str){
>>>>>>> 4d14afa13f1013c8039f2f15a1392cea50bcb4ca
	Element *new = malloc(sizeof(Element));
	int n = strlen(str);
	int resteelem = n%MAX;
	float nbelem = n/MAX;
	if(nbelem > 1)
	else{
		strncpy(new->data, str, n);
		list->head = new;
	}

}

void insert_end_list(List *list, char *str){

}

int insert_after_position(List *list, char *str, int p){

}

int remove(List *list, int p){

}

int sort(List *list){

}*/

void display(List *list)
{
    Element *elm = list->head;
    while(elm->next != NULL) {
        printf("%s\n", elm->data);
        elm = elm->next;
    }
}

void destruct(List *list)
{

}

void sum(List *list)
{

}

int main()
{
    char str[MAX];
    List liste;
    initialize(&liste);
    printf("Entrez un nombre :\n");
    scanf("%s", str);
    insert_empty_list(&liste, str);
    display(&liste);
    return 0;
}
