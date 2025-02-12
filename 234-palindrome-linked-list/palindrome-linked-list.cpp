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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *prev = nullptr, *curr = slow, *temp;
        while (curr) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        slow = head;
        while (prev) {
            if (slow->val != prev->val) return false;
            slow = slow->next;
            prev = prev->next;
        }
        return true;
    }
};