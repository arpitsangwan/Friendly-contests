//https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
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
 unordered_map<string,int> umap;
   
    int length(TreeNode* root, int dir){
        if(root==NULL){
            return 0;
        }
        ostringstream get_add;
        get_add << root;
        string key =get_add.str();
        key+=char(dir+'0');
        if(umap[key]){return umap[key];}
      if(dir==1){ umap[key]= 1+length(root->right,0);return umap[key];}
        umap[key]= 1+length(root->left,1);return umap[key];
        
    }
    void longest(TreeNode* root,int & maxl){
        if(root==NULL){
            return;
        }
        
        
        
        maxl=max(maxl,max(length(root,1)-1,length(root,0)-1 ) );
        longest(root->left,maxl);
        longest(root->right,maxl);
        
    }
    
    
    
    int longestZigZag(TreeNode* root) {
        
        int maxl=0;
        longest(root,maxl);
        return maxl;
        
    }
};