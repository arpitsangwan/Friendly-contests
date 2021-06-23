//https://leetcode.com/problems/interleaving-string/

class Solution {
public:
    unordered_map<string,bool> umap;
    
    bool isin(string s,string t,string x){
        if(x.length()==0){
            if(s.length()==0&&t.length()==0){return true;}
            return false;
        }
        if(s.length()==0){
            return false;
        }
        
        string key=s+" "+t;
        if(umap.find(key)!=umap.end()){return umap[key];}
        
        for(int i=0;i<s.length();i++){
            if(s[i]==x[i]){
                if(isin(t,s.substr(i+1),x.substr(i+1))){umap[key]=true;return true;}
            }
            else{break;}
        }
        umap[key]=false;
        return false;
        
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length()){return false;}
        if(isin(s1,s2,s3)){return true;}
        if(isin(s2,s1,s3)){return true;}
        return false;
    }
};