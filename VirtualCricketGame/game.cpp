
#include <windows.h>

#include <iostream>

#include "team.cpp"
using namespace std;

class Game {
public:
    Game();  // Declare the constructor
    Team CSK;
    Team RCB;
    Team* battingTeam;
    Team* bowlingTeam;
    Player *batsman, *bowler;
    bool isFirstinning;
    vector<string> players;
    vector<string> selectedPlayers;

    void displayWelcomeMessage();
    void displayInstructions();
    void displayPlayersPool();
    void selectTeamPlayer();
    void displayTeamPlayers(Team team);
    bool isItAvailableInAnotherTeam(string& player);
    void toss();
    void startFirstInnings();
    void displayScoreboard();
    void bowling();
    void startSecondinnings();
    void displayWinner();
};
Game::Game() {
    CSK.teamName = "CSK";
    RCB.teamName = "RCB";
    isFirstinning = false;
    players = {
        "[0] Rohit Sharma",     "[1] Virat Kohli",    "[2] Ravindra Jadeja",
        "[3] Mohammed Shami",   "[4] KL Rahul",       "[5] Shikhar Dhawan",
        "[6] Hardik Pandya",    "[7] Rishabh Pant",   "[8] Bhuvneshwar Kumar",
        "[9] Yuzvendra Chahal", "[10] Jasprit Bumrah"};
}

void Game::displayWelcomeMessage() {
    cout << "==================== WELCOME ====================" << endl;
    cout << "|                                                |" << endl;
    cout << "|          Virtual Cricket Game                  |" << endl;
    cout << "|                                                |" << endl;
    cout << "==================================================" << endl;
    cout << endl;
}

void Game::displayInstructions() {
    cout << "================== INSTRUCTIONS ==================" << endl;
    cout << "|                                                |" << endl;
    cout << "|  1. Create 2 teams (Team-X and Team-Y) with    |" << endl;
    cout << "|     5 players each from a pool of 12 players.  |" << endl;
    cout << "|  2. Toss a coin to decide which team bats first|." << endl;
    cout << "|  3. Each innings will consist of 5 balls.      |" << endl;
    cout << "|                                                |" << endl;
    cout << "==================================================" << endl;
    cout << endl;
}

void Game::displayPlayersPool() {
    cout << endl << "==============================" << endl;
    cout << "Player's Pool" << endl;
    for (string& player : players) {
        cout << player << endl;
    }
    cout << "==============================" << endl << endl;
}

bool Game::isItAvailableInAnotherTeam(string& player) {
    for (const string& p : selectedPlayers) {
        if (p == player) {
            return true;
        }
    }
    return false;
}

void Game::selectTeamPlayer() {
    cout << endl
         << "=============================================================="
         << endl;
    int temp;
    for (int i = 0; i < 4; ++i) {
    teamSelection:
        cout << "Please select the " << i + 1 << " player for your team "
             << CSK.teamName << " (Enter player number): ";
        cin >> temp;
        if (temp < 0 || temp >= 11) {
            cout << "Invalid player number. Please try again." << endl;
            goto teamSelection;
        } else {
            if (!isItAvailableInAnotherTeam(players[temp])) {
                Player cskPlayer;
                cskPlayer.name = players[temp];
                cskPlayer.uniqueId = temp;
                CSK.teamPlayers.push_back(cskPlayer);
                selectedPlayers.push_back(cskPlayer.name);
            } else {
                cout << "This player is already selected. "
                        "Please choose another player."
                     << endl;
                goto teamSelection;
            }
        }
    teamselection2:
        cout << "Please select the " << i + 1 << " player for your team "
             << RCB.teamName << " (Enter player number): ";
        cin >> temp;
        if (temp < 0 || temp >= 11) {
            cout << "Invalid player number. Please try again." << endl;
            goto teamselection2;

        } else {
            if (!isItAvailableInAnotherTeam(players[temp])) {
                Player rcbPlayer;
                rcbPlayer.name = players[temp];
                rcbPlayer.uniqueId = temp;
                RCB.teamPlayers.push_back(rcbPlayer);
                selectedPlayers.push_back(rcbPlayer.name);
            } else {
                cout << "This player is already selected. "
                        "Please choose another player."
                     << endl;
                goto teamselection2;
            }
        }
    }
    cout << "=============================================================="
         << endl
         << endl;
}

void Game::displayTeamPlayers(Team team) {
    cout
        << "\n##############################################################\n";
    cout << "                     Top Players of " << team.teamName << "\n";
    cout << "##############################################################\n";
    for (int i = 0; i < team.teamPlayers.size(); ++i) {
        cout << "Player " << (i + 1) << ": " << team.teamPlayers[i].name
             << endl;
    }
    cout
        << "##############################################################\n\n";
}

void Game::toss() {
    cout << endl;
    cout << "============ Let's Toss ============\n";
    cout << "   Please wait for the toss result";

    // Simulate the toss result delay
    for (int i = 0; i < 5; ++i) {
        Sleep(1000);
        cout << ".";
    }
    cout << endl;

    // Determine the toss winner and loser
    Team* tossWinner = (rand() % 2 == 0) ? &CSK : &RCB;
    Team* tossLoser = (tossWinner == &CSK) ? &RCB : &CSK;

    cout << "\nCongratulations! " << tossWinner->teamName << " won the toss.\n";
    cout << "Please select an option:\n";
    cout << "1. Bat\n";
    cout << "2. Bowl\n";

    int choice;
    cin >> choice;

    // Assign teams based on the user's choice
    if (choice == 1) {
        battingTeam = tossWinner;
        bowlingTeam = tossLoser;
        cout << "\n"
             << battingTeam->teamName << " has chosen to bat, and "
             << bowlingTeam->teamName << " will bowl.\n";
    } else {
        battingTeam = tossLoser;
        bowlingTeam = tossWinner;
        cout << "\n"
             << bowlingTeam->teamName << " has chosen to bat, and "
             << battingTeam->teamName << " will bowl.\n";
    }
}

