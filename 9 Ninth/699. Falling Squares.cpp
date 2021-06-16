//https://leetcode.com/problems/falling-squares/
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& pos) {
        
        vector<vector<int>> inte;
        vector<int> ans;
        int maxh=0;
        for(int i=0;i<pos.size();i++){
            int mh=0;
            for(auto it:inte){
            if((it[0]<=pos[i][0]&&pos[i][0]<it[1]) ||(it[0]<pos[i][0]+pos[i][1]&&pos[i][0]+pos[i][1]<=it[1])
    ||(pos[i][0]<=it[0]&&it[0]<pos[i][0]+pos[i][1])||(pos[i][0]+pos[i][1]<=it[1]&&pos[i][0]>it[1])
              ){
                    mh=max(mh,it[2]);
                }
            }
            maxh=max(maxh,pos[i][1]+mh);
            ans.push_back(maxh);
            inte.push_back(vector<int>{pos[i][0],pos[i][0]+pos[i][1],pos[i][1]+mh});
        }
       
        return ans;
        
    }
};