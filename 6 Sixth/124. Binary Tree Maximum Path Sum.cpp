//https://leetcode.com/problems/binary-tree-maximum-path-sum/
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
    int ans=INT_MIN;
    unordered_map<string,int>umap;
   
    int sum(TreeNode* root,int cm){
        if(root==NULL){return 0;}
        ostringstream get_add;
        get_add<<root;
        string key=get_add.str();
        if(umap[key]){return umap[key];}
        umap[key]=max(cm,root->val+max(sum(root->left,0),sum(root->right,0)));
        return umap[key];
        
    }
    
    int maxsum(TreeNode* root){
        return root->val+sum(root->left,0)+sum(root->right,0);
        
    }
    
    
    void traverse(TreeNode* root){
        if(root==NULL){return;}
        ans=max(ans, maxsum(root));
        traverse(root->left);
        traverse(root->right);
    }
    
    
    int maxPathSum(TreeNode* root) {
        traverse(root);
        return ans;
    }
};