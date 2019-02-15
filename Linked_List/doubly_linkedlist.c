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

struct node * delete_node(struct node * start)
{
    printf("Data of node to be deleted:- ");
    int data;
    scanf("%d",&data);
    struct node *p;

    //if list is empty
    if(start == NULL)
    {
        printf("List Empty\n");
        return start;
    }
    //if there is a single node
    if(start->next == NULL)
    {
        if(start->info == data)
        {
            p = start;
            start = NULL;
            free(p);

        }
        else
        {
            printf("Element not found\n");
        }
        return start;
    }

    //to delete first node
    if(start->info == data)
    {
        p = start;
        start->next->prev = NULL;
        start= start->next;
        free(p);
        return start;
    }
    p =start;
    //to delete in between
    while(p->next != NULL)
    {
        if(p->info == data)
        {
            p->next->prev = p->prev;
            p->prev->next = p->next;
            free(p);
            return start;
        }
        p = p->next;
    }

    // to delete from end
    if(p->info == data)
    {
        p->prev->next= NULL;
        free(p);
        return start;
    }
    printf("Element not found\n");
    return start;
};

struct node * reverse_list(struct node * start)
{
    struct node *p1,*p2;
    p1 = start;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;

    while(p2 != NULL)
    {
        p2->prev=  p2->next;
        p2->next = p1;

        p1=p2;
        p2 = p2->prev;
    }
    start = p1;
    printf("List reversed\n");
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
    int choice;

    printf("1. Traverse\n");
    printf("2. Count nodes\n");
    printf("3. Add at beginning\n");
    printf("4. Add at end\n");
    printf("5. Add after an element\n");
    printf("6. Add before an element\n");
    printf("7. Delete\n");
    printf("8. Reverse the list\n");
    printf("9. Quit\n");

    while(1)
    {

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
                counts(start);
                break;
            }

        case 3:
            {
                start=add_at_beg(start);
                break;
            }
        case 4:
            {
                start=add_at_end(start);
                break;
            }
        case 5:
            {

                start=add_after(start);
                break;
            }
        case 6:
            {

                start=add_before(start);
                break;
            }

        case 7:
            {

                start=delete_node(start);
                break;
            }
        case 8:
            {
                start=reverse_list(start);
                break;
            }
        case 9:
            {
                exit(1);
            }
        }

    }

}
