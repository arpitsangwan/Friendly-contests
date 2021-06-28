//https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
     
        if(nums.size()<=1){return 0;}
        int l=0;int n=nums.size();
        
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){l=i;break;}
             if(i==n-2){return 0;}
        }
       
        
        
        int r=n-1;
        for(int i=n-1;i>0;i--){
            if(nums[i]<nums[i-1]){r=i;break;}
        }
        
        
        int mini=INT_MAX,maxi=INT_MIN;
         
        
        
        for(int i=l;i<=r;i++){
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        
        }
        
        int li,ri;
        li=l;ri=r;
        
        for(int i=0;i<=l;i++){
            if(nums[i]>mini){li=i;break;}
        }
    
        for(int i=n-1;i>=r;i--){
            if(nums[i]<maxi){ri=i;break;}
        }
        
        return ri-li+1;
            
    }
};