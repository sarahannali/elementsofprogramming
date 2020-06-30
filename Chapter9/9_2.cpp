#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int RPNEvaluator(const string& str)
{
    stack<double> values;
    stringstream ss(str);
    string value;
    const char delimiter = ',';

    while (getline(ss, value, delimiter))
    {
        cout << "value: " << value << '\n';
        if (value == "+" || value == "-" || value == "*" || value == "/")
        {
            int y = values.top();
            values.pop();
            int x = values.top();
            values.pop();

            if (value == "+")
            {
                values.push(x+y);
            }
            else if (value == "-")
            {
                values.push(x-y);
            }
            else if (value == "*")
            {
                values.push(x*y);
            }
            else
            {
                values.push(x/y);
            }

        }
        else
        {
            values.push(stoi(value));
        }
    }

    return values.top();
}

int main()
{
    string str = "-2,3,*";
    cout << RPNEvaluator(str);
}