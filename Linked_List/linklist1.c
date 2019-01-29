#include<stdio.h>
#include<stdlib.h>


struct node
{
    int info;
    struct node * link;
};

struct node *add_at_beg(struct node * start)
{
    struct node * tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    int n;
    scanf("%d",&n);
    tmp->info=n;
    tmp->link=start;
    start=tmp;
    return start;
}

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

int main()
{
    struct node * start=NULL;
    traverse(start);
    start=add_at_beg(start);
    start=add_at_beg(start);
    traverse(start);
}
