//https://leetcode.com/problems/filling-bookcase-shelves/
class Solution {
public:
    int**dp;
    int minheight(vector<vector<int>>& books, int width,int i,int remwidth,int ch){
        if(i==books.size()){
            return ch;
        }
        if(dp[i][remwidth]!=-1){return dp[i][remwidth];}
        if(books[i][0]<=remwidth){
            if(remwidth==width){
                ch=books[i][1];
                dp[i][remwidth]= minheight(books,width,i+1,remwidth-books[i][0],ch);
                return dp[i][remwidth];
            }
            int temp=max(ch,books[i][1]);
 dp[i][remwidth]= min(minheight(books,width,i+1,remwidth-books[i][0],temp),ch+minheight(books,width,i+1,width-books[i][0],books[i][1]));
            return dp[i][remwidth];
        }
        
        dp[i][remwidth]= ch+minheight(books,width,i+1,width-books[i][0],books[i][1]);
        return dp[i][remwidth];
        
    }
    
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        
        dp=new int*[books.size()];
        for(int i=0;i<books.size();i++){
            dp[i]=new int[shelf_width+1];
            for(int j=0;j<=shelf_width;j++){
                dp[i][j]=-1;
            }
        }
        return minheight(books,shelf_width,0,shelf_width,0);
    }
};