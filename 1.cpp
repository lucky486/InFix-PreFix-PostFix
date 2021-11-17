#include <iostream>
#include <algorithm>
using namespace std;
class Node
{
public:
    int data;
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

int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

// The main function to convert infix expression to postfix expression
void infixToPostfix(string infix)
{

    Stack st;
    string postfix;

    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];

        // If the scanned character is an operand, add it to output string.
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            postfix += c;
        }
        // If the scanned character is an ‘(‘, push it to the stack.
        else if (c == '(')
        {
            st.push('(');
        }
        // If the scanned character is an ‘)’, pop and to output string from the stack until an ‘(‘ is encountered.
        else if (c == ')')
        {
            while (st.top->data != '(')
            {
                postfix += st.top->data;
                st.pop();
            }
            st.pop();
        }
        //If an operator is scanned
        else
        {
            while (!st.empty() && precedence(infix[i]) <= precedence(st.top->data))
            {
                postfix += st.top->data;
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.empty())
    {
        postfix += st.top->data;
        st.pop();
    }

    cout << postfix << endl;
}
int main()
{
    string str;
    cout<<"Enter the infix expression  :  ";
    cin>>str;
    cout<<"Postfix Expression  :  ";
    infixToPostfix(str);
    return 0;
}
