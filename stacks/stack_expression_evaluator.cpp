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

int calculate(string s)
{

    stack <char> operations;
    stack <int> values;

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

        else if(  isdigit(s[i])  )
        {
            //cout<<"value aayi"<<endl;
            int value=0;

            while(i < s.length() && isdigit(s[i]) )
            {
                value = value*10 + (s[i] - '0');
                i++;
            }
            //cout<<"value= "<<value<<endl;

            values.push(value);
            //cout<<endl<<"printing in loop"<<endl;

            i--;
        }

        else if(ch == ')')
        {
            //cout<<endl<<"pop ( 1"<<endl;
            while( !operations.empty() && operations.top() != '(')
            {
                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = operations.top();
                operations.pop();

                values.push(apply_operation(val1, val2, op));

            }
            //cout<<"pop ("<<endl;
            operations.pop();
        }

        else
        {
            //while( !operations.empty() /*&& (precedence(s[i]) <= precedence(operations.top()) || operations.top()== '(') */ &&  (ch == '*' || ch == '/' || ch == '+' || ch == '-' || ch == '^') )
            while(!operations.empty() &&  operations.top() != '(' && precedence(s[i]) <= precedence(operations.top()) )
            {
                //string temp = to_string(operations.top() );
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = operations.top();
                operations.pop();
                values.push(apply_operation(val1, val2, op));
            }


            operations.push(ch);
        }

    }

    while(!operations.empty())
    {
        int val2 = values.top();
        values.pop();
        int val1 = values.top();
        values.pop();
        char op = operations.top();
        operations.pop();
        values.push(apply_operation(val1, val2, op));
    }

    return values.top();
}

int main()
{
    string s;
    cout<<"Enter expression to be evaluated: "<<endl;
    getline(cin,s);

    cout<<calculate(s);
}
