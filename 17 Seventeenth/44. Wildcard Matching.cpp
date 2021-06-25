//https://leetcode.com/problems/wildcard-matching/

class Solution {
public:
    vector<vector<int>> dp;
    
    bool ismatch(string &s,string &p,int k,int l){
        
        if(dp[k][l]!=-1){return dp[k][l];}
        if(p.length()==l){
            if(s.length()==k){return true;}
            return false;
        }
        
        if(p[l]=='?'){
            if(s.length()==k){return false;}
            dp[k][l]=ismatch(s,p,k+1,l+1);return dp[k][l];
        }
        
        if(p[l]!='*'){
            if(s.length()==k||s[k]!=p[l]){return false;}
            
            dp[k][l]= ismatch(s,p,k+1,l+1);return dp[k][l];
        }
        
        if(s.length()==k){dp[k][l]= ismatch(s,p,k,l+1);return dp[k][l];}
        
        int j;
        for(j=l;j<p.length();j++){
            if(p[j]!='*'){break;}
        }
        
        if(j==p.length()){return true;}
        
        if(p[j]=='?'){
            for(int i=k;i<s.length();i++){
            
                if(ismatch(s,p,i+1,j+1)){dp[k][l]= true;return dp[k][l];}
            
            }
        }
        else{
        for(int i=k;i<s.length();i++){
            if(p[j]==s[i]){
                if(ismatch(s,p,i+1,j+1)){dp[k][l]= true;return dp[k][l];}
            }
        }}
        dp[k][l]= false;
        return dp[k][l];
    }
    
    bool isMatch(string s, string p) {
          
        dp.assign(s.length()+1,vector<int>(p.length()+1,-1));
      return  ismatch(s,p,0,0);
        
    }
};