class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1){return true;}
        bool dp[nums.size()];
        dp[nums.size()-1]=true;
        for(int i=nums.size()-2;i>=0;i--){
            dp[i]=false;
            for(int j=1;j<=nums[i];j++){
                if(j+i<=nums.size()-1){
                    if(dp[i+j]){dp[i]=true;break;}
                }
            }
            
        }
        return dp[0];
        
    }
};