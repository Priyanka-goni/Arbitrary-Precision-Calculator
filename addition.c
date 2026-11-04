#include "apc.h"

extern int sign1;
extern int sign2;
extern int flag;

int addition(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR)
{
    int ret;
    if(sign1 == sign2)
    {
        Dlist *temp1 = *tail1;
        Dlist *temp2 = *tail2;
        int carry = 0;
        int data;
        while (temp1 != NULL || temp2 != NULL)
        {
            if (temp1 != NULL && temp2 != NULL)
            {
                data = temp1->data + temp2->data + carry;
                temp1 = temp1->prev;
                temp2 = temp2->prev;
            }
            else if (temp1 != NULL)
            {
                data = temp1->data + carry;
                temp1 = temp1->prev;
            }
            else
            {
                data = temp2->data + carry;
                temp2 = temp2->prev;
            }
            if (data > 9)
            {
                data = data % 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            if (insert_first(headR, tailR, data) == FAILURE)
            {
                return FAILURE;
            }
        }
        if (carry)
        {
            if (insert_first(headR, tailR, carry) == FAILURE)
            {
                return FAILURE;
            }
        }
        flag = (sign1 == -1) ? 1 : 0;
        if (*headR != NULL && (*headR)->data == 0 && *headR == *tailR)
        {
            flag = 0;
        }
        return SUCCESS;
    }
    ret = list_compare(*head1, *head2);
    if(ret == 0)
    {
        if (insert_last(headR, tailR, 0) == FAILURE)
        {
            return FAILURE;
        }
        flag = 0;
        return SUCCESS;
    }
    int original_sign1 = sign1;
    int original_sign2 = sign2;
    sign1 = 1;
    sign2 = 1;
    if (ret > 0)
    {
        if (subtraction(head1, tail1,head2, tail2,headR, tailR) == FAILURE)
        {
            sign1 = original_sign1;
            sign2 = original_sign2;
            return FAILURE;
        }
        flag = (original_sign1 == -1) ? 1 : 0;
    }
    else
    {
        if (subtraction(head2, tail2,head1, tail1,headR, tailR) == FAILURE)
        {
            sign1 = original_sign1;
            sign2 = original_sign2;
            return FAILURE;
        }
        flag = (original_sign2 == -1) ? 1 : 0;
    }
    sign1 = original_sign1;
    sign2 = original_sign2;
    if(*headR != NULL &&(*headR)->data == 0 && *headR == *tailR)
    {
        flag = 0;
    }
    return SUCCESS;
}