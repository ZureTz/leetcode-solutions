#include <unordered_map>

class Solution {
  std::unordered_map<int, bool> map = {{1, true}};

public:
  bool isHappy(int n) {
    const auto foundIt = map.find(n);
    if (foundIt != map.end()) {
      return foundIt->second;
    }
    // Missed in the map
    map.insert({n, false});

    // do foreach sum
    int sum = 0;
    for (int temp = n; temp > 0; temp /= 10) {
      const int lastDigit = temp % 10;
      sum += lastDigit * lastDigit;
    }

    // Find if sum satisfies
    const bool nextResult = isHappy(sum);
    map.at(n) = nextResult;
    return nextResult;
  }
};