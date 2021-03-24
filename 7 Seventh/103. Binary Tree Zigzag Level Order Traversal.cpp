//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
    TreeNode* queue[3000];
    int start=0;
    int end=0;
   

    
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int flag=1;
        vector<vector<int>> ans;
        if(root==NULL){ return ans;}
        queue[end]=root;
        end++;
        queue[end]=NULL;
        end++;
        
       vector<int> temp;
        while(start<end){
            
            TreeNode* pop=queue[start];
            start++;
            
            if(pop!=NULL){
                temp.push_back(pop->val);
                if(pop->left){queue[end]= pop->left;
                end++;}
                 if(pop->right){queue[end]=pop->right;
                 end++;}
            }
            
            if(start<end&&queue[start]==NULL){
                
                queue[end]=NULL;
                if(flag==1){
                ans.push_back(temp);flag=0;}
                else{
                    reverse(temp.begin(),temp.end());
                    ans.push_back(temp);
                    flag=1;
                }
                if(end==start+1){break;}
                end++;
                
               temp.clear();
            }
                  
        }
        
       return ans;
        
        
   
        
        
    }
};