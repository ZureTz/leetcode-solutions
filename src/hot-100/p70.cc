#include <unordered_map>
class Solution {
  std::unordered_map<int, long long> memo = {{1, 1}, {2, 2}};

public:
  int climbStairs(int n) {
    // First, check if n is already in the memo
    auto it = memo.find(n);
    if (it != memo.end()) {
      return it->second;
    }

    // If not, calculate it recursively
    long long result = climbStairs(n - 1) + climbStairs(n - 2);
    // Put the result in the memo
    memo[n] = result;
    return result;
  }
};