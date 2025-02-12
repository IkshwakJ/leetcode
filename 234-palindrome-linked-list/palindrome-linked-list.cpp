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
        if(head == nullptr){
            return false;
        }
        int len = 0; 
        vector<int> ls;
        ListNode* entries = head;
        while(entries!= nullptr){
            ls.push_back(entries->val);
            entries = entries->next;
            len++;
        }
        while(head != nullptr && head->val == ls.back()){
            head = head->next;
            ls.pop_back();
        }
        if(head == nullptr){
            return true;
        }
        return false;
    }
};