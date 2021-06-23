//https://leetcode.com/problems/shortest-bridge/

class Solution {
public:
    vector<vector<int>> grid;int n,m;
    map<pair<int,int>,bool> umap;
    
    void dfs(int i,int j){
        if(i==n||i<0||j==m||j<0||grid[i][j]==0){return;}
        
        grid[i][j]=0;
        umap[make_pair(i,j)]=true;
        dfs(i+1,j);
        dfs(i,j+1);
        dfs(i,j-1);
        dfs(i-1,j);
        return ;
    }
    
    
    
    int shortestBridge(vector<vector<int>>& g) {
    grid=g;
        n=grid.size();m=grid[0].size();
        
        
        bool flag=false;
        for(int i=0;i<n;i++){
            if(flag){break;}
           for(int j=0;j<m;j++){
               
                 if(grid[i][j]==1){
                     dfs(i,j);
                     flag=true;break;
                 }

           }
            
        }
        int ans=INT_MAX;

        queue<vector<int>> q;    
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push(vector<int>{i,j,0});
                }
              
            }
        }
        
        
        while(!q.empty()){
            vector<int> temp=q.front();q.pop();
            if(umap.find(make_pair(temp[0],temp[1]))!=umap.end()){return temp[2]-1;}
            int i=temp[0],j=temp[1],d=temp[2];
            if(i+1<n&&grid[i+1][j]==0){q.push(vector<int>{i+1,j,d+1});grid[i+1][j]=1;}
            if(j+1<m&&grid[i][j+1]==0){q.push(vector<int>{i,j+1,d+1});grid[i][j+1]=1;}
            if(i-1>=0&&grid[i-1][j]==0){q.push(vector<int>{i-1,j,d+1});grid[i-1][j]=1;}
            if(j-1>=0&&grid[i][j-1]==0){q.push(vector<int>{i,j-1,d+1});grid[i][j-1]=1;}
            
        }
        
        
    
        return ans;
    }
};