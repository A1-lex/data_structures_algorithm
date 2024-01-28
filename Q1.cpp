#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    int index = 0;  

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[index]) {
            nums[++index] = nums[i];
        }
    }

    return index + 1;
}

int main() {
    std::vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5, 5};

    std::cout << "original array: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int newLength = removeDuplicates(nums);

    std::cout << "array after removing duplicates: ";
    for (int i = 0; i < newLength; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "new length: " << newLength << std::endl;

    return 0;
}