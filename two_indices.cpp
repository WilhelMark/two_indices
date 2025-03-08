#include <iostream>
#include <vector>
#include <climits>

// Function to find the indices of the subarray with the maximum sum
std::pair<int, int> findMaxSubarrayIndices(const std::vector<int>& nums) {
    // Initialize variables to store the maximum sum and current sum
    int maxSum = INT_MIN;
    int currentSum = 0;
    
    // Initialize variables to store the starting and ending indices of the max subarray
    int start = 0;
    int end = 0;
    int tempStart = 0;

    // Iterate through the array
    for (int i = 0; i < nums.size(); ++i) {
        // Add the current element to the current sum
        currentSum += nums[i];

        // If the current sum is greater than the max sum, update the max sum and indices
        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }

        // If the current sum becomes negative, reset it and update the temporary start index
        if (currentSum < 0) {
            currentSum = 0;
            tempStart = i + 1;
        }
    }

    // Return the indices of the subarray with the maximum sum
    return {start, end};
}

int main() {
    // Input array
    std::vector<int> a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // Find the indices of the subarray with the maximum sum
    std::pair<int, int> indices = findMaxSubarrayIndices(a);

    // Output the result
    std::cout << "The indices of the subarray with the maximum sum are: "
              << indices.first << " and " << indices.second << std::endl;

    return 0;
}