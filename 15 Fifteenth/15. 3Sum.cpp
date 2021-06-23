//https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> ans;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            while(i>0&&i<n&&nums[i]==nums[i-1]){i++;}
            if(i>=n-2){return ans;}
            
            int fp=-nums[i];
            int k=n-1;
            for(int j=i+1;j<n-1;j++){
                
                while(j>i+1&&j<n&&nums[j]==nums[j-1]){j++;}
                if(j>=n-1){break;}
                
                if(j>=k){break;}
                if(nums[j]+nums[k]==fp){ans.push_back(vector<int>{nums[i],nums[j],nums[k]});}
                if(nums[j]+nums[k]>fp){k--;j--;}
                
                
            }

        }
        return ans;

        
        
    }
};