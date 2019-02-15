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

struct node * add_after(struct node * last)
{
    printf("Enter data of node after which node to be inserted:- ");
    int data;
    scanf("%d",&data);
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data for node to be inserted after selected node:- ");
    int n;
    scanf("%d",&n);
    temp->info = n;

    struct node * p = last->link;

    do
    {
        if(p->info == data)
        {
            temp->link = p->link;
            p->link = temp;
            if( p == last)
                last = temp;

            return last;
        }
        p= p->link;

    }while(p != last->link);
    printf("Element not found\n");
    return last;
};

struct node * add_before(struct node * last)
{
    printf("Enter data of node before which node to be inserted:- ");
    int data;
    scanf("%d",&data);
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data for node to be inserted after selected node:- ");
    int n;
    scanf("%d",&n);
    temp->info = n;

    struct node * p = last->link;

    do
    {
        if(last->link->info == data)
        {
            last = add_at_beg(last);
            return last;
        }
        if(p->link->info == data)
        {
            temp->link = p->link;
            p->link = temp;
            return last;
        }
        p = p->link;
    }while(p != last->link);

    printf("Element not found\n");
    return last;
};

struct node * delete_node(struct node * last)
{
    printf("Enter data of node to be deleted:- ");
    int data;
    scanf("%d",&data);
    if(last == NULL)
    {
        printf("List is Empty\n");
        return last;
    }

    //to delete only node
    if(last->info == data && last->link == last)
    {
        struct node *p = last;
        last = NULL;
        free(p);
        return last;
    }
    //to delete first noe
    if(last->link->info == data)
    {
        struct node *p = last->link;
        last->link = p->link;
        free(p);
        return last;
    }
    struct node *p =last->link;
    while(p->link != last)
    {
        if(p->link->info == data)
        {
            struct node * temp =p->link;
            p->link = temp->link ;
            free(temp);
            return last;
        }
        p = p->link;
    }
    //deleting last node
    if(last->info == data)
    {
        struct node * temp = last;
        p->link = last->link;
        last = p;
        free(temp);
        return last;
    }
    printf("Element not found\n");
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

void counts(struct node * last)
{
    if(last == NULL)
    {
        printf("Number of nodes:- 0\n");
        return ;
    }
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

    int choice;

    printf("1. Traverse\n");
    printf("2. Count nodes\n");
    printf("3. Add to empty list\n");
    printf("4. Add at beginning\n");
    printf("5. Add at end\n");
    printf("6. Add after an element\n");
    printf("7. Add before an element\n");
    printf("8. Delete\n");
    printf("9. Quit\n");

    while(1)
    {

        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            {
                traverse(last);
                break;
            }

        case 2:
            {
                counts(last);
                break;
            }
        case 3:
        {
            last=add_to_empty(last);
            break;
        }

        case 4:
            {
                last=add_at_beg(last);
                break;
            }
        case 5:
            {
                last=add_at_end(last);
                break;
            }
        case 6:
            {

                last=add_after(last);
                break;
            }
        case 7:
            {

                last=add_before(last);
                break;
            }

        case 8:
            {

                last=delete_node(last);
                break;
            }
        case 9:
            {
                exit(1);
            }
        }

}
}
