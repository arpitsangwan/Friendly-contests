//https://leetcode.com/problems/edit-distance/
class Solution {
public:
    vector<vector<int>> dp;
    
    string s,t;
    
    int minop(int i,int j){
        if(i==s.length()){return t.length()-j;}
        if(j==t.length()){return s.length()-i;}
        
        if(dp[i][j]!=-1){return dp[i][j];}
        
        int ans=INT_MAX;
        
        if(s[i]==t[j]){
            ans=minop(i+1,j+1);
        }
        else{
            ans=1+minop(i+1,j+1);
        }
        
        int a=1+minop(i,j+1);
        int b=1+minop(i+1,j);
        
        ans=min(ans,min(a,b));
        dp[i][j]=ans;
        return ans;
    }
    
    
    int minDistance(string word1, string word2) {
        s=word1;t=word2;
        dp.assign(s.length(),vector<int>(t.length(),-1));
        return minop(0,0);
    }
};