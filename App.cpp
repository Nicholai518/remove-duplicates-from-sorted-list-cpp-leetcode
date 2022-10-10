#include <iostream>
using namespace std;


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  class Solution {
  public:
      ListNode* deleteDuplicates(ListNode* head) {

          ListNode* current_node = head;

          // while we have a current node and there is a next node
          while (current_node != nullptr && current_node->next != nullptr) {

              // because list is sorted, check and see if the values are the same at each node
              if (current_node->val == current_node->next->val) {

                  // because the numbers are the same, skip over the "next" node
                  current_node->next = current_node->next->next;
              }

              // there is NOT a duplicate value, the node values are different
              else {
                  current_node = current_node->next;
              }
          }

          return head;
      }
  };

int main()
{
    Solution solution;

    ListNode example_one_node_three(2);
    ListNode example_one_node_two(1, &example_one_node_three);
    ListNode example_one_head(1, &example_one_node_two);

    ListNode example_two_node_five(3);
    ListNode example_two_node_four(3, &example_two_node_five);
    ListNode example_two_node_three(2, &example_two_node_four);
    ListNode example_two_node_two(1, &example_two_node_three);
    ListNode example_two_head(1, &example_two_node_two);

    cout << "Example One : ";

    ListNode * current_node = solution.deleteDuplicates(&example_one_head);
    while (current_node != nullptr) {
        cout << current_node->val;
        current_node = current_node->next;
    }

    cout << endl;

    cout << "Example Two : ";
    current_node = solution.deleteDuplicates(&example_two_head);
    while (current_node != nullptr) {
        cout << current_node->val;
        current_node = current_node->next;
    }

    cout << endl;
	return 0;
}
