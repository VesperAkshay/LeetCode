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
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return;
        }

        // Find the middle of the linked list
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the linked list
        ListNode *prev = nullptr, *curr = slow->next, *tmp;
        slow->next = nullptr;
        while (curr) {
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        // Merge the two halves
        ListNode *first = head, *second = prev;
        while (second) {
            tmp = first->next;
            first->next = second;
            second = second->next;

            if (tmp) {
                first->next->next = tmp;
                first = tmp;
            } else {
                break;
            }
        }
    }
};
