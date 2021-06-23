//https://leetcode.com/problems/find-pivot-index/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int csum=0,tsum=0;
        for(int i=0;i<n;i++){
            tsum+=nums[i];
        }
        for(int i=0;i<n;i++){
            if(i>0){csum+=nums[i-1];}
            if(csum==tsum-nums[i]-csum){return i;}
        }
        return -1;
    }
};