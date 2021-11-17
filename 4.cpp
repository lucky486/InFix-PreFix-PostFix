#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    float data;
    Node *next;
};
class Stack
{
public:
    Node *top = NULL;
    bool empty();
    void push(int);
    void pop();
};
bool Stack ::empty()
{
    if (top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Stack ::push(int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = top;
    top = new_node;
}
void Stack ::pop()
{
    if (empty())
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        Node *temp = top;
        top = top->next;
        delete (temp);
    }
}
float scanNum(char ch)
{
    int value;
    value = ch;
    return float(value - '0'); //return float from character
}
int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
    {
        return 1; //character is an operator
    }
    else
    {
        return -1; //not an operator
    }
}
int isOperand(char ch)
{
    if (ch >= '0' && ch <= '9')
    {
        return 1; //character is an operand
    }
    else
    {
        return -1; //not an operand
    }
}
float operation(int a, int b, char op)
{
    //Perform operation
    if (op == '+')
    {
        return b + a;
    }
    else if (op == '-')
    {
        return b - a;
    }
    else if (op == '*')
    {
        return b * a;
    }
    else if (op == '/')
    {
        return b / a;
    }
    else if (op == '^')
    {
        return pow(b, a); //find b^a
    }
    else
    {
        return INT_MIN; //return negative infinity
    }
}
float postfixEval(string postfix)
{
    int a, b;
    Stack st;
    for (int i = 0; i < postfix.length(); i++)
    {
        //read elements and perform postfix evaluation
        if (isOperator(postfix[i]) != -1)
        {
            a = st.top->data;
            st.pop();
            b = st.top->data;
            st.pop();
            st.push(operation(a, b, postfix[i]));
        }
        else if (isOperand(postfix[i]) > 0)
        {
            st.push(scanNum(postfix[i]));
        }
    }
    return st.top->data;
}
int main()
{
    string str;
    cout << "Enter the PostFix Expression : ";
    cin >> str;
    cout << "Answer: " << postfixEval(str);
    return 0;
}
