#include <iostream>
#include <fstream>
#include <cctype> // for isdigit()
#include <chrono> // for high precision timing

int main() {
    std::ios::sync_with_stdio(false); // Disable synchronization with C-style I/O
    std::cin.tie(NULL); // Untie cin and cout

    std::ifstream file("problem1.txt");
    if (!file.is_open()) {
        std::cerr << "File could not be opened.\n";
        return 1;
    }

    int sum = 0;
    char ch;
    int leftint = 0, rightint = 0;
    bool leftFound = false, rightFound = false;

    // Start timing
    auto start = std::chrono::high_resolution_clock::now();

    while (file.get(ch)) {
        if (!leftFound && isdigit(ch)) {
            leftint = ch - '0';
            leftFound = true;
        }
        if (isdigit(ch)) {
            rightint = ch - '0';
            rightFound = true;
        }
        if (ch == '\n' && leftFound && rightFound) {
            sum += leftint * 10 + rightint;
            leftFound = false;
            rightFound = false;
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
