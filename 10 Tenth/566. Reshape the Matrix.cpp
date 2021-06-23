
//https://leetcode.com/problems/reshape-the-matrix/
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(r*c!=mat.size()*mat[0].size()){return mat;}
        vector<vector<int>> ans(r,vector<int>(c,0));
        int i=0,j=0;
       for(auto it: mat){
           for(auto el:it){
               ans[i][j]=el;
               j++;
               if(j==c){j=0;i++;}
               if(i==r){return ans;}
           }
       }
        return ans;
    }
};