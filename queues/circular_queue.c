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


int main()
{

}
