//https://leetcode.com/problems/coin-change/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        dp[0]=0;
        
        for(int i=1;i<=amount;i++){
            int temp=amount+1;
            for(int j=0;j<coins.size();j++){
                if(coins[j]<=i){temp=min(temp,1+dp[i-coins[j]]);}
            }
            dp[i]=temp;
        }
        return dp[amount]==amount+1?-1:dp[amount];
        
    }
};