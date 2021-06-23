//https://leetcode.com/problems/combination-sum/

class Solution {
public:
     vector<vector<int>> ans;
    
    void getcomb(vector<int>&cand,int t,int i,vector<int>&temp){
        
        if(t==0){ans.push_back(temp);return;}
        if(t<0){return;}
        
        for(int j=i;j<cand.size();j++){
            temp.push_back(cand[j]);
            getcomb(cand,t-cand[j],j,temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& cand, int t) {
        vector<int> temp;
         getcomb(cand,t,0,temp);
        return ans;
    }
};