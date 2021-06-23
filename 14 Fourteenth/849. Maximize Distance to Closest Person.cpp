//https://leetcode.com/problems/maximize-distance-to-closest-person/

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        
        vector<int> right(n,n);
        int nr=n;
        for(int i=n-1;i>=0;i--){
            
            if(seats[i]==1){nr=i;continue;}
            right[i]=nr;
        }
         vector<int> left(n,-1);
        int nl=-1;
        for(int i=0;i<n;i++){
            
            if(seats[i]==1){nl=i;continue;}
            left[i]=nl;
        }
        int ans=0;

        for(int i=0;i<n;i++){
            
            if(seats[i]==1){continue;}
            
            int d;
            d =min(i-left[i],right[i]-i);
            if(right[i]==n){d=i-left[i];}
            if(left[i]==-1){d=right[i]-i;}
            
                
            
         
            ans=max(d,ans);
        }
        return ans;
        
    }
};