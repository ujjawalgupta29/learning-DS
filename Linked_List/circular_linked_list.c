#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node * link;
};

struct node * add_to_empty(struct node * last)
{
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data for first node:- ");
    int n;
    scanf("%d",&n);
    temp->info = n;

    last = temp;
    temp->link = temp;
    return last;
};

struct node * add_at_beg(struct node * last)
{
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data for node to be inserted at beg:- ");
    int n;
    scanf("%d",&n);
    temp->info = n;

    temp->link = last->link;
    last->link = temp;

    return last;
};

struct node * add_at_end(struct node *last)
{

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data for node to be inserted at end:- ");
    int n;
    scanf("%d",&n);
    temp->info = n;

    temp->link = last->link;
    last->link = temp;
    last = temp;

    return last;
};

struct node *

void traverse(struct node * last)
{
    struct node * p ;
    if(last == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    p= last->link;
    do
    {
        printf("%d ",p->info);
        p= p->link;
    }while(p != last->link);
    printf("\n");
}

void counts(struct node * last)
{
    struct node * p = last->link;
    int numbers=0;
    do
    {
        numbers++;
        //printf("%d ",p->info);
        p = p->link;
    }while(p != last->link);
    printf("Number of nodes:- %d \n",numbers);
}

int main()
{
    struct node *last = NULL;

    last = add_to_empty(last);
    last = add_at_beg(last);
    traverse(last);
    counts(last);
    last = add_at_end(last);
    last = add_at_end(last);
    last = add_at_end(last);
    traverse(last);
    counts(last);
}
