
//https://leetcode.com/problems/longest-well-performing-interval/

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n=hours.size();
        
        for(int i=0;i<n;i++){
            if(hours[i]>8){
                hours[i]=1;
            }    
            else{
                hours[i]=0;
            }
        }
        
        
        vector<int> s(n,0);
        int cd=0;
        for(int i=0;i<n;i++){
               if(hours[i]==1){cd++;}
                else{cd--;}
            s[i]=cd;
        }
        for(auto it:s){
            cout<<it<<" ";
        }
        int lp=INT_MIN;
        int k=n-1;
        int ans=0;
        int mn=INT_MIN;
        for(int i=n-1;i>=0;i--){
            if(s[i]<mn){continue;}
            else{mn=s[i];}
            if(s[i]>0){ans=max(ans,i+1);return ans;}
            
            for(int j=0;j<=k;j++){
                if(s[i]-s[j]>0){ans=max(ans,i-j);lp=j;break;}   
            }
        }
        
        return ans;
    }
};