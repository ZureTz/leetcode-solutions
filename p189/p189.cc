#include <vector>

class Solution {

public:
  void rotate(std::vector<int> &nums, int k) {
    const int toRotateTimes = k % nums.size();
    if (toRotateTimes == 0) {
      return;
    }

    auto moveTowards = [&](std::vector<int>::iterator &it) {
      if (it == nums.end() - 1) {
        it = nums.begin();
        return;
      }
      it++;
    };

    std::vector<int> result(nums.size());
    auto resultIt = result.begin(), numsIt = nums.end() - toRotateTimes;

    while (resultIt != result.end()) {
      *resultIt = *numsIt;
      resultIt++;
      moveTowards(numsIt);
    }

    nums = result;

    return;
  }
};