//https://leetcode.com/problems/majority-element/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int n=nums.size();
        int count=1,val=nums[0];
        for(int i=1;i<n;i++){
            if(val!=nums[i]){
                if(count){count--;}
                else{count=1;val=nums[i];}
            }
            else{
                count++;
            }
        }
        return val;
        
    }
};