#include <iostream>
#include <string>

int main(void) {
    int running_total = 0;
    int top1 = 0;
    int top2 = 0;
    int top3 = 0;
    std::string line;
    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            if (running_total > top1) {
                top3 = top2;
                top2 = top1;
                top1 = running_total;
            } else if (running_total > top2) {
                top3 = top2;
                top2 = running_total;
            } else if (running_total > top3) {
                top3 = running_total;
            }
            running_total = 0;
        } else {
            running_total += std::stoi(line);
        }
    }
    std::cout << top1 + top2 + top3 << std::endl;
    return 0;
}
