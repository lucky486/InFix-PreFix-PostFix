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

int prec(char c)
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

bool isOperator(char c)
{
    return (!isalpha(c) && !isdigit(c));
}

string infixToPostfix(string infix)
{
    infix = '(' + infix + ')';
    int l = infix.size();
    Stack st;
    string output;

    for (int i = 0; i < l; i++)
    {

        // If the scanned character is an
        // operand, add it to output.
        if (isalpha(infix[i]) || isdigit(infix[i]))
            output += infix[i];

        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (infix[i] == '(')
            st.push('(');

        // If the scanned character is an
        // ‘)’, pop and output from the stack
        // until an ‘(‘ is encountered.
        else if (infix[i] == ')')
        {
            while (st.top->data != '(')
            {
                output += st.top->data;
                st.pop();
            }

            // Remove '(' from the stack
            st.pop();
        }

        // Operator found
        else
        {
            if (isOperator(st.top->data))
            {
                if (infix[i] == '^')
                {
                    while (prec(infix[i]) <= prec(st.top->data))
                    {
                        output += st.top->data;
                        st.pop();
                    }
                }
                else
                {
                    while (prec(infix[i]) < prec(st.top->data))
                    {
                        output += st.top->data;
                        st.pop();
                    }
                }

                // Push current Operator on stack
                st.push(infix[i]);
            }
        }
    }
    while (!st.empty())
    {
        output += st.top->data;
        st.pop();
    }
    return output;
}

string infixToPrefix(string infix)
{
    /* 1. Reverse String
       2. Replace ( with ) and vice versa
       3. Get Postfix
       4. Reverse Postfix   
    */
    int l = infix.size();

    // Reverse infix
    reverse(infix.begin(), infix.end());

    // Replace ( with ) and vice versa
    for (int i = 0; i < l; i++)
    {

        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
    }

    string prefix = infixToPostfix(infix);

    // Reverse postfix
    reverse(prefix.begin(), prefix.end());

    return prefix;
}

int main()
{
    string str;
    cout << "Enter the infix expression  :  ";
    cin >> str;
    cout << "Prefix Expression  :  " << infixToPrefix(str);
    return 0;
}
