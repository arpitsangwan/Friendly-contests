// https://leetcode.com/problems/transform-to-chessboard/

TLE:::::::ADHOC Solution
class Solution {
public:
    
    vector<vector<vector<int>>> getadj(vector<vector<int>> &a){
        vector<vector<vector<int>>> ans;
        for(int i=0;i<a.size()-1;i++){
            for(int j=i+1;j<a.size();j++){
                
                for(int k=0;k<a[0].size();k++){
                    int temp=a[i][k];
                    a[i][k]=a[j][k];
                    a[j][k]=temp;
                }
                ans.push_back(a);
                for(int k=0;k<a[0].size();k++){
                    int temp=a[i][k];
                    a[i][k]=a[j][k];
                    a[j][k]=temp;
                }
            }
        }
        
        
        for(int i=0;i<a[0].size()-1;i++){
            for(int j=i+1;j<a[0].size();j++){
                
                for(int k=0;k<a.size();k++){
                    int temp=a[k][i];
                    a[k][i]=a[k][j];
                    a[k][j]=temp;
                }
                ans.push_back(a);
                for(int k=0;k<a.size();k++){
                    int temp=a[k][i];
                    a[k][i]=a[k][j];
                    a[k][j]=temp;
                }
            }
        }
        return ans;
    }
    
    
    int movesToChessboard(vector<vector<int>>& board) {
        
        
       queue<pair<vector<vector<int>>,int> > q;
        q.push(make_pair(board,0));
        vector<vector<int>> ans1(board),ans2(board);
        for(int i=0;i<board.size();i++){
            int t;
            if(i%2){t=0;}else{t=1;}
            for(int j=0;j<board[0].size();j++){
                if(j&1){ans1[i][j]=t^0;}
                else{ans1[i][j]=t^1;}
            }
        }
        
        
         for(int i=0;i<board.size();i++){
            int t;
            if(i%2){t=1;}else{t=0;}
            for(int j=0;j<board[0].size();j++){
                if((j&1)){ans2[i][j]=(t^0);}
                else{ans2[i][j]=(t^1);}
            }
        }
      map<vector<vector<int>>,bool> v;
        while(!q.empty()){
            if(q.front().first==ans1||q.front().first==ans2){return q.front().second;}
            
            vector<vector<vector<int>>> adj=getadj(q.front().first);
            for(auto it:adj){
                if(v.find(it)==v.end()){
                    v[it]=true;
                    q.push(make_pair(it,q.front().second+1));
                }
            }
            q.pop();
        }
        return -1;
        
    }
};