void Game::displayScoreboard() {
    cout << "------------------------------------" << endl;
    cout << "          Match Scoreboard          " << endl;
    cout << "------------------------------------" << endl;
    cout << "| Batting Team: " << battingTeam->teamName << endl;
    cout << "| Total Runs Scored: " << battingTeam->totalRunsScored << endl;
    cout << "| Total Wickets Lost: " << battingTeam->totalWicketLost << endl;
    cout << "| Total Balls Bowled: " << battingTeam->totalballBowled << endl;
    cout << "------------------------------------" << endl;
    cout << "| Players:" << endl;
    for (const Player& player : battingTeam->teamPlayers) {
        cout << "| Name: " << player.name
             << ", Runs Scored: " << player.runsScored
             << ", Balls Played: " << player.ballPlayed << endl;
    }
    cout << "------------------------------------" << endl;
    cout << "| Bowling Team: " << bowlingTeam->teamName << endl;
    cout << "| Total Runs Given: " << bowlingTeam->totalRunsScored << endl;
    cout << "| Total Wickets Taken: " << bowlingTeam->totalWicketLost << endl;
    cout << "| Total Balls Bowled: " << bowlingTeam->totalballBowled << endl;
    cout << "------------------------------------" << endl;
    cout << "| Players:" << endl;
    for (const Player& player : bowlingTeam->teamPlayers) {
        cout << "| Name: " << player.name << ", Runs Given: " << player.runGiven
             << ", Wickets Taken: " << player.wicketTaken
             << ", Balls Bowled: " << player.ballsBowled << endl;
    }
    cout << "------------------------------------" << endl;
}
void Game::displayWinner() {
    cout << endl;
    cout << "------------------------------------" << endl;
    if (CSK.totalRunsScored > RCB.totalRunsScored) {
        cout << "Congratulations to CSK! They have won the match!" << endl;
    } else if (CSK.totalRunsScored < RCB.totalRunsScored) {
        cout << "Congratulations to RCB! They have won the match!" << endl;
    } else {
        cout << "The match is a tie!" << endl;
    }
    cout << "------------------------------------" << endl;
}

void Game::bowling() {
    cout << endl;
    for (int i = 0; i < 6; i++) {
        bowlingTeam->totalballBowled++;
        bowler->ballsBowled++;
        cout << "bowling.";
        Sleep(1000);
        cout << ".";
        Sleep(1000);
        cout << ".";
        Sleep(1000);
        cout << endl;

        int runScored = rand() % 8;
        if (runScored == 7) {
            bowler->wicketTaken++;
            bowler->ballsBowled++;
            batsman->ballPlayed++;
            cout << endl;
            cout << batsman->name.substr(4) << " is out" << endl;
            battingTeam->totalWicketLost++;
            Player* outPlayer = batsman;
        selectNewPlayer:
            Player* newPlayer = &(battingTeam->teamPlayers[rand() % 3]);
            if (outPlayer != newPlayer) {
                batsman = newPlayer;
                cout << "New player is : " << batsman->name.substr(4) << endl
                     << endl;
            } else
                goto selectNewPlayer;
        } else {
            battingTeam->totalRunsScored += runScored;
            batsman->runsScored += runScored;
            batsman->ballPlayed++;
            cout << endl << "This ball : " << runScored << " runs " << endl;
        }

        cout << "=============================================================="
                "==============="
             << endl;
        cout << battingTeam->teamName << "\t" << battingTeam->totalRunsScored
             << " - " << battingTeam->totalWicketLost << " (" << i + 1 << ") "
             << " | " << (batsman->name).substr(4) << " " << batsman->runsScored
             << " " << " (" << batsman->ballPlayed << ") " << "\t\t"
             << bowler->name.substr(4) << " " << bowler->ballsBowled << " - "
             << battingTeam->totalRunsScored << " - " << bowler->wicketTaken
             << endl;
        cout << "=============================================================="
                "=============="

             << endl;
    }
    cout << endl << endl;
}
void Game::startFirstInnings() {
    cout << "              =====================\n";
    cout << "              |    1st Innings    |\n";
    cout << "=================================================\n\n";

    // Select a random batsman and bowler
    batsman = &(battingTeam->teamPlayers[rand() % 3]);
    bowler = &(bowlingTeam->teamPlayers[rand() % 2]);

    cout << "Batsman: " << batsman->name << " is ready to bat.\n";
    cout << "Bowler: " << bowler->name << " is ready to bowl.\n";
    cout << "-------------------------------------------------\n";

    // Call the bowling function to start the innings
    bowling();
}

void Game::startSecondinnings() {
    cout << "              =====================\n";
    cout << "              |    2nd Innings    |\n";
    cout << "=================================================\n\n";

    // Swap the batting and bowling teams for the second innings
    Team* temp = battingTeam;
    battingTeam = bowlingTeam;
    bowlingTeam = temp;

    // Select a random batsman and bowler
    batsman = &(battingTeam->teamPlayers[rand() % 3]);
    bowler = &(bowlingTeam->teamPlayers[rand() % 2]);

    cout << "Batsman: " << batsman->name << " is ready to bat.\n";
    cout << "Bowler: " << bowler->name << " is ready to bowl.\n";
    cout << "-------------------------------------------------\n";

    // Call the bowling function to start the innings
    bowling();
}
