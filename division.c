#include "apc.h"

extern int sign1;
extern int sign2;
extern int flag;

int division(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR)
{
    Dlist *trav = *head1;
    Dlist *result_head = NULL;
    Dlist *result_tail = NULL;
    Dlist *sub_head = NULL;
    Dlist *sub_tail = NULL;
    int count;
    int result_sign;
    int original_sign1 = sign1;
    int original_sign2 = sign2;
    Dlist *temp = *head2;
    int divisor_zero = 1;
    while (temp != NULL)
    {
        if(temp->data != 0)
        {
            divisor_zero = 0;
            break;
        }
        temp = temp->next;
    }
    if (divisor_zero)
    {
        printf("Error: Division by zero\n");
        return FAILURE;
    }
    result_sign = (sign1 != sign2);
    delete_list(headR, tailR);
    while (trav != NULL)
    {
        if (insert_last(&result_head, &result_tail,trav->data) == FAILURE)
        {
            delete_list(&result_head, &result_tail);
            return FAILURE;
        }
        while (result_head != NULL && result_head->data == 0 && result_head != result_tail)
        {
            Dlist *temp = result_head;
            result_head = result_head->next;
            if (result_head != NULL)
            {
                result_head->prev = NULL;
            }
            free(temp);
        }
        count = 0;
        sign1 = 1;
        sign2 = 1;
        while (result_head != NULL && list_compare(result_head, *head2) >= 0)
        {
            if (subtraction(&result_head, &result_tail,head2, tail2,&sub_head, &sub_tail) == FAILURE)
            {
                delete_list(&result_head, &result_tail);
                delete_list(&sub_head, &sub_tail);
                sign1 = original_sign1;
                sign2 = original_sign2;
                return FAILURE;
            }
            delete_list(&result_head, &result_tail);
            result_head = sub_head;
            result_tail = sub_tail;
            sub_head = NULL;
            sub_tail = NULL;
            count++;
        }
        if(count != 0 || *headR != NULL)
        {
            if(insert_last(headR, tailR, count) == FAILURE)
            {
                delete_list(&result_head, &result_tail);
                sign1 = original_sign1;
                sign2 = original_sign2;
                return FAILURE;
            }
        }
        trav = trav->next;
    }
    if(*headR == NULL)
    {
        insert_last(headR, tailR, 0);
    }
    while(*headR != NULL &&(*headR)->data == 0 && *headR != *tailR)
    {
        Dlist *temp = *headR;
        *headR = (*headR)->next;
        if (*headR != NULL)
        {
            (*headR)->prev = NULL;
        }
        free(temp);
    }
    if (*headR != NULL &&(*headR)->data == 0 && *headR == *tailR)
    {
        flag = 0;
    }
    else
    {
        flag = result_sign;
    }
    sign1 = original_sign1;
    sign2 = original_sign2;
    delete_list(&result_head, &result_tail);
    return SUCCESS;
}