#include <utility>
#include <vector>

class Solution {
public:
  int removeElement(std::vector<int> &nums, int val) {
    // Do nothing if size is 0
    if (nums.size() == 0) {
      return 0;
    }

    int remainingNumsCount = nums.size();
    std::vector<int>::iterator itBegin = nums.begin(), itEnd = nums.end() - 1;
    while (itBegin <= itEnd && *itEnd == val) {
      itEnd--;
      remainingNumsCount--;
    }

    if (itEnd < itBegin) {
      return remainingNumsCount;
    }

    while (itBegin <= itEnd) {
      while (itBegin <= itEnd && *itBegin == val) {
        std::swap(*itBegin, *itEnd);
        itEnd--;
        remainingNumsCount--;
      }
      itBegin++;
    }

    return remainingNumsCount;
  }
};