#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct ColorCount {
    std::string color;
    int count;
};

bool isPortionPossible(const std::vector<ColorCount>& data) {
    for (const auto& item : data) {
        if ((item.color == "red" && item.count > 12) ||
            (item.color == "green" && item.count > 13) ||
            (item.color == "blue" && item.count > 14)) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ifstream file("yourfile.txt");
    std::string line;
    int sumOfPossibleGames = 0;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string gameLabel;
        int gameNumber;
        char colon;

        iss >> gameLabel >> gameNumber >> colon; // Reading "Game", game number, and colon

        std::string segment;
        bool isGamePossible = true;

        // Process the remainder of the line
        std::string remainder;
        std::getline(iss, remainder);
        std::istringstream segmentStream(remainder);

        while (std::getline(segmentStream, segment, ';')) {
            std::istringstream colorStream(segment);
            std::vector<ColorCount> portionData;
            int count;
            std::string color;

            while (colorStream >> count >> color) {
                color.erase(color.find_last_not_of(", ") + 1); // Remove trailing comma and space
                portionData.push_back({color, count});
            }

            if (!isPortionPossible(portionData)) {
                isGamePossible = false;
                break; // Stop checking further if one portion fails
            }
        }

        if (isGamePossible) {
            sumOfPossibleGames += gameNumber;
        }
    }

    std::cout << "Sum of possible game IDs: " << sumOfPossibleGames << std::endl;

    return 0;
}
