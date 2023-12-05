#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <cctype> // for isdigit()
#include <chrono> // for high precision timing

std::unordered_map<std::string, int> createNumberMap() {
    return {
        {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
        {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
    };
}

int findNumberInSubstring(const std::string& line, int start, const std::unordered_map<std::string, int>& numberMap) {
    std::string currentWord;
    for (size_t i = start; i < line.length(); i++) {
        if (isalpha(line[i])) {
            currentWord += line[i];
            auto it = numberMap.find(currentWord);
            if (it != numberMap.end()) {
                return it->second;
            }
        } else {
            break; // Non-alphabetic character ends the current word search
        }
    }
    return -1; // No valid number word found
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

    // Start timing
    auto start = std::chrono::high_resolution_clock::now();

    while (std::getline(file, line)) {
        int leftInt = -1, rightInt = -1;

        for (size_t i = 0; i < line.length(); ++i) {
            if (isdigit(line[i])) {
                int digit = line[i] - '0';
                if (leftInt == -1) {
                    leftInt = digit;
                }
                rightInt = digit;
            } else if (isalpha(line[i])) {
                int numberValue = findNumberInSubstring(line, i, numberMap);
                if (numberValue != -1) {
                    if (leftInt == -1) {
                        leftInt = numberValue;
                    }
                    rightInt = numberValue;
                }
            }
        }

        if (leftInt != -1 && rightInt != -1) {
            //std::cout << leftInt << " " << rightInt << "\n";
            sum += leftInt * 10 + rightInt;
        }
    }

    // End timing
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;

    file.close();
    return 0;
}
