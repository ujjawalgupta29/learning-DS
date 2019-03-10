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

int apply_operation(int value1,int value2, char ch)
{
    switch (ch)
    {
        case '-': return value1-value2;
        case '+': return value1+value2;
        case '*': return value1*value2;
        case '/': return value1/value2;
        case '^': return pow(value1,value2);
    }
    return -1;
}

void postfix(string s)
{

    stack <char> operations;
    string post;


    for(int i = 0 ;i < s.length() ; i++)
    {
        char ch = s[i];
        //cout<<"ch= "<<ch<<endl;
        if(ch  == ' ')
        {
            //cout<<"space"<<endl;
            continue;
        }

        else if(ch == '(')
            operations.push(s[i]);

        // if character is an operand
        else if(  (s[i] <= 'z' && s[i] >= 'a') || (s[i] <= 'Z' && s[i] >= 'A')  )
        {
            //cout<<"operand"<<endl;
            post = post + ch;
        }

        else if(ch == ')')
        {

            while( !operations.empty() && operations.top() != '(')
            {
                char character = operations.top();
                operations.pop();
                post = post + character;

            }
            operations.pop();

        }

        //if we encounter a operator
        else
        {

            while(!operations.empty() &&  operations.top() != '(' && precedence(s[i]) <= precedence(operations.top()) )
            {
                char character = operations.top();
                operations.pop();
                post = post + character;

            }

            operations.push(ch);

        }

    }

    while(!operations.empty())
    {
        char character = operations.top();
        operations.pop();
        post = post + character;
    }

    cout<<post<<endl;

}


int main()
{
    string s;
    cout<<"Enter expression to be converted: "<<endl;
    getline(cin,s);

    postfix(s);
}
