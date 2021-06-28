//https://leetcode.com/problems/number-of-operations-to-make-network-connected/
class Solution {
public:
    
    vector<bool> v;
    vector<vector<int>> adj;
    
    void dfs(int i){
        
        if(v[i])
            return;
        v[i]=true;
        
        for(auto it:adj[i]){
            dfs(it);
        }
        return ;
    }
    
    int makeConnected(int n, vector<vector<int>>& con) {
        if(con.size()< n-1){return -1;}
        
        int c=0;
        adj.assign(n,vector<int>{});
        v.assign(n,false);
        for(auto it :con){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        for(int i=0;i<n;i++){
            if(!v[i])
            {dfs(i);c++;}
        }
        
        return c-1;
        
    }
};