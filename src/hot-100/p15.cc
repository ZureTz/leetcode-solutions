#include <algorithm>
#include <cstddef>
#include <vector>

class Solution {

public:
  std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    // Sort the nums first
    std::sort(nums.begin(), nums.end());

    std::vector<std::vector<int>> results;

    // Using one pointer, iterate through the sorted array
    for (size_t i = 0; i < nums.size() - 2; i++) {
      // Skip duplicates for the first number
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      // Using two pointers for the remaining two numbers
      size_t j = i + 1, k = nums.size() - 1;
      while (j < k) {
        // Skip duplicates for the second number
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          j++;
          continue;
        }

        // Skip duplicates for the third number
        if (k < nums.size() - 1 && nums[k] == nums[k + 1]) {
          k--;
          continue;
        }

        const int sum = nums[i] + nums[j] + nums[k];

        if (sum < 0) {
          j++;
          continue;
        }

        if (sum > 0) {
          k--;
          continue;
        }

        // Otherwise, we found a valid triplet
        results.push_back({nums[i], nums[j], nums[k]});

        j++;
        k--;
      }
    }

    return results;
  }
};