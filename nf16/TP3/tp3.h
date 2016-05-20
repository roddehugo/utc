#ifndef TP3_H_INCLUDED
#define TP3_H_INCLUDED
#define MAX 6

//Definition des structures

typedef struct element {
    char data[MAX];
    struct element *next;
} Element;

typedef struct list {
    struct element *head;
    struct element *tail;
} List;

//Définition des fonctions

void initialize(List*);
void insert_empty_list(List*, char*);
void insert_begining_list(List*, char*);
void insert_end_list(List*, char*);
int insert_after_position(List*, char*, int);
//int remove(List*, int);
//int sort(List*);
void display(List*);
void destruct(List*);
void sum(List*);

#endif
//TP3_H_INCLUD
