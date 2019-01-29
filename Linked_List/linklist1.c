#include<stdio.h>
#include<stdlib.h>


void clrscr()
{
    system("@cls||clear");
}
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

struct node* add_before(struct node * start,int item,int data)
{
    struct node *p,*tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->info=data;
    if(start==NULL)
    {
        printf("List is empty\n");
        return start;
    }
    p=start;
    if(start->info==item)
    {
        tmp->link=start;
        start=tmp;
        return start;
    }
    while(p!=NULL)
    {
        if(p->link->info==item)
        {
            tmp->link=p->link;
            p->link=tmp;
            return start;
        }
        else
            p=p->link;
    }
    printf("Element not found\n");
    return start;

}

struct node * add_after(struct node* start,int item,int data)
{
    struct node *p,*tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->info=data;
    if(start==NULL)
    {
        printf("List is empty\n");
        return start;
    }
    p=start;
    while(p!=NULL)
    {
        if(p->info==item)
        {
            tmp->link=p->link;
            p->link=tmp;
            return start;
        }
        p=p->link;
    }
    printf("Element not found\n");
    return start;
}

struct node *add_at_pos(struct node* start,int pos,int data)
{
    struct node *p,*tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    if(pos==NULL)
    {
        printf("position specified is NULL\n");
        return start;
    }
    tmp->info=data;
    if(pos==1)
    {
        tmp->link=start;
        start=tmp;
        return start;
    }
    p=start;
    for(int i=1;i<pos-1;i++)
    {
        p=p->link;
    }
    tmp->link=p->link;
    p->link=tmp;
    return start;
}
//Deletion in linked list
struct node *del(struct node * start,int item)
{
    struct node *p,*tmp;

    if(start==NULL)
    {
        printf("List is empty\n");
        return start;
    }
    if(start->info==item)
    {
        tmp=start;
        start=start->link;
        free(tmp);
        return start;
    }
    p=start;
    while(p->link!=NULL)
    {
        if(p->link->info==item)
        {
            tmp=p->link;
            p->link=tmp->link;
            free(tmp);
            return start;
        }
        p=p->link;
    }
    printf("Element not found\n");
    return start;
}
//Reversing the list
struct node *reversing(struct node *start)
{
    struct node *prev,*ptr,*next;
    prev=NULL;
    ptr=start;
    while(ptr!=NULL)
    {
        next=ptr->link;
        ptr->link=prev;
        prev=ptr;
        ptr=next;
    }
    start=prev;
    return start;
};

int main()
{
    struct node * start=NULL;
    int item,data,choice;
    while(1)
    {
        printf("1. Traverse\n");
        printf("2. Count nodes\n");
        printf("3. Search\n");
        printf("4. Add at beginning\n");
        printf("5. Add at end\n");
        printf("6. Add after an element\n");
        printf("7. Add before an element\n");
        printf("8. Add at specific position\n");
        printf("9. Delete\n");
        printf("10. Reverse the list\n");
        printf("11. Quit\n");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            {
                traverse(start);
                break;
            }

        case 2:
            {
                count(start);
                break;
            }
        case 3:
            {
                printf("Enter element to search: ");
                scanf("%d",&item);
                search(start,item);
                break;
            }
        case 4:
            {
                start=add_at_beg(start);
                break;
            }
        case 5:
            {
                start=add_at_end(start);
                break;
            }
        case 6:
            {
                printf("Enter data: ");
                int n;
                scanf("%d",&n);
                printf("Enter item: ");

                scanf("%d",&item);
                start=add_after(start,item,n);
                break;
            }
        case 7:
            {
                printf("Enter data: ");
                int n;
                scanf("%d",&n);
                printf("Enter item: ");

                scanf("%d",&item);
                start=add_before(start,item,n);
                break;
            }
        case 8:
            {
                printf("Enter data: ");
                int n;
                scanf("%d",&n);
                printf("Enter position: ");
                int pos;
                scanf("%d",&pos);
                start=add_at_pos(start,pos,n);
                break;
            }
        case 9:
            {
                printf("Enter item: ");

                scanf("%d",&item);
                start=del(start,item);
                break;
            }
        case 10:
            {
                start=reversing(start);
                break;
            }
        case 11:
            {
                exit(1);
            }
        }

    }
}
