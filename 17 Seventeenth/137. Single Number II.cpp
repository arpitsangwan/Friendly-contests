//https://leetcode.com/problems/single-number-ii/

class Solution {
public:
    
    int singleNumber(vector<int>& nums) {
        int n=0;
        vector<int> mask(33,0);
        for(int i=0;i<nums.size();i++){
            long long  temp=nums[i];
            if(temp<0){temp*=-1;n++;}
            int p=0;
            while(temp){
                if(temp&1){mask[p]++;}
                p++;
                temp=temp>>1;
            }
        }
        
        long long  ans=0;
        for(int i=0;i<mask.size();i++){
            if(mask[i]%3){
                ans+=pow(2,i);
            }
        }
        if(n%3){ans*=-1;}
        return ans;
    }
};