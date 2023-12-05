#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <cctype>
#include <chrono>
#include <algorithm>

std::unordered_map<std::string, int> createNumberMap() {
    return {
        {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
        {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
    };
}

int findNumberInSubstring(const std::string& line, size_t start, const std::unordered_map<std::string, int>& numberMap, size_t& nextIndex) {
    std::string currentWord;

    for (size_t i = start; i < line.length(); i++) {
        currentWord += line[i];
        auto it = numberMap.find(currentWord);
        if (it != numberMap.end()) {
            nextIndex = i + 1; // Update the next index to continue from
            return it->second;
        }
    }

    nextIndex = start + 1; // Move to the next character
    return -1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::unordered_map<std::string, int> numberMap = createNumberMap();
    std::ifstream file("problem2.txt");
    if (!file.is_open()) {
        std::cerr << "File could not be opened.\n";
        return 1;
    }

    int sum = 0;
    std::string line;

    auto start = std::chrono::high_resolution_clock::now();

    while (std::getline(file, line)) {
        std::transform(line.begin(), line.end(), line.begin(), [](unsigned char c){ return std::tolower(c); });

        int leftInt = -1, rightInt = -1;
        size_t nextIndex = 0;

        for (size_t i = 0; i < line.length(); ++i) {
            if (isdigit(line[i])) {
                int digit = line[i] - '0';
                if (leftInt == -1) {
                    leftInt = digit;
                }
                rightInt = digit;
            } else if (isalpha(line[i]) && i >= nextIndex) {
                int numberValue = findNumberInSubstring(line, i, numberMap, nextIndex);
                if (numberValue != -1) {
                    if (leftInt == -1) {
                        leftInt = numberValue;
                    }
                    rightInt = numberValue;
                    i = nextIndex - 1; // Skip past the processed number word
                }
            }
        }

        if (leftInt != -1 && rightInt != -1) {
            sum += leftInt * 10 + rightInt;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;

    file.close();
    return 0;
}
