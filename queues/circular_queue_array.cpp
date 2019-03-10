#include<bits/stdc++.h>
using namespace std;

int a[10];
int first =-1,rear =-1;

int main()

{

    int choice ;
    cout<<"Queues:"<<endl;
    cout<<"1. Insert an element"<<endl<<"2. Delete an element"<<endl<<"3. Display queue"<<endl<<"4. Exit"<<endl;


    while(1)
    {
        cout<<endl<<"Select a function : ";
        cin>>choice;

        if(choice == 1)
        {
            int info;

            if( (rear == 9 && first == 0)  || (  first == rear+1 ) )
            {
                cout<<"overflow"<<endl;
            }
            else
            {
                cout<<"Enter element to be inserted: ";
                cin>>info;

                if(first == -1 && rear == -1)
                {
                    first++;
                    rear++;
                    a[rear] = info;
                }
                else if(rear == 9)
                {
                    rear = 0;
                    a[rear] = info;
                }
                else
                {
                    rear++;
                    a[rear] = info;
                }
            }


        }

        if(choice == 2)
        {
            if(first == -1 && rear == -1)
            {
                cout<<"underflow"<<endl;
            }


            else if(first == rear )
            {
                first = -1;
                rear = -1;
            }
            else if(first == 9)
            {
                first = 0;
            }

            else
                first++;
        }

        if(choice == 3)
        {
            if(first == -1 && rear == -1)
            {
                cout<<"underflow"<<endl;
            }
            else if(first <= rear )
            {
                for(int i= first; i<=rear ; i++)
                {
                    cout<<a[i]<<" ";
                }
                cout<<endl;
            }

            else
            {
                for(int i= first; i<=9 ; i++)
                {
                    cout<<a[i]<<" ";
                }
                for(int i= 0; i<=rear ; i++)
                {
                    cout<<a[i]<<" ";
                }
                cout<<endl;
            }
        }

        if(choice == 4)
            exit(0);
    }
}
