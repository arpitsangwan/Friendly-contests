//https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/

class Solution {
public:
    int numOfSubarrays(vector<int>& ar) {
        int m=1000000000+7;
        int n=ar.size();
        long long int odd=0,even=0;
        long long int ans=0;
        
        int cs=0;
        
        for(int i=0;i<n;i++){
            cs+=ar[i];
            if(cs&1){
                odd++;
                ans++;
                ans+=even%m;
                ans%=m;
                
            }
            else{
                even++;
                ans+=odd%m;
                ans%=m;
            }
        }
    
        return ans;
    }
};