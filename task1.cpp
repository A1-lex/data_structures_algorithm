#include <iostream>
#include <climits>  

int summation(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    return sum;
}

int maximum(int arr[], int n) {
    int max_value = INT_MIN;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }
    return max_value;
}

int main() {
    int n;
    std::cout << "Enter the length of the array (0 <= n <= ∞): ";
    std::cin >> n;

    int array[n];

    for (int i = 0; i < n; ++i) {
        std::cout << "Enter integer " << i + 1 << ": ";
        std::cin >> array[i];
    }

    int sum_result = summation(array, n);
    std::cout << "Sum of the array: " << sum_result << std::endl;

    int max_result = maximum(array, n);
    std::cout << "Maximum element in the array: " << max_result << std::endl;

    return 0;
}