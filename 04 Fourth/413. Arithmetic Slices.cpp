//https://leetcode.com/problems/arithmetic-slices/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& ar) {
        int n=ar.size();
        int ans=0;
        int i=0;
        int cl=0;
        while (i<n){
            if(cl>0){
                if( ar[i-2]-ar[i-1]==ar[i-1]-ar[i]){
                    cl++;
                    ans+=cl-3+1;
                    i++;
                }
                else{
                   cl=0;
                   i--;   
                }
                
            }
           else if(i<n-2 && ar[i]-ar[i+1]==ar[i+1]-ar[i+2]){
                    ans++;
                    i=i+3;
                    cl=3;
            }
            else {
                i++;  
            }
            
            
        }
        return ans;
    
        
        
        
    }
};