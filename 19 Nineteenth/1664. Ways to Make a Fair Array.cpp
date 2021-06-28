//https://leetcode.com/problems/ways-to-make-a-fair-array/

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> altsumr(n+1,0),altsuml(n,0);
        
        
        for(int i=n-1;i>=0;i--){
            altsumr[i]=nums[i];
            if(i+2<=n){
            altsumr[i]+=altsumr[i+2];}
        }
        
        altsuml[0]=nums[0];
        for(int i=0;i<n;i++){
            altsuml[i]=nums[i];
            if(i-2>=0){
                altsuml[i]+=altsuml[i-2];
            }
        }
        
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int ev=0,od=0;
            
            if(i-1>=0)
                ev+=altsuml[i-1];
            if(i-2>=0)
                od+=altsuml[i-2];
            if(i+1<n)
                od+=altsumr[i+1];
            if(i+2<n)
                ev+=altsumr[i+2];
            if(ev==od){ans++;}
        }
        return ans;
    }
};