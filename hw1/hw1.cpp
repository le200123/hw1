#include <iostream>
#include <vector>

using namespace std;

void generatePowerset(std::vector<char>& set, std::vector<char>& subset, int index) {
    if (index == set.size()) {
        std::cout << "{ ";
        for (char elem : subset) {
            std::cout << elem << " ";
        }
        std::cout << "}" << std::endl;
    }
    else {
        // Exclude the current element
        generatePowerset(set, subset, index + 1);

        // Include the current element
        subset.push_back(set[index]);
        generatePowerset(set, subset, index + 1);

        // Backtrack
        subset.pop_back();
    }
}

int main() {
    std::vector<char> set = { 'a', 'b', 'c' };
    std::vector<char> subset;
    generatePowerset(set, subset, 0);
    return 0;
}