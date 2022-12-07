// A = rock, B = paper, C = scissors
// X = rock, Y = paper, Z = scissors

#include <iostream>
#include <string>
#include <map>
int main(void) {

std::map<char, char> translation = {
    {'X', 'A'},
    {'Y', 'B'},
    {'Z', 'C'}
};

std::map<char, char> wins_against = {
    {'A', 'C'},
    {'B', 'A'},
    {'C', 'B'}
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
    char my_play = translation[line[2]];
    char opponent_play = line[0];
    running_total_score += score_of_play[my_play];
    if (wins_against[my_play] == opponent_play) {
        running_total_score += win_score;
    } else if (my_play == opponent_play) {
        running_total_score += draw_score;
    }
}

std::cout << running_total_score << std::endl;

}
