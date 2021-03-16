//https://leetcode.com/problems/distinct-subsequences/
class Solution {
public:
    
    int count(string s,string t,int si,int ti,int**dp){
        if(ti==t.length()){return 1;}
        if(si==s.length()){return 0;}
        if(dp[si][ti]!=-1){return dp[si][ti];}
        if(s[si]==t[ti]){
            dp[si][ti]= count(s,t,si+1,ti+1,dp)+count(s,t,si+1,ti,dp);
            return dp[si][ti];
        }
        dp[si][ti]= count(s,t,si+1,ti,dp);
        return dp[si][ti];
    }
    
    
    int numDistinct(string s, string t) {
        int **dp=new int*[s.length()];
        for(int i=0;i<s.length();i++){
            dp[i]=new int[t.length()];
            for(int j=0;j<t.length();j++){
                dp[i][j]=-1;
            }
            
        }
        
        return count(s,t,0,0,dp);
        
    }
};