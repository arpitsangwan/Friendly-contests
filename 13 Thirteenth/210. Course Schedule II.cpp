//https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
            vector<vector<int>> adj;
        stack<int> ord;
     vector<bool> v;
    
    void dfs(int i){
        v[i]=true;
        
        for(auto it:adj[i]){
            if(!v[it]){
                dfs(it);
            }
        }
        ord.push(i);
    }
    
    
    
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        
        adj.assign(n,vector<int>{});
        
        for(auto it:pre){
            adj[it[1]].push_back(it[0]);
        }    
        v.assign(n,false);
        for(int i=0;i<n;i++){
            if(!v[i]){
               dfs(i); 
            }
                
        }
        
        vector<int> ans;
        v.assign(n,false);

        while(!ord.empty()){
            int temp=ord.top();ord.pop();
            v[temp]=true;
            for(auto it:adj[temp]){
                if(v[it]){return vector<int>{};}
            }
            ans.push_back(temp);
        }
        return ans;
    }
};