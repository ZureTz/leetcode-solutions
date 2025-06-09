/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#ifdef LOCAL
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#endif

class Solution {
public:
  // Recursive solution
    ListNode *reverseList(ListNode *head) {
      if (head == nullptr || head->next == nullptr) {
        // The last node becomes the new head
        return head;
      }

      // Recursively reverse the rest of the list
      auto next = reverseList(head->next);
      
      // Set the next of the current head to null and the tail to point to the current head
      head->next->next = head; // The next node's next should point to the current head
      head->next = nullptr;
      return next;
    }

  // Iterative solution
  // ListNode *reverseList(ListNode *head) {
  //   // For cases where the list is empty or has only one node
  //   if (head == nullptr || head->next == nullptr) {
  //     return head;
  //   }

  //   ListNode *first = head, *second = head->next;
  //   while (second != nullptr) {
  //     // Reverse the link
  //     auto next = second->next;
  //     second->next = first;
  //     first = second;
  //     second = next;
  //   }
  //   // After the loop, 'first' will be the new head of the reversed list
  //   // and the original head will be the last node
  //   head->next = nullptr; // Set the next of the original head to null
  //   return first; // Return the new head of the reversed list
  // }
};