#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <deque>
#include <vector>

// std::vector<std::string> split(std::string s, std::string delimiter) {
//     size_t pos_start = 0, pos_end, delim_len = delimiter.length();
//     std::string token;
//     std::vector<std::string> res;

//     while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
//         token = s.substr (pos_start, pos_end - pos_start);
//         pos_start = pos_end + delim_len;
//         res.push_back (token);
//     }

//     res.push_back (s.substr (pos_start));
//     return res;
// }


int main(void) {
    //front of deque is top of stack
    std::string stacks[9];

    std::string line;
    char current_letter;
    int cl_index = 0;

    //get initial stacks
    while (std::getline(std::cin, line)) {
        if (line[1] == '1') {
            break;
        }

        // omg ugly but too tired to refactor
        for (int i=0; i<9; i++) {
            cl_index = 4*i+1;
            if (cl_index < line.length()) {
                current_letter = line[cl_index];
                if (current_letter != ' ') {
                    stacks[i].push_back(current_letter);
                }
            }
        }

    }

    //skip emtpy line
    std::getline(std::cin, line);
    int num_to_move;
    int move_source;
    int move_target;
    int next_space_index;

    while (std::getline(std::cin, line)) {

        //should have just used "split"

        //"move "
        line.erase(0, 5);

        next_space_index = line.find(' ');
        num_to_move = stoi(line.substr(0, next_space_index));
        line.erase(0, next_space_index);

        //" from "
        line.erase(0, 6);

        next_space_index = line.find(' ');
        move_source = stoi(line.substr(0, next_space_index))-1;
        line.erase(0, next_space_index);

        //" to "
        line.erase(0, 4);

        move_target = stoi(line)-1;

        stacks[move_target].insert(0, stacks[move_source].substr(0, num_to_move));
        stacks[move_source].erase(0, num_to_move);

    }


    for (std::string &stack : stacks) {
        std::cout << stack[0];
    }

    std::cout << std::endl;

    return 0;
}
