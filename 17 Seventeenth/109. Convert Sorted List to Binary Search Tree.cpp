//https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* tree(ListNode* start,ListNode* mid,ListNode* end){
        
        if(mid==NULL){return NULL;}
        
        if(start==end){return NULL;}
        if(start==mid){
        
            TreeNode* re=new TreeNode(mid->val);
            return re;
        }
           
        TreeNode* head=new TreeNode(mid->val);
           
           
          ListNode* temp=start,*temp1=start; 
           
        while(temp1!=mid&&temp1->next!=mid){
            temp1=temp1->next->next;
            temp=temp->next;
        }
           
           TreeNode* left=tree(start,temp,mid);
        
        
           temp=mid->next;temp1=mid->next;
           while(temp1!=end&&temp1->next!=end){
            temp1=temp1->next->next;
            temp=temp->next;
          }
           TreeNode* right=tree(mid->next,temp,end);
           
           head->left=left;
           head->right=right;
           return head;
        
        
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        if(head==NULL){return NULL;}
        
        ListNode* temp1=head,*temp=head;
        
        while(temp1!=NULL&&temp1->next!=NULL){
            temp1=temp1->next->next;
            temp=temp->next;
        }
        
        
        return tree(head,temp,NULL);
        
    }
};