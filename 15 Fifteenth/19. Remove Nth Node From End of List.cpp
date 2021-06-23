//https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
     
        ListNode* temp=head,*temp1=head;
        n++;
        while(n&&temp){
            temp=temp->next;
            n--;
        }
        if(n){head=head->next;return head;}
        while(temp!=NULL){
            temp=temp->next;
            temp1=temp1->next;
        }
        temp1->next=temp1->next->next;
        return head;
            
    }
};