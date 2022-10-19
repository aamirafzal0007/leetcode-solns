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
    ListNode* deleteMiddle(ListNode* head) {
        if(! head->next) 
            return NULL;
        int count=0;
        
        ListNode *fast= head->next, *slow=head, *prev=head;
        while(slow) 
            {
            count++;
            slow=slow->next;
        }
        slow=head;
        int i=0;
        while(slow&&i!=count/2) 
            {
            
            prev=slow;
            slow=slow->next;
            i++;
        }
        prev->next=slow->next;
        return head;
    }
};