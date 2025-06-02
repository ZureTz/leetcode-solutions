#include <algorithm>
#include <vector>

class Solution {
public:
  void moveZeroes(std::vector<int> &nums) {
    auto forEachIterator = nums.begin();
    auto nonZeroIterator = nums.begin();
    while (nonZeroIterator != nums.end()) {
      if (*nonZeroIterator != 0) {
        std::swap(*nonZeroIterator, *forEachIterator);
        forEachIterator++;
      }
      nonZeroIterator++;
    }
  }
};