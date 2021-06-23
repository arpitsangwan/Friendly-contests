//https://leetcode.com/problems/longest-univalue-path/

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
    int ans=1;
    int lpath(TreeNode* root){
        if(root==NULL){return 0;}
        
        int left=lpath(root->left);
        int right=lpath(root->right);
        int an=1;
        if(root->left&&root->left->val==root->val){an+=left;ans=max(ans,an);}
        if(root->right&&root->right->val==root->val){an=max(an,1+right);ans=max(ans,an);}
        
        if(root->right&&root->left){
            if(root->right->val==root->left->val&&root->left->val==root->val){
                ans=max(ans,left+right+1);
            }
        }
        
        
        return an;
        
  
    }
    
    int longestUnivaluePath(TreeNode* root) {
        if(!root){return 0;}
        int a=lpath(root);
        return ans-1;
    }
};