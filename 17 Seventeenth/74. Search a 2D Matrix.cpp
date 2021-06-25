//https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    
    int findrow(vector<vector<int>>& matrix,int target,int low,int high){

        if(low==high){
             if(matrix[low][0]<=target && target<=matrix[low].back()){
                    return low;
                }
            return -1;
        }
        if(low>high){return -1;}
        
        int mid=(low+high)/2;
        
        if(matrix[mid][0]<=target&&target<=matrix[mid].back()){
            return mid;
        }
        if(matrix[mid][0]>target){return findrow(matrix,target,low,mid-1);}
        return findrow(matrix,target,mid+1,high);

        
    }
    bool bs(vector<int>& mat,int t, int l,int h){
        if(l==h){
            if(mat[l]==t){return true;}
            return false;
        }
        if(l>h){return false;}
        int m=(l+h)/2;
        
        if(mat[m]==t){return true;}
        if(mat[m]>t){return bs(mat,t,l,m-1);}
        return bs(mat,t,m+1,h);
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=findrow(matrix,target,0,matrix.size()-1);   
        if(row==-1){return false;}
        
        return bs(matrix[row],target,0,matrix[row].size()-1);
    }
};