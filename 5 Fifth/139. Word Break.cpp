//https://leetcode.com/problems/word-break/
class Solution {
public:
    unordered_map<string,bool> umap;
    
   
    
     bool canfind(string s, vector<string>& dict) {
         if(s.length()==0){return true;}
         
         if(umap.find(s)!=umap.end()){return umap[s];}
         
         for(int j=0;j<s.length();j++){
             if(umap[s.substr(0,j+1)]){
                if(j==s.length()-1){umap[s]= true;return true;}
                 if(canfind(s.substr(j+1),dict)){umap[s]= true;return true;}
             }
         }
         umap[s]= false;return false;
            
        
         
         
     
    }
 
    bool wordBreak(string s, vector<string>& wordDict) {
        for(int i=0;i<wordDict.size();i++){
            umap[wordDict[i]]=true;
        }
        return canfind(s,wordDict);
        
    }
};