
//https://leetcode.com/problems/next-greater-element-ii/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(),-1);
        
        for(int i=nums.size()-2;i>=0;i--){
            int j=i+1;
            while(j<nums.size()&& nums[j]<=nums[i]){
                j=ans[j];
                if(j==-1){break;}
            }
            if(j==-1||j==nums.size()){ans[i]=-1;}
            else{
                ans[i]=j;
            }
            
        }
       for(int i=0;i<ans.size();i++){
           if(ans[i]!=-1){continue;}
           int j=0;
           while(j<i &&nums[j]<=nums[i]){
               j=ans[j];
               if(j==-1){break;}
           }
           if(j==-1||j>=i){continue;}
           ans[i]=j;
       }
        for(int i=0;i<ans.size();i++){
            if(ans[i]==-1){continue;}
            ans[i]=nums[ans[i]];
        }
        return ans;
    }
};