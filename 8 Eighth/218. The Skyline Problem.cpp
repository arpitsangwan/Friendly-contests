
//https://leetcode.com/problems/the-skyline-problem/

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
     vector<vector<int>> ans;
        
        vector<vector<int>> endp;
        int j=0;
        for(auto it:buildings){
            endp.push_back(vector<int>{buildings[j][0],0,j});
            endp.push_back(vector<int>{buildings[j][1],1,j});j++;
        }
        sort(endp.begin(),endp.end());
        
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<endp.size();i++){


            if(!endp[i][1]){
                pq.push(make_pair(buildings[endp[i][2]][2],buildings[endp[i][2]][1]));
            }
            
            while(!pq.empty()&& pq.top().second<=endp[i][0]){pq.pop();}
            
            if(pq.empty()){
                if(ans.size()==0||ans.back()[1]!=0){ans.push_back(vector<int>{endp[i][0],0});}
            }
            else{
        if(ans.size()==0||ans.back()[1]!=pq.top().first){ans.push_back(vector<int>{endp[i][0],pq.top().first});}
                if(ans.size()>1&&ans.back()[0]==ans[ans.size()-2][0]){
                    ans[ans.size()-2][1]=max(ans[ans.size()-2][1],ans.back()[1]);
                    ans.pop_back();
                }
                while(ans.size()>1&&ans.back()[1]==ans[ans.size()-2][1]){ans.pop_back();}
                
            }
            
            
        }
        return ans;
        
        
        
    }
};