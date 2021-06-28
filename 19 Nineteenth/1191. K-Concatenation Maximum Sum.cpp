//https://leetcode.com/problems/k-concatenation-maximum-sum/

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        
        int m=1e9+7;
        int n=arr.size();
        
       long long int indm=0;
       long long  int cm=0;
        long long int ns=0;
        
        for(auto it:arr){
            ns+=it;
            if(it+cm>it){cm+=it;}
            else{cm=it;}
            
            if(indm<cm){indm=cm;}
            
        }
        
        if(k==1){return indm%m;}
        
        for(auto it:arr){
            if(it+cm>it){cm+=it;}
            else{cm=it;}
            
            if(indm<cm){indm=cm;}
        }
        
        if(k==2){return indm%m;}
        
        
            if(ns>0){
                long long int ans=(ns*(k-2)+indm);
                
                return ans%m;
            }
        
        
        
        return indm%m;
        
        
    }
};