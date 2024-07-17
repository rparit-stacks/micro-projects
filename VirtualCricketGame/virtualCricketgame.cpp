
#include <algorithm>
#include <climits>
#include <cmath>
#include <ctime>
#include <iostream>
#include <limits>
#include <random>
#include <string>
#include <vector>

#include "game.cpp"
using namespace std;
void pleaseWait() {
    cout << "Please wait.";
    Sleep(1000);
    cout << ".";
    Sleep(1000);
    cout << ".";
    Sleep(1000);
    cout << ".";
}

int main() {
    srand(time(0));  // Initialize random seed

    Game game;
    game.displayWelcomeMessage();
    game.displayInstructions();

    cout << "Press Enter to Continue...";
    cin.ignore();  // Wait for user to press Enter
    game.displayPlayersPool();

    cout << "\nPress Enter to Proceed to Player Selection...";
    cin.ignore();  // Wait for user to press Enter
    game.selectTeamPlayer();

    cout << "\nPress Enter to Continue...";
    cin.ignore();  // Wait for user to press Enter
    game.displayTeamPlayers(game.CSK);
    game.displayTeamPlayers(game.RCB);

    cout << "\nPress Enter to Continue to Toss...";
    cin.ignore();  // Wait for user to press Enter
    game.toss();

    cout << "\nLet the game begin!\n";
    cin.ignore();  // Wait for user to press Enter

    // Start the first innings
    game.startFirstInnings();

    // Wait for 3 seconds before proceeding
    pleaseWait();

    cout << "\nFirst innings completed. Press Enter to continue to the second "
            "innings...";
    cin.ignore();  // Wait for user to press Enter

    // Start the second innings
    game.startSecondinnings();

    // Wait for 3 seconds before proceeding
    pleaseWait();

    cout << "\nSecond innings completed. Press Enter to see the final "
            "scoreboard...";
    cin.ignore();  // Wait for user to press Enter

    // Display the final scoreboard
    game.displayScoreboard();

    // Announce the winner
    game.displayWinner();

    return 0;
}