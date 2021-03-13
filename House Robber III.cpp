class Solution {
public:
    unordered_map<string,int> umap;
    int maxamount(TreeNode * root,int state){
        string key="";
        ostringstream get_the_address; 
        get_the_address << root;
        key+=  get_the_address.str();
        key+=char(state+'0');
        
        if(root==NULL){
            return 0;
        }
        if(umap[key]){return umap[key];}
        
        int maxsum=0;
        if(state==0){
        umap[key]= max( root->val+maxamount(root->left,1)+maxamount(root->right,1), maxamount(root->left,0)+maxamount(root->right,0));
            return umap[key];
        }
        
        else{
            
        umap[key]= maxamount(root->right,0)+maxamount(root->left,0);    
         return umap[key];   
        }
        
        
    }
    
    int rob(TreeNode* root) {
        
        return maxamount(root,0);
        
    }
};