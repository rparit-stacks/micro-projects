#include <string>

class Player {
public:
    std::string name;
    int uniqueId;
    int runsScored;
    int ballPlayed;
    int ballsBowled;
    int runGiven;
    int wicketTaken;

    Player();
};

Player::Player() {
    runsScored = 0;
    ballPlayed = 0;
    ballsBowled = 0;
    runGiven = 0;
    wicketTaken = 0;
}