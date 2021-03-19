//https://leetcode.com/problems/swim-in-rising-water/
class Solution {
public:

    int ans=INT_MAX;
     void leasttime(vector<vector<int>>& grid,int sx,int sy,int e,int t,vector<vector<int>>& visited){
       
         if(sx==e&&sy==e){
             ans=min(ans,t);
             return;
         }
         
         visited[sx][sy]=t;
        
         if(sx+1<=e){
         if( visited[sx+1][sy]==-1){
              int ti=max(grid[sx+1][sy],t);
             leasttime(grid,sx+1,sy,e,ti,visited);
         }
         else if(visited[sx+1][sy]>max(t,grid[sx+1][sy])){
              int ti=max(grid[sx+1][sy],t);
             leasttime(grid,sx+1,sy,e,ti,visited); 
         }
         }
         
         if(sx-1>=0){
          if( visited[sx-1][sy]==-1){
              int ti=max(grid[sx-1][sy],t);
             leasttime(grid,sx-1,sy,e,ti,visited);
         }
         else if(visited[sx-1][sy]>max(t,grid[sx-1][sy])){
              int ti=max(grid[sx-1][sy],t);
             leasttime(grid,sx-1,sy,e,ti,visited); 
         }
         }
         if(sy-1>=0 ){
           if(visited[sx][sy-1]==-1){
              int ti=max(grid[sx][sy-1],t);
             leasttime(grid,sx,sy-1,e,ti,visited);
         }
         else if(visited[sx][sy-1]>max(t,grid[sx][sy-1])){
              int ti=max(grid[sx][sy-1],t);
             leasttime(grid,sx,sy-1,e,ti,visited); 
         }
         }
         if(sy+1<=e ){
          if( visited[sx][sy+1]==-1){
              int ti=max(grid[sx][sy+1],t);
             leasttime(grid,sx,sy+1,e,ti,visited);
         }
         else if(visited[sx][sy+1]>max(t,grid[sx][sy+1])){ 
              int ti=max(grid[sx][sy+1],t);
             leasttime(grid,sx,sy+1,e,ti,visited); 
         }      
         }
         return;
         
         
     } 
    
    
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> visited;
        for(int i=0;i<n;i++){
            vector<int> temp;
            visited.push_back(temp);
            for(int j=0;j<n;j++){
                visited[i].push_back(-1);
            }
        }
       
         leasttime(grid,0,0,n-1,grid[0][0],visited);
         
        return ans;
    }
};