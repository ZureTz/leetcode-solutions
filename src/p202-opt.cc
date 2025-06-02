class Solution {
  int bitSum(int num) {
    int sum = 0;
    while (num > 0) {
      const int lastDigit = num % 10;
      sum += lastDigit * lastDigit;
      num /= 10;
    }
    return sum;
  }

public:
  bool isHappy(int n) {
    int slow = bitSum(n), fast = bitSum(slow);
    while (slow != fast) {
      slow = bitSum(slow);
      fast = bitSum(fast);
      fast = bitSum(fast);
    }
    return slow == 1;
  }
};