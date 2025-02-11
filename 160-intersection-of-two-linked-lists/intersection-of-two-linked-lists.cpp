/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<ListNode*> A;
        vector<ListNode*> B;
        while(headA != nullptr){
            A.push_back(headA);
            headA = headA->next;
        }
        while(headB != nullptr){
            B.push_back(headB);
            headB = headB->next;
        }
        ListNode * result = nullptr;
        while(!A.empty() && !B.empty() && A.back() == B.back()){
            result = A.back();
            A.pop_back();
            B.pop_back();

        }
        return result;
    }
};