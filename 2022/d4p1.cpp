#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

int main(void) {

    std::vector<std::string> ranges;
    int range1[2];
    int range2[2];

    int num_contained = 0;

    std::vector<std::string> tmp_vec;

    std::string line;
    while (std::getline(std::cin, line)) {
        ranges = split(line, ",");

        tmp_vec = split(ranges[0], "-");
        range1[0] = stoi(tmp_vec[0]);
        range1[1] = stoi(tmp_vec[1]);

        tmp_vec = split(ranges[1], "-");
        range2[0] = stoi(tmp_vec[0]);
        range2[1] = stoi(tmp_vec[1]);

        //range1 contains range2
        if (range1[0] <= range2[0] && range1[1] >= range2[1]) {
            num_contained++;
        } else if (range2[0] <= range1[0] && range2[1] >= range1[1]) {
            //range2 contains range1
            num_contained++;
        }

    }

    std::cout << num_contained << std::endl;

    return 0;
}
