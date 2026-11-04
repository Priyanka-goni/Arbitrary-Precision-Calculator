#include "apc.h"

extern int flag;
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    int ret=0;
    if(sign1!=sign2)
    {
    Dlist *temp1=*tail1;
    Dlist *temp2=*tail2;
    int carry=0;
    int data;
    while(temp1 || temp2)
    {
        if(temp1 && temp2)
        {
            data=temp1->data + temp2->data + carry;
            temp1=temp1->prev;
            temp2=temp2->prev;
        }
        else if(temp1!=NULL)
        {
            data=temp1->data + carry;
            temp1=temp1->prev;
        }
        else
        {
            data=temp2->data + carry;
            temp2=temp2->prev;
        }
        if(data>9)
        {
            data=data%10;
            carry=1;
        }
        else
        {
            carry=0;
        }
        insert_first(headR, tailR, data);
    }
    if (carry)
    {
        insert_first(headR,tailR,carry);
    }
    if(sign1==-1)
    {
        flag=1;
    }
    else
    {
        flag=0;
    }
    return SUCCESS;
}
    ret = list_compare(*head1, *head2);
    if(ret==0)
    {
        insert_last(headR,tailR, 0);
		flag=0;
        return SUCCESS;
    } 
    if(ret==-1)
    {
        flag = 1;
        Dlist *tempH = *head1;
        Dlist *tempT = *tail1;
        *head1 = *head2;
        *tail1 = *tail2;
        *head2 = tempH;
        *tail2 = tempT;
        if(sign1==1)
        {
            flag=1;
        }
        else
        {
            flag=0;
        }
    }
	else
	{
        if(sign1==-1)
        {
            flag=1;
        }
        else
        {
            flag=0;
        }
	}
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;
    int borrow = 0;
    int diff;
    while (temp1 != NULL)
    {
        int d1 = temp1->data;
        int d2 = 0;
        if (temp2 != NULL)
        {
            d2 = temp2->data;
        }
        d1 = d1 - borrow;
        if (d1<d2)
        {
            d1 += 10;
            borrow=1;
        }
        else
        {
            borrow=0;
        }
        diff=d1-d2;
        insert_first(headR, tailR, diff);
        temp1=temp1->prev;
        if (temp2 != NULL)
        {
            temp2 = temp2->prev;
        }
    } 
    while(*headR!=NULL && (*headR)->data==0 && *headR!=*tailR)
    {
        Dlist *del=*headR;
        *headR=(*headR)->next;
        (*headR)->prev=NULL;
        free(del);
    }
    return SUCCESS; 
}