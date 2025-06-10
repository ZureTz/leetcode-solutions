#ifdef LOCAL
#include "list.h"
#endif

class Solution {
public:
  bool isPalindrome(ListNode *head) {
    auto *first = head, *second = head;
    // Find the middle of the list
    while (second && second->next) {
      first = first->next;
      second = second->next->next;
    }

    // Reverse the second half of the list
    auto *prev = first, *curr = first->next;
    while (curr) {
      auto *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    // Set the end of the first half to null
    first->next = nullptr;
    // Compare the first half and the reversed second half
    auto *firstHalf = head, *secondHalf = prev;
    while (firstHalf && secondHalf) {
      if (firstHalf->val != secondHalf->val) {
        return false; // Not a palindrome
      }
      firstHalf = firstHalf->next;
      secondHalf = secondHalf->next;
    }

    return true; // All values matched, it's a palindrome
  }
};