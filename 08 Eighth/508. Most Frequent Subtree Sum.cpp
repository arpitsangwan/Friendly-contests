
//https://leetcode.com/problems/most-frequent-subtree-sum/
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
    unordered_map<int,int> freq;
    
    
    int gsum(TreeNode* root){
        if(root==NULL){return 0;}
        int l=gsum(root->left);
        int r=gsum(root->right);
        
        int cs=l+r+root->val;
        if(freq.find(cs)==freq.end()){freq[cs]=0;}
        freq[cs]++;
        return cs;
        
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int temp=    gsum(root);
        vector<int> ans;
        int mf=0;
        for(auto it:freq){
            mf=max(mf,it.second);
        }
        for(auto it:freq){
            if(it.second==mf){
            ans.push_back(it.first);}
        }
        return ans;
    }
};