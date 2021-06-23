//https://leetcode.com/problems/unique-paths/

class Solution {
public:
    
    int paths(int m,int n,int sx,int sy,int**dp){
        if(sx==n||sy==m){return 0;}
        if(sx==n-1 && sy==m-1){return 1;}
        if(dp[sy][sx]!=-1){return dp[sy][sx];}
        dp[sy][sx]= paths(m,n,sx+1,sy,dp)+paths(m,n,sx,sy+1,dp);
        return dp[sy][sx];
    }
    
    
    int uniquePaths(int m, int n) {
        int**dp=new int*[m];
        
        for(int i=0;i<m;i++){
            dp[i]=new int[n];
            for(int j=0;j<n;j++){
                dp[i][j]=-1;
            }
        }
        
        return paths(m,n,0,0,dp);
    }
};