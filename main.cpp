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
    std::vector<int> all;
    
    std::sort(line.begin(), line.end());
    if (!(std::unique(line.begin(), line.end()) == line.end())) {
        return all;
    }

    int length = static_cast<int>(line.length());
    auto rng = std::default_random_engine{};
    int howMany = 0;
    std::string huh;

    switch (length) {
    case 4:
        howMany = 24;
        while (all.size() < howMany) {
            std::shuffle(line.begin(), line.end(), rng);
            int rivi = std::stoi(line);
            if (std::find(all.begin(), all.end(), rivi) == all.end()) {
                all.push_back(rivi);
            }
        }
        break;
    case 3:
        howMany = 36;
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
        break;
    case 2:
        howMany = 14;
        for (int i = 0; i < howMany; i++) {
            huh.clear();
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
        break;
    }
    return all;
}

int main() {
    while (true) {
        std::string line;
        std::cout << "Numbers: ";
        std::getline(std::cin, line);
        std::cout << std::endl;

        if (line.length() > 4 or line.length() < 2) {
            std::cout << "Must input betweeen 2 to 4 numbers" << std::endl << std::endl;
            continue;
        }

        std::vector<int> combs = combinations(line);
        if (combs.empty()) {
            std::cout << "All numbers must be different" << std::endl;
        }

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