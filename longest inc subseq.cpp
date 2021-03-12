
//https://leetcode.com/problems/longest-continuous-increasing-subsequence/
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int prev=0,next=1,maxl=1,l=1;
        if(nums.size()==0){return 0;}
        while(next<nums.size()){
            if(nums[next]>nums[prev]){
                next++;
                prev++;
                l++;
                maxl=max(maxl,l);
            }
            else{
                prev=next;
                l=1;
                next++;
            }
        }
    return maxl;
    }
};