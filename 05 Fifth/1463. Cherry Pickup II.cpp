//https://leetcode.com/problems/cherry-pickup-ii/
class Solution {
public:
    
    int maxcherry(vector<vector<int>>& grid,int i,int j,int k,int l,int r,int c,int***dp ){
        if(i==r||k==r||j==c||l==c||j==-1||l==-1){
            return 0;
        }
        
        if(dp[i][j][l]!=-1){return dp[i][j][l];}
        
        int ans=0;
        int left=grid[i][j];
        int right=grid[k][l];
        ans+=left;
        grid[i][j]=0;
        
        ans+=grid[k][l];
        grid[k][l]=0;
        int temp=0;
       temp=max(temp, maxcherry(grid,i+1,j-1,k+1,l,r,c,dp) );
        temp=max(temp,maxcherry(grid,i+1,j-1,k+1,l-1,r,c,dp));
       temp=max(temp, maxcherry(grid,i+1,j-1,k+1,l+1,r,c,dp));
       temp=max(temp, maxcherry(grid,i+1,j,k+1,l,r,c,dp));
        temp=max(temp,maxcherry(grid,i+1,j,k+1,l-1,r,c,dp));
        temp=max(temp,maxcherry(grid,i+1,j,k+1,l+1,r,c,dp));
        temp=max(temp,maxcherry(grid,i+1,j+1,k+1,l,r,c,dp));
       temp=max(temp, maxcherry(grid,i+1,j+1,k+1,l-1,r,c,dp));
        temp=max(temp,maxcherry(grid,i+1,j+1,k+1,l+1,r,c,dp));
        grid[i][j]=left;
        grid[k][l]=right;
        dp[i][j][l]= ans+temp;
        return dp[i][j][l];
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int***dp=new int**[r];
        for(int i=0;i<r;i++){
            dp[i]=new int*[c];
            for(int j=0;j<c;j++){
                dp[i][j]=new int[c];
                for(int k=0;k<c;k++){
                    dp[i][j][k]=-1;
                }
            }
        }
        
        unordered_map<string,int> umap;
        return maxcherry(grid,0,0,0,c-1,r,c,dp);
    }
};