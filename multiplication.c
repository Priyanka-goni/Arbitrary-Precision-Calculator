#include "apc.h"

extern int sign1;
extern int sign2;
extern int flag;

int multiplication(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR)
{
    Dlist *t1;
    Dlist *t2 = *tail2;
    Dlist *head = NULL;
    Dlist *tail = NULL;
    Dlist *tempRHead = NULL;
    Dlist *tempRTail = NULL;
    int count = 0;
    int original_sign1 = sign1;
    int original_sign2 = sign2;
    while (t2 != NULL)
    {
        t1 = *tail1;
        int carry = 0;
        for(int i = 0; i < count; i++)
        {
            if(insert_first(&head, &tail,0)==FAILURE)
            {
                delete_list(&head, &tail);
                return FAILURE;
            }
        }
        while(t1 != NULL)
        {
            int mul = (t1->data * t2->data) + carry;
            if (insert_first(&head, &tail, mul % 10) == FAILURE)
            {
                delete_list(&head, &tail);
                return FAILURE;
            }
            carry = mul / 10;
            t1 = t1->prev;
        }
        if(carry!= 0)
        {
            if (insert_first(&head, &tail, carry) == FAILURE)
            {
                delete_list(&head, &tail);
                return FAILURE;
            }
        }
        if (count == 0)
        {
            *headR = head;
            *tailR = tail;
            head = NULL;
            tail = NULL;
        }
        else
        {
            sign1 = 1;
            sign2 = 1;
            if (addition(headR, tailR,&head, &tail,&tempRHead, &tempRTail) == FAILURE)
            {
                delete_list(&head, &tail);
                sign1 = original_sign1;
                sign2 = original_sign2;
                return FAILURE;
            }
            delete_list(headR, tailR);
            delete_list(&head, &tail);
            *headR = tempRHead;
            *tailR = tempRTail;
            tempRHead = NULL;
            tempRTail = NULL;
        }
        count++;
        t2 = t2->prev;
    }
    while (*headR != NULL &&(*headR)->data == 0 &&*headR != *tailR)
    {
        Dlist *temp = *headR;
        *headR = (*headR)->next;
        (*headR)->prev = NULL;
        free(temp);
    }
    sign1 = original_sign1;
    sign2 = original_sign2;
    flag = (sign1 != sign2);
    if (*headR != NULL &&(*headR)->data == 0 &&*headR == *tailR)
    {
        flag = 0;
    }
    return SUCCESS;
}