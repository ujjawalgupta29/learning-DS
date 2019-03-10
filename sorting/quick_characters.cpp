#include<bits/stdc++.h>
using namespace std;

void print(char a[])
{
    for(int i=0;i<7;i++)
        cout<<a[i];
    cout<<endl;
}

int partitions(char a[],int start,int last)
{
    char pivot = a[last];
    int pindex = start;

    for(int i=start;i<last;i++)
    {
        if( int(a[i]) <= int(pivot) )
        {
            swap(a[i],a[pindex]);
            pindex++;
        }
    }
    swap(a[pindex],a[last]);
    return pindex;
}

void quick(char a[],int start,int last)
{
    if(start < last)
    {
        int pindex = partitions(a,start,last);
        //cout<<"pindex= "<<pindex<<endl;

        quick(a,start,pindex-1);
        //cout<<"start= "<<start<<" end= "<<last<<endl;
        //print(a);

        quick(a,pindex+1,last);
        //cout<<"start= "<<start<<" end= "<<last<<endl;
        //print(a);
    }
}


int main()
{
    char a[] = {'E','X','A','M','P','L','E'};
    quick(a,0,6);
    print(a);
}
