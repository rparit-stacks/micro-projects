#include <iostream>
#include <vector>

#include "player.cpp"
using namespace std;

class Team {
public:
    std::string teamName;
    int totalRunsScored;
    int totalWicketLost;
    int totalballBowled;
    std::vector<Player> teamPlayers;

    Team();
};

Team::Team() {
    totalRunsScored = 0;
    totalWicketLost = 0;
    totalballBowled = 0;
}
