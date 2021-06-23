//https://leetcode.com/problems/max-area-of-island/
class Solution {
public:
   int maxa=0;
    
    int maxarea(vector<vector<int>>& grid,int i,int j,int r, int c){
       if(i>=r||i<0||j>=c||j<0){return 0;} 
        if(grid[i][j]==0){return 0;}
        
        int ans=1;
        
        
                  grid[i][j]=0;
                ans+=maxarea(grid,i+1,j,r,c);
                ans+=maxarea(grid,i-1,j,r,c);
               ans+= maxarea(grid,i,j+1,r,c);
                ans+=maxarea(grid,i,j-1,r,c);
        
        return ans;
        
    }
    
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       
        int r=grid.size();
        int c=grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                maxa=max(maxa,maxarea(grid,i,j,r,c));
            }
        }
        return maxa;
        
    }
};