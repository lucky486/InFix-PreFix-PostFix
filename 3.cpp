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
bool isOperand(char c)
{
    // If the character is a digit then it must
    // be an operand
    return isdigit(c);
}

double evaluatePrefix(string s)
{
    Stack st;

    for (int j = s.size() - 1; j >= 0; j--)
    {

        // Push operand to Stack
        // To convert s[j] to digit subtract
        // '0' from s[j].
        if (isOperand(s[j]))
        {
            st.push(s[j] - '0');
        }
        else
        {

            // Operator encountered
            // Pop two elements from Stack
            double o1 = st.top->data;
            st.pop();
            double o2 = st.top->data;
            st.pop();

            // Use switch case to operate on o1
            // and o2 and perform o1 O o2.
            switch (s[j])
            {
            case '+':
                st.push(o1 + o2);
                break;
            case '-':
                st.push(o1 - o2);
                break;
            case '*':
                st.push(o1 * o2);
                break;
            case '/':
                st.push(o1 / o2);
                break;
            }
        }
    }

    return st.top->data;
}
int main()
{
    string str;
    cout << "Enter the prefix expression  :  ";
    cin >> str;
    cout << "Answer  : " << evaluatePrefix(str) << endl;
    return 0;
}
