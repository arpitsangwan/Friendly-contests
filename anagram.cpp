//https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string,vector<string>> umap;
        for(int i=0;i<strs.size();i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            if(umap.count(temp)){
                   umap[temp].push_back(strs[i]);
            }
            else{umap[temp]=vector<string> (1,strs[i]); }
        }
         
        vector<vector<string>> ans;
        for(auto it:umap){
            ans.push_back(it.second);
        }
        return ans;
    }
};