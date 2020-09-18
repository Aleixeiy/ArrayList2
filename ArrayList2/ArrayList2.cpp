#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

struct elem {
    int num;
    struct elem* next;
};

void del(elem *x, elem *head){
    struct elem *current= head;
    while ((current->next != x) && (current->next!=NULL))
        current = current->next;

    if (current == head)
    {
        struct elem* last = head;
        do {
            last = last->next;
        } while (last->next!=head->next);
        last->next = last->next->next;
    }

    if (current->next == current->next->next)
        head->next = NULL;
    else current->next= current->next->next;
}

int main()
{
    

    printf("Enter K\n");
    int N, K;
    scanf("%d", &K);
    for (N = 1; N <= 64; N++)
    {
        printf("%d) ", N);
        struct elem* current = (struct elem*)malloc(sizeof(struct elem));
        struct elem* head = current;

        for (int i = 1; i <= N; i++)
        {
            struct elem* x = (struct elem*)malloc(sizeof(struct elem));
            current->next = x;
            x->num = i;
            x->next = NULL;
            current = x;
        }

        current->next = head->next;
        current = head;

        do {
            int i = 0;
            do {
                current = current->next;
                i++;
            } while (i != K);
            printf("%d ", current->num);
            del(current, head);
        } while (head->next != NULL);
        printf("\n");
    }
}
