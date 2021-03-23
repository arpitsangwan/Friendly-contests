//https://leetcode.com/problems/remove-k-digits/
class Solution {
public:
   
    string removeKdigits(string nums, int k) {
        int i=0;
        while(k>0&& i<nums.length()-1){
            if(nums[i]>nums[i+1]){
                nums=nums.substr(0,i)+nums.substr(i+1);
                if(i>0){i--;}
                k--;
            }
            else{i++;}
           
            while(nums[0]=='0'&& nums.length()>1){nums=nums.substr(1);}
        }
        
        nums=nums.substr(0,nums.length()-k);
        return nums.length()?nums:"0";
    }
};
