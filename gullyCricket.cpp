
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

class Team {
private:
    vector<string> teamPlayers = vector<string>(4);
    int totalScore = 0;

public:
    Team(string teamName) {  // constructor
        teamPlayers[0] = teamName;
    }

    void setPlayerName(string p1, string p2, string p3) {
        teamPlayers[1] = p1;
        teamPlayers[2] = p2;
        teamPlayers[3] = p3;
    }
    void displayPlayerName() {
        cout << "Player 1 : " << teamPlayers[1] << endl;
        cout << "Player 2 : " << teamPlayers[2] << endl;
        cout << "Player 3 : " << teamPlayers[3] << endl;
    }

    void displayTeams() {
        cout << this->teamPlayers[0] << endl;
        this->displayPlayerName();
    }

    string player(int n) {
        return this->teamPlayers[n];
    }

    void setTotalScore(int score) {
        this->totalScore = score;
    }
    int getScore() {
        return this->totalScore;
    }
};

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

int tossDecision(string teamName) {
    Sleep(3000);

    if (!rand() % 2) {
        cout << endl << endl;
        cout << teamName << " choose bat first";
        return 1;
    }

    else {
        cout << endl << endl;
        cout << teamName << " choose ball first";
        return 0;
    }
}

void welcomeUsers() {
    cout << "**********************************" << std::endl;
    cout << "**** Welcome to Gully Cricket ****" << std::endl;
    cout << "**********************************" << std::endl;
    cout << "------------ Have Fun! -----------" << std::endl;
}

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
        int score = rand() % 5 + 1;  // Generate a random score between 1 and 6
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