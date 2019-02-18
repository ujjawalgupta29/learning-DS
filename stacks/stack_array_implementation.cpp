#include<bits/stdc++.h>
using namespace std;

int stack_arr[10];
int top =-1;

int isFull()
{
    if(top == 9)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

void push()
{
    if(isFull())
    {
        cout<<"Stack overflow"<<endl;
        return;
    }
    cout<<"Enter element you want to insert: ";
    int element;
    cin>>element;

    top = top +1;
    stack_arr[top] = element;
}

void pop()
{
    if(isEmpty())
    {
        cout<<"Stack underflow"<<endl;
        return;
    }
    int item;
    item = stack_arr[top];
    top--;
    cout<<"Element popped out is :- "<<item<<endl;
}

void display()
{
    if(top == -1)
    {
        cout<<"Stack empty"<<endl;
        return ;
    }
    cout<<"Displaying stack contents:- "<<endl;
    for(int i=top;i>=0;i--)
        cout<<stack_arr[i]<<" ";
    cout<<endl;
}

void upper()
{
    cout<<"Top is at position :- "<<top<<endl;
    cout<<"Element at top is:- "<<stack_arr[top]<<endl;
}

int main()
{
    int choice;
    cout<<"Select an operation for stack"<<endl;
    cout<<"1. Push an element\n2. Pop an element\n3. Display scenario of top\n4. Print stack\n5. Exit"<<endl;

    while(1)
    {
       cin>>choice;
       if(choice == 1)
            push();
       else if(choice == 2)
            pop();
       else if(choice == 3)
            upper();
       else if(choice == 4)
            display();
       else
            exit(1);
    }
}
