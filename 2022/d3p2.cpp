#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <map>
#include <cstring>


const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

int main(void) {

    std::map<char, int> priority;
    for (int p = 0; p<26; p++) {
        priority[alphabet[p]] = p + 1;
        priority[toupper(alphabet[p])] = p + 27;
    }

    int running_total = 0;

    int char_in_line1[26 * 2] = {0};
    int char_in_line2[26 * 2] = {0};
    int char_in_line3[26 * 2] = {0};

    int line_number = 0;

    std::string line;
    while (std::getline(std::cin, line)) {
        if (line_number == 3) {

            line_number = 0;

            bool common_chars[26*2] = {false};

            for (int i = 0; i<26*2; i++) {
                common_chars[i] = char_in_line1[i] && char_in_line2[i] && char_in_line3[i];
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

            memset(char_in_line1, 0, sizeof(char_in_line1));
            memset(char_in_line2, 0, sizeof(char_in_line2));
            memset(char_in_line3, 0, sizeof(char_in_line3));
        }

        if (line_number == 0) {
            for (char &c : line) {
                if (islower(c)) {
                    char_in_line1[c - (int)'a']++;
                } else {
                    char_in_line1[c - (int)'A' + 26]++;
                }
            }
        } else if (line_number == 1) {
            for (char &c : line) {
                if (islower(c)) {
                    char_in_line2[c - (int)'a']++;
                } else {
                    char_in_line2[c - (int)'A' + 26]++;
                }
            }
        } else if (line_number == 2) {
            for (char &c : line) {
                if (islower(c)) {
                    char_in_line3[c - (int)'a']++;
                } else {
                    char_in_line3[c - (int)'A' + 26]++;
                }
            }
        }

        line_number++;
    }
    bool common_chars[26*2] = {false};
    for (int i = 0; i<26*2; i++) {
        common_chars[i] = char_in_line1[i] && char_in_line2[i] && char_in_line3[i];
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

    std::cout << running_total << std::endl;

    return 0;
}
