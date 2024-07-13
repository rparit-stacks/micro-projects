
# Gully Cricket Simulation

This code simulates a simple game of cricket between two teams, RCB and CSK. The game involves a toss to decide which team will bat first, followed by an innings where each team bats and bowls. The scores are randomly generated, and the final results are displayed at the end.

## Libraries and Namespaces

```cpp
#include <windows.h>
#include <algorithm>
#include <climits>
#include <cmath>
#include <ctime>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;
```

The code includes standard C++ libraries for input/output operations, string manipulation, random number generation, time functions, and Windows-specific functions for introducing delays.

## Team Class

### Private Members

```cpp
vector<string> teamPlayers = vector<string>(4); 
int totalScore = 0;
```

- `teamPlayers`: A vector to store the names of the team players.
- `totalScore`: An integer to keep track of the team's total score.

### Public Methods

#### Constructor

```cpp
Team(string teamName) {
    teamPlayers[0] = teamName;
}
```
- Initializes the team with the given team name.

#### `setPlayerName`

```cpp
void setPlayerName(string p1, string p2, string p3) {
    teamPlayers[1] = p1;
    teamPlayers[2] = p2;
    teamPlayers[3] = p3;
}
```
- Sets the names of the three players in the team.

#### `displayPlayerName`

```cpp
void displayPlayerName() {
    cout << "Player 1 : " << teamPlayers[1] << endl;
    cout << "Player 2 : " << teamPlayers[2] << endl;
    cout << "Player 3 : " << teamPlayers[3] << endl;
}
```
- Displays the names of the three players.

#### `displayTeams`

```cpp
void displayTeams() {
    cout << this->teamPlayers[0] << endl;
    this->displayPlayerName();
}
```
- Displays the team name and the names of the players.

#### `player`

```cpp
string player(int n) {
    return this->teamPlayers[n];
}
```
- Returns the name of the player at the specified index.

#### `setTotalScore`

```cpp
void setTotalScore(int score) {
    this->totalScore = score;
}
```
- Sets the total score of the team.

#### `getScore`

```cpp
int getScore() {
    return this->totalScore;
}
```
- Returns the total score of the team.

## Functions

### `toss`

```cpp
int toss() {
    cout << endl;
    cout << "Please Wait for toss result.";
    Sleep(1000);
    cout << ".";
    Sleep(1000);
    cout << ".";
    Sleep(1000);
    cout << ".";
    Sleep(1000);
    cout << ".";
    Sleep(1000);
    cout << ".";
    cout << endl;

    return rand() % 2;
}
```
- Simulates the toss and returns a random result (0 or 1) after a delay.

### `tossDecision`

```cpp
int tossDecision(string teamName) {
    Sleep(3000);

    if (!rand() % 2) {
        cout << endl << endl;
        cout << teamName << " choose bat first";
        return 1;
    } else {
        cout << endl << endl;
        cout << teamName << " choose ball first";
        return 0;
    }
}
```
- Simulates the toss decision and returns the choice of batting or bowling first after a delay.

### `welcomeUsers`

```cpp
void welcomeUsers() {
    cout << "**********************************" << std::endl;
    cout << "**** Welcome to Gully Cricket ****" << std::endl;
    cout << "**********************************" << std::endl;
    cout << "------------ Have Fun! -----------" << std::endl;
}
```
- Displays a welcome message.

### `gameStart`

```cpp
void gameStart(Team& bat, Team& ball, int n) {
    if (n < 0)
        return;

    int totalScore = 0;
    cout << endl << endl;

    string batPlayer = bat.player(rand() % 2 + 1);
    string ballPlayer = ball.player(rand() % 2 + 1);

    cout << "--------------------------------------------------" << endl;
    cout << bat.player(0) << " Innings: " << endl;
    cout << batPlayer << " will bat first" << endl;
    cout << ballPlayer << " will ball first" << endl;
    cout << "--------------------------------------------------" << endl;

    for (int ball = 1; ball <= 6; ball++) {
        cout << "Ball " << ball << ": ";
        int score = rand() % 5 + 1;
        totalScore += score;
        cout << "Scored " << score << " runs." << endl;
        Sleep(2000);
    }

    bat.setTotalScore(totalScore);
    cout << "--------------------------------------------------" << endl;
    cout << "Total Score: " << bat.getScore() << " runs" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << endl << endl;

    gameStart(ball, bat, n - 1);
}
```
- Simulates an innings, where the batting and bowling teams play, and recursively starts the next innings until the specified number of innings is completed.

## Main Function

```cpp
int main() {
    srand(time(0));
    welcomeUsers();
    Team rcb("RCB");
    Team csk("CSK");
    rcb.setPlayerName("Vk", "Fap", "ABD");
    csk.setPlayerName("MSD", "Shane", "Jadeja");
    cout << endl;
    cout << "Team 1 : ";
    csk.displayTeams();
    cout << endl;
    cout << "Team 2 : ";
    rcb.displayTeams();

    if (!toss()) {
        cout << "Csk Won the Toss, Please wait for their Decision : ";
        if (!tossDecision("CSK"))
            gameStart(rcb, csk, 1);
        else
            gameStart(csk, rcb, 1);
    } else {
        cout << "RCB Won the Toss, Please wait for their Decision : ";
        if (!tossDecision("RCB"))
            gameStart(csk, rcb, 1);
        else
            gameStart(rcb, csk, 1);
    }

    cout << endl;
    cout << "==================================================" << endl;
    cout << "**************** Final Scores ********************" << endl;
    cout << "==================================================" << endl;
    cout << "RCB: " << rcb.getScore() << " runs" << endl;
    cout << "CSK: " << csk.getScore() << " runs" << endl;
    cout << "==================================================" << endl;

    if (rcb.getScore() > csk.getScore()) {
        cout << "RCB wins the match!" << endl;
    } else if (rcb.getScore() < csk.getScore()) {
        cout << "CSK wins the match!" << endl;
    } else {
        cout << "The match is a tie!" << endl;
    }
    cout << "==================================================" << endl;

    return 0;
}
```
- Initializes the random number generator.
- Welcomes the users.
- Creates two teams, RCB and CSK, and sets their players' names.
- Displays the teams.
- Conducts the toss to decide which team will bat first.
- Simulates the game by calling the `gameStart` function.
- Displays the final scores and declares the winner.

---

This documentation provides a comprehensive overview of the code's functionality and how each part contributes to the overall simulation of the cricket game.
