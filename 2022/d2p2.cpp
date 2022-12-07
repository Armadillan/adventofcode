// A = rock, B = paper, C = scissors
// X = lose, Y = draw, Z = win

#include <iostream>
#include <string>
#include <map>
int main(void) {


std::map<char, char> wins_against = {
    {'A', 'C'},
    {'B', 'A'},
    {'C', 'B'}
};

std::map<char, char> loses_against = {
    {'A', 'B'},
    {'B', 'C'},
    {'C', 'A'}
};

std::map<char, int> score_of_play = {
    {'A', 1},
    {'B', 2},
    {'C', 3}
};

const int win_score = 6;
const int draw_score = 3;


int running_total_score = 0;
std::string line;
while (std::getline(std::cin, line)) {
    char opponent_play = line[0];
    char outcome = line[2];
    char my_play;
    if (outcome == 'X') {
        //loss
        my_play = wins_against[opponent_play];
    } else if (outcome == 'Y') {
        //draw
        running_total_score += draw_score;
        my_play = opponent_play;
    } else {
        //win
        running_total_score += win_score;
        my_play = loses_against[opponent_play];
    }
    running_total_score += score_of_play[my_play];
}

std::cout << running_total_score << std::endl;

}
