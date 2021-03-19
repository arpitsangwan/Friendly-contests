//https://leetcode.com/problems/balance-a-binary-search-tree/
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
    vector<int> ar;
    void traverse(TreeNode* root){
        if(root==NULL){return;}
        ar.push_back(root->val);
        traverse(root->left);
        traverse(root->right);
        
    }
    TreeNode* createbst(int l,int r){
        if(l>r){return NULL;}
        int mid=l+(r-l)/2;
        TreeNode* temp=new TreeNode;
        temp->val=ar[mid];
        temp->right=createbst(mid+1,r);
        temp->left=createbst(l,mid-1);
        return temp;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        traverse(root);
        sort(ar.begin(),ar.end());
        return  createbst(0,ar.size()-1);
    }
};