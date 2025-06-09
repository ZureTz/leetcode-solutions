#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> permute(std::vector<int> &nums) {
    std::vector<std::vector<int>> result;

    auto dfs = [&](auto &&self, int firstToSwap,
                   std::vector<int> &current) -> void {
      if (firstToSwap == nums.size()) {
        result.push_back(current);
        return;
      }

      for (int i = firstToSwap; i < nums.size(); i++) {
        std::swap(current[firstToSwap], current[i]); // swap
        self(self, firstToSwap + 1, current);
        std::swap(current[firstToSwap], current[i]); // backtrack
      }
    };

    std::vector<int> current = nums;
    dfs(dfs, 0, current);

    return result;
  }
};