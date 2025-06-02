// You are given a 0-indexed integer array nums. For each index i (1 <=
// i <= nums.length - 2) the beauty of nums[i] equals:

// 2, if nums[j] < nums[i] < nums[k], for all 0 <= j < i and for all i < k
// <= nums.length - 1.

// 1, if nums[i - 1] < nums[i] < nums[i + 1], and the
// previous condition is not satisfied.

// 0, if none of the previous
// conditions holds.

// Return the sum of beauty of all nums[i] where 1 <= i <=
// nums.length - 2.

#include <iostream>
#include <limits>
#include <vector>

class Solution {
  // Prefix and suffix arrays

  // prefix[i] records the maximum value in range (0, i - 1) inclusive.
  std::vector<int> prefix;
  // suffix[i] records the minimum value in range (i + 1, n - 1) inclusive.
  std::vector<int> suffix;

  // Fill prefix and suffix based on nums
  void fillPrefixAndSuffix(const std::vector<int> &nums) {
    const int numsSize = nums.size();

    // Fill prefix
    prefix[0] = std::numeric_limits<int>::min();
    for (int i = 1; i < numsSize; ++i) {
      prefix[i] = std::max(prefix[i - 1], nums[i - 1]);
    }

    // Fill suffix
    suffix[numsSize - 1] = std::numeric_limits<int>::max();
    for (int i = numsSize - 2; i >= 0; --i) {
      suffix[i] = std::min(suffix[i + 1], nums[i + 1]);
    }

    // Debug: print prefix and suffix arrays
    // std::cout << "Prefix: ";
    // for (const auto &val : prefix) {
    //   std::cout << val << " ";
    // }
    // std::cout << std::endl;

    // std::cout << "Suffix: ";
    // for (const auto &val : suffix) {
    //   std::cout << val << " ";
    // }
    // std::cout << std::endl;
  }

  // Get the beauty for a specific index
  int getBeautyForSpecificIndex(const std::vector<int> &nums, const int index) {
    // 2, if nums[j] < nums[i] < nums[k], for all 0 <= j < i and for all i < k
    // <= nums.length - 1.
    if (prefix[index] < nums[index] && nums[index] < suffix[index]) {
      return 2;
    }

    // 1, if nums[i - 1] < nums[i] < nums[i + 1], and the
    // previous condition is not satisfied.
    if (nums[index - 1] < nums[index] && nums[index] < nums[index + 1]) {
      return 1;
    }

    // 0, if none of the previous conditions holds.
    return 0;
  }

public:
  int sumOfBeauties(const std::vector<int> &nums) {
    const int numsSize = nums.size();

    // If size too small
    if (numsSize < 3) {
      return 0;
    }

    // Initialize prefix and suffix arrays
    prefix.resize(numsSize);
    suffix.resize(numsSize);

    // Fill prefix and suffix arrays
    fillPrefixAndSuffix(nums);

    // Initialize the result
    int result = 0;
    // Iterate through the nums array
    for (int i = 1; i < numsSize - 1; i++) {
      result += getBeautyForSpecificIndex(nums, i);
    }

    // Return the result
    return result;
  }
};

// int main() {
//   Solution solution;
//   std::vector<int> nums = {
//       1,
//       2,
//       3,
//   };
//   int result = solution.sumOfBeauties(nums);
//   std::cout << "Sum of beauties: " << result << std::endl;
//   return 0;
// }