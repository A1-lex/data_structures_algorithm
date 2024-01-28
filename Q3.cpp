#include <iostream>
#include <vector>
#include <unordered_set>

bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> uniqueElements;

    for (int num : nums) {
        if (uniqueElements.count(num) > 0) {
            return true;
        } else {
            uniqueElements.insert(num);
        }
    }

    return false;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 2};  
    if (containsDuplicate(nums)) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }

    return 0;
}
