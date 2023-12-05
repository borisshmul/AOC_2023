#include <iostream>
#include <fstream>
#include <string>
#include <cctype> // for isdigit()
#include <chrono> // for high precision timing

int main() {
    int sum = 0;
    std::ifstream file("problem1.txt");  
    std::string line;

    // Start timing
    auto start = std::chrono::high_resolution_clock::now();

    if (file.is_open()) {
        while (std::getline(file, line)) {
            int left = 0;
            int right = line.size() - 1;
            
            // Finding the first integer from the left
            while (left < line.size() && !isdigit(line[left])) {
                left++;
            }

            // Finding the first integer from the right
            while (right >= 0 && !isdigit(line[right])) {
                right--;
            }
            int leftint = line[left] - '0';
            int rightint = line[right] - '0';
            sum += leftint * 10;
            sum += rightint;
            //std::cout << leftint*10<< " "<< rightint << "\n\n";  
        }
        file.close();
    }

    // End timing
    auto end = std::chrono::high_resolution_clock::now();

    // Calculating total time taken by the program
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;

    return 0;
}
