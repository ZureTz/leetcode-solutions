#include <utility>
#include <vector>

class Solution {
public:
  int removeElement(std::vector<int> &nums, int val) {
    // Return 0 if the array is empty
    if (nums.empty()) {
      return 0;
    }

    int remainingNumsCount = nums.size();
    auto itBegin = nums.begin();
    auto itEnd = nums.end() - 1;

    // Move itEnd from back to front until finding the first element not equal
    // to val
    while (itBegin <= itEnd && *itEnd == val) {
      itEnd--;
      remainingNumsCount--;
    }

    // Return if all elements are equal to val
    if (itEnd < itBegin) {
      return remainingNumsCount;
    }

    // Traverse the array from front to back, swapping elements equal to val to
    // the end of the array
    while (itBegin <= itEnd) {
      if (*itBegin == val) {
        std::swap(*itBegin, *itEnd);
        itEnd--;
        remainingNumsCount--;
        // Ensure the element pointed to by itEnd is not equal to val
        while (itBegin <= itEnd && *itEnd == val) {
          itEnd--;
          remainingNumsCount--;
        }
      }
      itBegin++;
    }

    return remainingNumsCount;
  }
};