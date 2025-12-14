#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <random>


bool compare(int a, int b) {
    return a < b;
}

bool mole(std::string huh, std::string line) {
    bool first = huh.find(line[0]) != std::string::npos;
    bool sec = huh.find(line[1]) != std::string::npos;
    return first && sec;
}

std::vector<int> combinations(std::string line) {

    int length = static_cast<int>(line.length());
    std::vector<int> all;
    auto rng = std::default_random_engine{};

    if (length == 4) {
        int howMany = 24;
        while (all.size() < howMany) {
            std::shuffle(line.begin(), line.end(), rng);
            int rivi = std::stoi(line);
            if (std::find(all.begin(), all.end(), rivi) == all.end()) {
                all.push_back(rivi);
            }
        }
    }
    else if (length == 3) {
        int howMany = 36;
        std::string huh;
        while (all.size() < howMany) {
            for (char c : line) {
                huh = line + c;
                std::shuffle(huh.begin(), huh.end(), rng);
                int rivi = std::stoi(huh);
                if (std::find(all.begin(), all.end(), rivi) == all.end()) {
                    all.push_back(rivi);
                }
            }
        } 
    }
    else if (length == 2) {
        int howMany = 14;
        for (int i = 0; i < howMany; i++) {
            std::string huh;
            for (int j = 0; j < 4; j++) {
                if ((i >> j) & 1) {
                    huh += line[0];
                }
                else {
                    huh += line[1];
                }
            }
            if (mole(huh, line)) {
                all.push_back(stoi(huh));
            }
        }
    }
    return all;
}




int main() {
    while (true) {
        std::string line;
        std::cout << "Numbers: ";
        std::getline(std::cin, line);
        std::cout << std::endl;

        std::vector<int> combs = combinations(line);

        std::sort(combs.begin(), combs.end(), compare);

        int counter = 0;

        for (int com : combs) {
            if (counter < 2) {
                std::cout << com << " : ";
                counter++;
            }
            else {
                std::cout << com << std::endl;
                std::cout << "------------------" << std::endl;
                counter = 0;
            }
        }

        std::cout << std::endl;
    }

}