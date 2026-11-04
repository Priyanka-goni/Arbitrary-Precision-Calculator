#include "apc.h"
#include<stdlib.h>
#include<string.h>

int flag=0;
int sign1=1;
int sign2=1;
int insert_first(Dlist **head,Dlist **tail,int data);
int insert_last(Dlist **head, Dlist **tail, int data);
void print_list(Dlist *head);
int list_compare(Dlist *head1,Dlist *head2);
void delete_list(Dlist **head, Dlist **tail);

int digit_to_list(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,char *argv[])
{
    char *str;
    int data;
    str=argv[1];
    if(*str=='-')
    {
        sign1=-1;
        str++;
    }
    else if(*str=='+')
    {
        sign1=1;
        str++;
    }
    while(*str=='\0')
    {
        return -1;
    }
    while (*str)
    {
        if(*str<'0' || *str>'9')
        {
            return -1;
        }
        data = *str - '0';
        if(insert_last(head1, tail1, data)==-1)
        {
            return -1;
        }
        str++;
    }
    str = argv[3];
    if(*str=='-')
    {
        sign2=-1;
        str++;
    }
    else if(*str=='+')
    {
        sign2=1;
        str++;
    }
    while(*str=='\0')
    {
        return -1;
    }
    while (*str)
    {
        if(*str<'0' || *str>'9')
        {
            return -1;
        }
        data = *str - '0';
        if(insert_last(head2, tail2, data)==-1)
        {
            return -1;
        }
        str++;
    }
    return SUCCESS;
}
int insert_first(Dlist **head,Dlist **tail,int data)
{
	if(*head==NULL)
    {
        Dlist *new=malloc(sizeof(Dlist));
        if(new==NULL)
        {
            return -1;
        }
        new->data=data;
        new->prev=NULL;
        new->next=NULL;
        *head=new;
        *tail=new;
        return 0;
    }
    else
    {
        Dlist *new=malloc(sizeof(Dlist));
        if(new==NULL)
        {
            return -1;
        }
        new->data=data;
        new->next=*head;
        (*head)->prev=new;
        new->prev=NULL;
        *head=new;
        return 0;
    }
}
int insert_last(Dlist **head, Dlist **tail, int data)
{
    if(*head==NULL)
    {
        Dlist *new=malloc(sizeof(Dlist));
        if(new==NULL)
        {
            return -1;
        }
        new->data=data;
        new->next=NULL;
        new->prev=NULL;
        *head=new;
        *tail=new;
        return 0;
    }
    else
    {
        Dlist *new=malloc(sizeof(Dlist));
        if(new==NULL)
        {
            return -1;
        }
        new->data=data;
        new->next=NULL;
        new->prev=*tail;
        (*tail)->next=new;
        *tail=new;
        return 0;
    }
}
void print_list(Dlist *head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while(head != NULL)
    {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}
int list_compare(Dlist *head1,Dlist *head2)
{
    int list1_len=0;
    int list2_len=0;
    Dlist *temp1=head1;
    Dlist *temp2=head2;
    while(temp1!=NULL)
    {
        list1_len++;
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        list2_len++;
        temp2=temp2->next;
    } 
    if(list1_len>list2_len)
    {
        return 1;
    }
    if(list1_len<list2_len)
    {
        return -1;
    }
    temp1=head1;
    temp2=head2;
    while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1->data>temp2->data)
            {
                return 1;
            }
            else if(temp1->data<temp2->data)
            {
                return -1;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return 0;
}
void delete_list(Dlist **head, Dlist **tail)
{
    Dlist *temp;
    while (*head)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    *tail = NULL;
}