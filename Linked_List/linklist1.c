#include<stdio.h>
#include<stdlib.h>


struct node
{
    int info;
    struct node * link;
};

struct node *add_at_beg(struct node * start)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    int n;
    scanf("%d",&n);
    tmp->info=n;
    tmp->link=start;
    start=tmp;
    return start;
}

struct node* add_at_end(struct node *start)
{
    struct node *p,*tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    int n;
    scanf("%d",&n);

    p=start;
    //now traverse upto when p->link != NULL
    while(p->link!=NULL)
    {
        p=p->link;
    }
    p->link=tmp;
    tmp->link=NULL;
    tmp->info=n;
    return start;
};

void traverse(struct node * start)
{
    struct node * p=start;
    if(start==NULL)
        printf("Empty list\n");
    else
    {
        while(p!=NULL)
        {
            printf("%d ",p->info);
            p=p->link;
        }
        printf("\n");
    }
}

void count(struct node * start)
{
    struct node * p =start;
    if(start==NULL)
        printf("Empty list\n");
    else
    {
       int counts=0;
       while(p!=NULL)
       {

            p=p->link;
            counts++;
       }
       printf("Number of nodes are %d\n",counts);
    }
}

void search(struct node * start,int item)
{
    struct node *p=start;
    if(start==NULL)
        printf("Empty list\n");
    else
    {
        int pos=1;
        while(p!=NULL)
        {
            if(p->info==item)
            {
                printf("item at position %d\n",pos);
                return;
            }

            pos++;
            p=p->link;
        }
        printf("Element not in list\n");
    }
}

int main()
{
    struct node * start=NULL;
    traverse(start);
    start=add_at_beg(start);
    start=add_at_beg(start);
    traverse(start);
    int item;
    printf("Enter item to search: ");
    scanf("%d",&item);
    search(start,item);
    count(start);

    start=add_at_end(start);
    traverse(start);
    count(start);
}
