//https://leetcode.com/problems/dungeon-game/

class Solution {
public:
    
   
    
    int calculateMinimumHP(vector<vector<int>>& dg) {
        int n=dg.size(),m=dg[0].size();
        vector<vector<int>> minh(n,vector<int>(m));
        
        minh[n-1][m-1]=max(1,1-dg[n-1][m-1]);
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                
                if(i==n-1&&j==m-1){continue;}
                int ans=INT_MAX;
                if(i+1<n){
                    ans=min(ans,minh[i+1][j]);
                    if(ans<0){ans=1;}
                }
                if(j+1<m){
                    ans=min(ans,minh[i][j+1]);
                }
                
                if(dg[i][j]>=ans){minh[i][j]=1;}
                else{
                    minh[i][j]=ans-dg[i][j];
                    if(minh[i][j]<0){minh[i][j]=1;}
                }
                
            }
            
        }
        return minh[0][0];
        
    }
};