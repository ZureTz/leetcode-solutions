#include <cstddef>
#include <unordered_map>
#include <vector>

class Solution {
  std::unordered_map<int, size_t> usedNumAndIndex;

public:
  std::vector<int> twoSum(const std::vector<int> &nums, int target) {
    // For each number, find if there is a number that can be added to it to
    // If there is, return the indices of the two numbers.
    // Otherwise, continue.
    for (size_t i = 0; i < nums.size(); ++i) {
      auto it = usedNumAndIndex.find(target - nums[i]);
      // If the number is found, return the indices.
      if (it != usedNumAndIndex.end()) {
        return std::vector<int>{static_cast<int>(it->second),
                                static_cast<int>(i)};
      }
      // Otherwise, add the number to the map.
      usedNumAndIndex.insert({nums[i], i});
    }

    // If no such numbers are found, return an empty vector.
    return {};
  }
};