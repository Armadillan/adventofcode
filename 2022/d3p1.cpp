#include <cctype>
#include <iostream>
#include <string>
#include <map>


const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

int main(void) {

    std::map<char, int> priority;
    for (int p = 0; p<26; p++) {
        priority[alphabet[p]] = p + 1;
        priority[toupper(alphabet[p])] = p + 27;
    }

    int running_total = 0;

    std::string line;
    while (std::getline(std::cin, line)) {

        std::string part1 = line.substr(0, line.length()/2);
        std::string part2 = line.substr(line.length()/2);

        //find chars in each half
        int char_in_part1[26 * 2] = {0};
        int char_in_part2[26 * 2] = {0};
        for (int i = 0; i<part1.length(); i++) {
            char part1_char = part1[i];
            char part2_char = part2[i];
            if (islower(part1_char)) {
                char_in_part1[part1_char - (int)'a']++;
            } else {
                char_in_part1[part1_char - (int)'A' + 26]++;
            }
            if (islower(part2_char)) {
                char_in_part2[part2_char - (int)'a']++;
            } else {
                char_in_part2[part2_char - (int)'A' + 26]++;
            }
        }

        //find common chars
        bool common_chars[26*2] = {false};
        for (int i = 0; i<26*2; i++) {
            common_chars[i] = char_in_part1[i] && char_in_part2[i];
        }

        for (int i = 0; i<26; i++) {
            if (common_chars[i]) {
                char common = (char)(i+(int)'a');
                running_total += priority[common];
            }
        }
        for (int i = 26; i<26*2; i++) {
            if (common_chars[i]) {
                char common = (char)(i+(int)'A' - 26);
                running_total += priority[common];
            }
        }
    }

    std::cout << running_total << std::endl;

    return 0;
}
