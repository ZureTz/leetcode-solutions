#include <algorithm>
#include <vector>

class Solution {
  struct {
    bool operator()(const std::vector<int> &interval1,
                    const std::vector<int> &interval2) {
      if (interval1[0] == interval2[0]) {
        return interval1[1] < interval2[1];
      }
      return interval1[0] < interval2[0];
    }
  } compare;

  bool isOverlapped(const std::vector<int> &interval1,
                    const std::vector<int> &interval2) {
    if (interval1[0] > interval2[0]) {
      return isOverlapped(interval2, interval1);
    }

    // interval1[0] <= interval2[0]
    return interval2[0] <= interval1[1];
  }

public:
  std::vector<std::vector<int>>
  merge(std::vector<std::vector<int>> &intervals) {
    std::sort(intervals.begin(), intervals.end(), compare);

    std::vector<std::vector<int>> results;

    auto iter1 = intervals.begin();
    auto iter2 = iter1;

    while (iter2 != intervals.end()) {
      while (iter2 != intervals.end() && isOverlapped(*iter1, *iter2)) {
        iter1->at(1) = std::max(iter1->at(1), iter2->at(1));
        iter2++;
      }
      // Not overlapped
      results.push_back(*iter1);
      iter1 = iter2;
    }

    return results;
  }
};
