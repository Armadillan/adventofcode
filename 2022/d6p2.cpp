#include <iostream>
#include <unordered_map>

bool unique(char char_array[14]) {
    std::unordered_map<char, int> map;

    for (int i=0; i<14; i++) {
        map[char_array[i]]++;
        if (map[char_array[i]]>1) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char chars[14];
    for (int i=0; i<14; i++) {
        chars[i] = std::getchar();
    }
    int processed = 14;
    while (true) {
        if (unique(chars)) {
            std::cout << processed << std::endl;
            return 0;
        }
        for (int i=1; i<14; i++) {
            chars[i-1] = chars[i];
        }
        chars[13] = std::getchar();
        processed++;
    }

    return 1;
}
