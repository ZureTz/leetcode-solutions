#include <iostream>
#include <vector>

class Solution {
public:
  void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    std::vector<int> result(m + n);
    std::vector<int>::iterator dest = result.begin();

    std::vector<int>::iterator it1 = nums1.begin(), it2 = nums2.begin();
    while (it1 != nums1.begin() + m && it2 != nums2.begin() + n) {
      if (*it1 < *it2) {
        *dest++ = *it1++;
        continue;
      }
      *dest++ = *it2++;
    }

    auto toBeContinuedIt = it1 == nums1.begin() + m ? it2 : it1;
    auto toBeContinuedItEnd =
        it1 == nums1.begin() + m ? nums2.begin() + n : nums1.begin() + m;
    while (toBeContinuedIt != toBeContinuedItEnd) {
      *dest++ = *toBeContinuedIt++;
    }

    // Copy back
    nums1 = result;
  }
};

int main(int argc, char const *argv[]) {
  Solution solution;

  std::vector<int> v1 = {1, 2, 3, 0, 0, 0};
  std::vector<int> v2 = {2, 5, 6};

  solution.merge(v1, 3, v2, 3);

  for (const auto num : v1) {
    std::cout << num << ' ';
  }

  return 0;
}