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
    void deleteNode(ListNode* node) {
        ListNode *cur=node,*prev=NULL;
        while(cur->next)
        {
            prev=cur;
            cur->val=cur->next->val;
            cur=cur->next;
        }
        prev->next=NULL;
        
        
        
    }
};