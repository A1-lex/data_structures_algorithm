#include <iostream>
#include <vector>

void rotate(std::vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;

    int count = 0;

    for (int start = 0; count < n; ++start) {
        int current = start;
        int prev = nums[start];

        do {
            int next = (current + k) % n;
            std::swap(nums[next], prev);
            current = next;
            ++count;
        } while (start != current);
    }
}

int main() {
    std::vector<int> nums = {11, 24, 20, 32, 64};
    int k = 2;

    std::cout << "Original array: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    rotate(nums, k);

    std::cout << "array after rotating by " << k << " steps to the right: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
