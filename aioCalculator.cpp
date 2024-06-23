#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
int a, b;
int extrafun(int operat)
{
    if (operat == 4)
    {
        cout << "Enter number of which you want to find percentage : ";
        cin >> a;
        cout << "Enter the % amount : ";
        cin >> b;
        cout << b << " % of " << a << " will be : " << b % a << endl;
        cout << "please enter 0 to open calculator : ";
        cin >> a;
        if (a == 0)
            return 0;
    }
    cout << "Enter number 1 : ";
    cin >> a;
    cout << "Enter number 2 : ";
    cin >> b;
    if (operat == 1)
    {
        cout << "Addition of " << a << "+" << b << " = " << a + b << endl;
    }
    else if (operat == 2)
    {
        cout << "Product of " << a << "x" << b << " = " << a * b << endl;
    }
    else if (operat == 3)
    {
        cout << "if we divide " << a << " with " << b << " The remainder will be " << a / b << endl;
    }

    cout << "please enter 0 to open calculator : ";
    cin >> a;
    if (a == 0)
        return 0;
}
int reverse_fun()
{
    cout << "Enter number : ";
    cin >> a;
    b = 0;

    while (a > 0)
    {
        b *= 10;
        b += a % 10;
        a = a / 10;
    }

    cout << b;
    cout << "please enter 0 to open calculator : ";
    cin >> a;
    if (a == 0)
        return 0;
}
int sin_fun()
{
    double angle;
    cout << "please enter the angle : ";
    cin >> angle;
    cout << "sin(" << angle << ") = " << sin(angle) << endl
         << endl;
    cout << "please enter 0 to open calculator : ";
    cin >> a;
    if (a == 0)
        return 0;
}
int ln_fun()
{
    double x;
    cout << "Please Enter Number : ";
    cin >> x;

    if (x <= 0)
    {
        return 0.0;
    }

    double result = 0.0;
    double term = (x - 1.0) / (x + 1.0);
    double power = term * term;
    double sum = 0.0;
    int n = 1;

    while (true)
    {
        double currentTerm = 2.0 / n * term;
        if (abs(currentTerm) < 1e-12)
        {
            break;
        }
        sum += currentTerm;
        term *= power;
        n += 2;
    }
    result = sum;
    cout << "ln(" << x << ") = " << result << endl
         << endl;
    cout << "please enter 0 to open calculator : ";
    cin >> a;
    if (a == 0)
        return 0;
}
int perfect_root()
{
    cout << "Enter number : ";
    cin >> a;

    int low = 2;
    int high = a / 2;
    int mid = (low + high) / 2;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (mid * mid == a)
        {
            cout << mid << "x" << mid << " = " << a;
            break;
        }
        if (mid * mid > a)
            high = mid - 1;
        else
            low = mid + 1;
    }
}
void calculator()
{
    cout << endl
         << endl;
    string calculator_structure[2][2];

    calculator_structure[0][0] = "| 1. rvs      |";
    calculator_structure[0][1] = "| 2. sin      |";
    calculator_structure[1][0] = "| 3. ln       |";
    calculator_structure[1][1] = "| 4. Pft Root |";

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << calculator_structure[i][j] << "   ";
        }
        cout << endl;
    }

    cout << endl;
    int input;
    cout << "Please choose an option to continue(enter 0 for more option) : ";
    cin >> input;

    // normal calculator
    if (input == 0)
    {
        cout << "1. add two number : " << endl
             << "2. Multiple two number : " << endl
             << "3. divide two number : " << endl
             << "4. find percentage : " << endl
             << endl;
        cout << "Please choose an option to continue : ";
        cin >> input;
        if (extrafun(input) == 0)
            calculator();
    }

    if (input == 1)
        if (reverse_fun() == 0)
            calculator();
    if (input == 2)
        if (sin_fun() == 0)
            calculator();
    if (input == 3)
        if (ln_fun() == 0)
            calculator();
    if (input == 4)
        if (perfect_root() == 0)
            calculator();
}
int main()
{
    calculator();

    return 0;
}