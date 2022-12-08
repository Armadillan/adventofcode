#include <iostream>
#include <unordered_map>

bool unique(char char_array[], int n) {
    std::unordered_map<char, int> map;

    for (int i=0; i<n; i++) {
        map[char_array[i]]++;
        if (map[char_array[i]]>1) {
            return 0;
        }
    }
    return 1;
}

int solve_n(int n) {
    char chars[n];
    for (int i=0; i<n; i++) {
        chars[i] = std::getchar();
    }
    int processed = n;
    while (true) {
        if (unique(chars, n)) {
            return processed;
        }
        for (int i=1; i<n; i++) {
            chars[i-1] = chars[i];
        }
        chars[n-1] = std::getchar();
        processed++;
    }

    return 0;
}

int main() {
    // std::cout << solve_n(4) << std::endl;
    std::cout << solve_n(14) << std::endl;
}
