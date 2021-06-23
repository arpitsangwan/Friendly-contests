
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
class Solution {
public:
    int maxp(vector<int>& prices,int si,int state,int dp[][3]){
        
        if(si>=prices.size()){return 0;}
        
       if(dp[si][state]!=-1){return dp[si][state];}
        if(state==0){
           dp[si][state]= max( maxp(prices,si+1,1,dp)-prices[si],maxp(prices,si+1,0,dp) );
            return dp[si][state];
        }
        
        if(state==1){
             dp[si][state]= max( maxp(prices,si+1,2,dp)+prices[si],maxp(prices,si+1,1,dp) );
            return dp[si][state];
        }
        dp[si][state]=maxp(prices,si+1,0,dp);
        return dp[si][state];
        
    }
    
    int maxProfit(vector<int>& prices) {
        int dp[prices.size()+1][3];
        for(int i=0;i<=prices.size();i++){
            for(int k=0;k<3;k++){
            dp[i][k]=-1;}
        }
        return maxp(prices,0,0,dp);
        
    }
};