#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

char getComputerchoice(int n)
{
    if (n == 0)
        return 'R';
    if (n == 1)
        return 'P';
    else
        return 'S';
}

int main()
{

    char user;
    cout << endl
         << endl;
    cout << "Please choose R.rock, P.paper, S.scissor (in upper case)";
    cin >> user;

    int comp = rand() % 3;
    char compchoice = getComputerchoice(comp);

    if (compchoice == user)
    {
        cout << "Match tie";
    }
    else if (compchoice == 'S' && user == 'R')
    {
        cout << "YOU WIN, computer choice is : Scissor";
    }
    else if (compchoice == 'R' && user == 'P')
    {
        cout << "YOU WIN, computer choice is : Rock";
    }

    else if (compchoice == 'P' && user == 'S')
    {
        cout << "YOU WIN, computer choice is : Rock";
    }

    else
    {
        cout << "Computer Win, computer choice is : " << compchoice;
    }

    main();
    return 0;
}