//https://leetcode.com/problems/ugly-number-ii/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1,0);
        dp[1]=1;
        int a=1,b=1,c=1;
        int i=2;
        while(a<n&&b<n&&c<n&&i<=n){
            int ins=min(dp[a]*2,min(dp[b]*3,dp[c]*5));
            if(dp[a]*2==ins){a++;}
            if(dp[b]*3==ins){b++;}
            if(dp[c]*5==ins){c++;}
            if(dp[i-1]!=ins);
                dp[i]=ins;i++;
            
        }
        
        return dp[n];
    }
};