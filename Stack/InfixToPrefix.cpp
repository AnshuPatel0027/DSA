#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// function to check if a character is an operator
bool isOperator(char c) 
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// function to get precedence of an operator
int getPrecedence(char c)
{
    if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

// function to convert infix expression to postfix expression
string infixToPostfix(string infix)
{
    stack<char> s;
    string postfix;

    for (int i = 0; i < infix.length(); i++) 
    {
        char c = infix[i];
        if (isalnum(c))
            postfix += c;
        else if (isOperator(c)) 
        {
            while (!s.empty() && s.top() != '(' && getPrecedence(s.top()) >= getPrecedence(c)) 
            {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
        else if (c == '(') 
        {
            s.push(c);
        }
        else if (c == ')') 
        {
            while (!s.empty() && s.top() != '(') 
            {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(')
                s.pop();
        }
    }

    while (!s.empty()) 
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

// main function
int main()
{
    string infix, postfix;
    cout << "Enter infix expression: ";
    getline(cin, infix);
    postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
