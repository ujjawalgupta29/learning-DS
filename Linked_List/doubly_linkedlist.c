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

struct node * add_at_end(struct node * start)
{
    struct node *p =start;
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data to be inserted at end:- ");
    int n;
    scanf("%d",&n);


    while(p->next != NULL)
    {
        p = p->next;
    }
    temp->info = n;
    //printf("check1\n");
    temp->next = NULL;
    //printf("check2\n");
    temp->prev = p;
    //printf("check3\n");

    if(start != NULL)
        p->next = temp;

    //printf("check4\n");
    return start;
};

struct node * add_after(struct node * start)
{
    printf("Data of node after which new node to be inserted:- ");
    int data;
    scanf("%d",&data);
    printf("Enter data to be inserted after selected node:- ");
    int n;
    scanf("%d",&n);

    struct node *p =start;
    struct node * temp = (struct node *)malloc(sizeof(struct node));

    while(p->info != data)
    {
        p = p->next;
    }
    temp->info = n;
    temp->next = p->next;
    temp->prev = p;

    p->next->prev = temp;
    p->next = temp;

    return start;
};

struct node * add_before(struct node * start)
{
    printf("Data of node before which new node to be inserted:- ");
    int data;
    scanf("%d",&data);
    printf("Enter data to be inserted after selected node:- ");
    int n;
    scanf("%d",&n);

    struct node *p =start;
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->info = n;

    while(p->info != data)
    {
        p = p->next;
    }

    temp->prev = p->prev;
    temp->next = p;

    p->prev->next = temp;
    p->prev = temp;

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
    start = add_at_end(start);
    start = add_at_end(start);
    start = add_after(start);
    start = add_before(start);
    start = add_before(start);
    traverse(start);
    counts(start);
}
