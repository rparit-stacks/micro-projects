#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

int initial_amount = 9999;
int num1;
int bet_amount;
vector<int> winning_num;

void delay(int seconds)
{
    // this function is to make an real animation that computer is loading...
    clock_t start_time = clock();
    while (clock() < start_time + seconds * CLOCKS_PER_SEC)
        ;
}
void current_balance(bool loss_winn)
{
    // if you loss/winn the initial amount will alter here
    if (loss_winn)
        initial_amount += bet_amount * 8;
    else
        initial_amount -= bet_amount;
}
void winning_number()
{
    // this function allow is to choose 3 random number and if user have same number then user will win
    for (int i = 0; i < 3; i++)
    {
        winning_num.push_back(rand() % 49);
    }
}

int casino_game()
{
    cout << "Enter Your Bet amount : ";
    cin >> bet_amount;
    cout << endl;

    // this section will stop you to bet if you have low balance
    if (bet_amount > initial_amount)
    {
        cout << "Insufficient balance. Please enter a valid bet amount." << endl;
        casino_game();
    }

    cout << "Enter a number : ";
    cin >> num1;
    // if you enter a number which is greater than 49 than you cannot bet
    if (num1 > 49)
    {
        cout << "Please choose number between 0 to 49" << endl;
        casino_game();
    }
    cout << endl;
    // we call function get some random numbers
    winning_number();

    cout << "The computer is choosing its number, please wait a little...";
    delay(3);
    cout << endl
         << "Initializing...";
    delay(3);

    cout << endl
         << "Winning Number is : ";

    // this will help to show the winning numbers
    for (int i = 0; i < winning_num.size(); i++)
    {
        cout << winning_num[i] << " ";
    }
    cout << endl
         << endl;

    bool win = false;
    // This loop will check if any of your chosen numbers match the winning numbers
    for (int i = 0; i < winning_num.size(); i++)
    {
        if (winning_num[i] == num1)
        {
            win = true;
            break;
        }
    }

    // if you win you balance will get updated using current_balance(true);
    if (win)
    {

        current_balance(true);
        cout << "Congratulations, you win 8 times the amount you invested." << endl;
        cout << initial_amount;

        cout << endl;
    }
    else
    {
        // if you win you balance will get updated using current_balance(false);
        current_balance(false);
        cout << "We are very sorry that you lost your invested amount." << endl;
        cout << initial_amount;

        cout << endl;
    }

    winning_num.clear(); // clear the vector to fresh start the winning number
    cout << endl;
    cout << "Do you want to play the game again (y/n)";
    char temp;
    cin >> temp;
    if (temp == 'Y' || temp == 'y')
        casino_game();

    return 0;
}
int main()
{
    cout << "*****Welcome to Starlight Casino*****" << endl
         << endl;
    cout << "Rules of Game!!" << endl
         << endl
         << "1. Choose 1 number between 0 to 49" << endl
         << "2. If the numbers you draw is equal to the 3 winning number, you will win 8 times the money." << endl
         << "3. You will get an initial deposit of Rs 9999" << endl
         << "4. If you bet on wrong number you will lose your betting amount" << endl
         << endl;

    cout << "Your Current Balance is Rs." << initial_amount;
    char user_decision;
    cout << endl;
    cout << endl;

    cout << "Are You Ready to play (y/n) : ";
    cin >> user_decision;
    if (user_decision == 'Y' || user_decision == 'y')
    {
        cout << endl;
        casino_game();
    }

    return 0;
}