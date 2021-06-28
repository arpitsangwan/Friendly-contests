//https://leetcode.com/problems/patching-array/

class Solution {
public:
    /***************NOT MY CODE*****************/
    
    int minPatches(vector<int>& nums, int n) {
        long long maxrange=1,ans=0;
        sort(nums.begin(),nums.end());
        int i=0;
        if(nums[0]!=1){ans++;}
        else{
            i++;
        }
        for(i;i<nums.size();i++)
        {
            
            
            while(nums[i]>maxrange+1){
                if(maxrange>=n){return ans;}
                ans++;
                maxrange=(maxrange)*2+1;
            }
            
            
            maxrange=max(maxrange,maxrange+nums[i]);
            
            if(maxrange>=n){return ans;}
        }
        
        while(maxrange<n){
            ans++;
            maxrange=maxrange*2+1;
        }
        return ans;
    }
};