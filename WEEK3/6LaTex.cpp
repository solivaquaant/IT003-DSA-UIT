#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool KiemTraNgoac(string str)
{
    stack<char> s;
    for (char c : str)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            s.push(c);
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            if (s.empty())
                return false;
            char top = s.top();
            s.pop();
            if ((top == '(' && c != ')') ||
                (top == '{' && c != '}') ||
                (top == '[' && c != ']'))
            {
                return false;
            }
        }
    }
    return s.empty();
}

int main()
{
    string str;
    getline(cin, str);
    if (KiemTraNgoac(str))
    {
        cout << "1" << endl;
    }
    else
    {
        cout << "0" << endl;
    }
    return 0;
}
