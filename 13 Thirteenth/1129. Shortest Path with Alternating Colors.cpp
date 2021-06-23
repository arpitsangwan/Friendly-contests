//https://leetcode.com/problems/shortest-path-with-alternating-colors/

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        
        unordered_map<int,vector<int>> red,blue;
        
        for(auto it:red_edges){
            if(red.find(it[0])==red.end()){red[it[0]]=vector<int>{};}
            red[it[0]].push_back(it[1]);
        }
        
          for(auto it:blue_edges){
            if(blue.find(it[0])==blue.end()){blue[it[0]]=vector<int>{};}
            blue[it[0]].push_back(it[1]);
        }
        
        queue<vector<int>> q;
        vector<int> ans(n,INT_MAX);
        ans[0]=0;
        q.push(vector<int>{0,0,-1});
        
        map<pair<int,int>,bool> v;
        v[make_pair(0,-1)]=true;

        while(!q.empty()){
            
            int node=q.front()[0];
            int d=q.front()[1];
            int c=q.front()[2];

            q.pop();
            if(c==-1||c==0){
                
                 for(auto it:red[node]){
                    if(v.find(make_pair(it,1))==v.end()){
                        v[make_pair(it,1)]=true;
                        ans[it]=min(ans[it],d+1);
                        q.push(vector<int>{it,d+1,1});
                    }
                }
            }
            
            if(c==-1||c==1){
                 for(auto it:blue[node]){
                    if(v.find(make_pair(it,0))==v.end()){
                        
                       v[make_pair(it,0)]=true;ans[it]=min(ans[it],d+1);
                        q.push(vector<int>{it,d+1,0});
                    }
                }
            }
           
            
        }
        for(int i=0;i<ans.size();i++)
            if(ans[i]==INT_MAX)
                ans[i]=-1;
        
        return ans;
    }
};