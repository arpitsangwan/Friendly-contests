//https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int s1=0,s2=0;
        vector<int>* g,*l;
        
        for(auto it:nums1){s1+=it;}
        for(auto it:nums2){s2+=it;}
        g=&nums1;l=&nums2;
        if(s1<s2){
            int t=s1;
            s1=s2;
            s2=t;
            g=&nums2;
            l=&nums1;
        }
        
        int d=s1-s2;
        if(d==0){return 0;}
        
       vector<int> op(6);
        op[0]=op[1]=op[2]=op[3]=op[4]=op[5]=0;
        for(auto it:*g){
            op[it-1]++;
            
        }
        
        for(auto it:*l){
            op[6-it]++;
        }
        
        int m=5;int ans=0;
        while(m>0){
            if(op[m]!=0){
            int sb=m*op[m];
            if(sb>=d){
                if(d%m>0){ans++;}
                ans+=d/m;
                return ans;
            }
            ans+=op[m];
            d-=sb;}
            m--;
        }
        
        return m==0?-1:ans;
        
    }
};