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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr)
            return nullptr;
        ListNode* result = new ListNode;
        int carry = 0;
        int sum;
        ListNode * temp = result;
        while(l1 != nullptr || l2 != nullptr || carry != 0){
            sum = carry;
            carry = 0;
            if(l1 != nullptr){
                sum += l1->val;
            }
            if(l2 != nullptr){
                sum += l2->val;
            }
            carry = (sum - sum%10)/10;
            sum = sum - carry*10;
            temp->val = sum;
            if(l1 != nullptr){
                l1 = l1->next;
            }
            if(l2 != nullptr){
                l2 = l2->next;
            }
            if(l1 != nullptr || l2 != nullptr || carry != 0){
                temp->next = new ListNode;
            }
            temp = temp->next;
        }
        return result;
    }
};