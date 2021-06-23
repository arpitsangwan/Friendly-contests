
//https://leetcode.com/problems/number-of-matching-subsequences/
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char,set<int>> umap;
        for(int i=0;i<s.length();i++){
            if(umap.find(s[i])==umap.end()){umap[s[i]]=set<int>();}
            umap[s[i]].insert(i);
        }
        
        int ans=0;
        for(auto it:words){
            int li=-1;
            int i=0;
            for(i=0;i<it.length();i++){
                if(umap.find(it[i])==umap.end()){break;}
                set<int>:: iterator pt=umap[it[i]].upper_bound(li);
                if(pt==umap[it[i]].end()){break;}
                li=*pt;
            }
            if(i==it.length()){ans++;}
        }
        return ans;
    }
};