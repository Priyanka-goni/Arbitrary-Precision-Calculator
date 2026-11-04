#include "apc.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *headR = NULL, *tailR = NULL;
    extern int flag;
    if (argc != 4)
    {
        printf("Usage: ./a.out <number1> <operator> <number2>\n");
        return FAILURE;
    }
    char operator = argv[2][0];
    switch (operator)
    {
        case '+':

            if (digit_to_list(&head1, &tail1,&head2, &tail2, argv) == FAILURE)
            {
                printf("Invalid operand\n");
                return FAILURE;
            }

            if (addition(&head1, &tail1,&head2, &tail2,&headR, &tailR) == FAILURE)
            {
                printf("Addition failed\n");
                return FAILURE;
            }

            if (flag == 1 && headR != NULL &&!(headR->data == 0 && headR == tailR))
            {
                printf("-");
            }
            print_list(headR);
            break;
        case '-':
            if (digit_to_list(&head1, &tail1,&head2, &tail2, argv) == FAILURE)
            {
                printf("Invalid operand\n");
                return FAILURE;
            }
            if (subtraction(&head1, &tail1,&head2, &tail2,&headR, &tailR) == FAILURE)
            {
                printf("Subtraction failed\n");
                return FAILURE;
            }
            if (flag == 1 && headR != NULL && !(headR->data == 0 && headR == tailR))
            {
                printf("-");
            }
            print_list(headR);
            break;
        case 'x':
            if (digit_to_list(&head1, &tail1,&head2, &tail2, argv) == FAILURE)
            {
                printf("Invalid operand\n");
                return FAILURE;
            }
            if (multiplication(&head1, &tail1,&head2, &tail2,&headR, &tailR) == FAILURE)
            {
                printf("Multiplication failed\n");
                return FAILURE;
            }
            if (flag == 1 && headR != NULL &&!(headR->data == 0 && headR == tailR))
            {
                printf("-");
            }
            print_list(headR);
            break;
        case '/':
            if (digit_to_list(&head1, &tail1,&head2, &tail2, argv) == FAILURE)
            {
                printf("Invalid operand\n");
                return FAILURE;
            }
            Dlist *temp = head2;
            int all_zero = 1;
            while(temp != NULL)
            {
                if(temp->data != 0)
                {
                    all_zero = 0;
                    break;
                }
                temp = temp->next;
            }
            if (all_zero)
            {
                printf("Error: Division by zero\n");
                return FAILURE;
            }
            if (division(&head1, &tail1,&head2, &tail2,&headR, &tailR) == FAILURE)
            {
                printf("Division failed\n");
                return FAILURE;
            }
            if (flag == 1 && headR != NULL &&!(headR->data == 0 && headR == tailR))
            {
                printf("-");
            }
            print_list(headR);
            break;
        default:
            printf("Invalid operator\n");
            printf("Use +, -, x or /\n");
            return FAILURE;
    }
    return SUCCESS;
}