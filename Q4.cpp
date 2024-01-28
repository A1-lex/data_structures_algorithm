#include <iostream>
#include <unordered_set>
#include <vector>


int singleNumber(std::vector<int>& nums) {
    int uniqueSum = 0, totalSum = 0;
    std::unordered_set<int> uniqueElements;

    for (int num : nums) {
        if (uniqueElements.count(num) == 0) {
            uniqueElements.insert(num);
            uniqueSum += num;
        }
        totalSum += num;
    }

    return 2 * uniqueSum - totalSum;
}

int main() {
    std::vector<int> nums = {4, 2, 3, 2, 3};  

    int single = singleNumber(nums);

    std::cout << "The single number is: " << single << std::endl;

    return 0;
}