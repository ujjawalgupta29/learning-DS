#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *prev;
    struct node *next;
};

struct node * add_at_beg(struct node * start)
{
    struct node * temp = (struct node *)malloc(sizeof(struct node ));
    printf("Enter data to be inserted at beg:- ");
    int n;
    scanf("%d",&n);

    if(start == NULL)
    {
        temp->info = n;
        temp->prev = NULL;
        temp->next = NULL;
        start = temp;

    }

    else
    {

        temp->info = n;
        temp->prev = NULL;
        temp->next = start;
        start->prev = temp;
        start = temp;

    }

    return start;
};

void traverse(struct node *start)
{
    struct node * p = start;
    while(p != NULL)
    {
        printf("%d ",p->info);
        p = p->next;
    }
    printf("\n");
}

void counts(struct node *start)
{
    struct node * p = start;
    int number=0;
    while(p != NULL)
    {
        //printf("%d ",p->info);
        number++;
        p = p->next;
    }
    printf("Number of nodes:- %d \n",number);
}

int main()
{
    struct node * start = NULL;

    start = add_at_beg(start);
    traverse(start);
    counts(start);
}
