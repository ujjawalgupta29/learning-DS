#include<bits/stdc++.h>
using namespace std;

int precedence(char ch)
{
    if(ch == '+' || ch == '-')
        return 1;
    if(ch == '*' || ch == '/')
        return 2;
    if(ch == '^')
        return 3;

    return 0;
}


int main()
{
    string s;
    cout<<"Enter expression to be converted: "<<endl;
    getline(cin,s);

    cout<<postfix(s);
}
