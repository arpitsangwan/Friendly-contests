//https://leetcode.com/problems/isomorphic-strings/


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> umap;
        if(t.length()!=s.length()){return false;}
        int i=0;
        for(auto it:s){
            if(umap.find(it)==umap.end()){
                
                umap[it]=t[i];
            }
            
            if(umap[it]!=t[i]){return false;}
            i++;
        }
        
        i=0;
        string temp=s;
        s=t;
        t=temp;umap.clear();
        for(auto it:s){
            if(umap.find(it)==umap.end()){
                
                umap[it]=t[i];
            }
            
            if(umap[it]!=t[i]){return false;}
            i++;
        }
        return true;
    }
};