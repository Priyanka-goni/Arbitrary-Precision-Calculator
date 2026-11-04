#ifndef APC_H
#define APC_H
#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
}Dlist;

extern int sign1;
extern int sign2;
extern int flag;
int digit_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[]);

/*Addition */
int addition(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*subtraction*/
int subtraction(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*multiplication*/
int multiplication(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*division*/
int division(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

int insert_first(Dlist **head,Dlist **tail,int data);

int insert_last(Dlist **head, Dlist **tail, int data);

void print_list(Dlist *head);

int list_compare(Dlist *head1,Dlist *head2);

void delete_list(Dlist **head, Dlist **tail);

#endif