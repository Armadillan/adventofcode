#include <iostream>
#include <string>

int main(void) {
    int running_total = 0;
    int current_max = 0;
    std::string line;
    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            if (running_total > current_max) {
                current_max = running_total;
            }
            running_total = 0;
        } else {
            running_total += std::stoi(line);
        }
    }
    std::cout << current_max << std::endl;
    return 0;
}
