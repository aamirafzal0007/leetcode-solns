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
       cur->val=cur->next->val;
        prev=cur->next;
        cur->next=cur->next->next;
        delete prev;
        
        
        
    }
};