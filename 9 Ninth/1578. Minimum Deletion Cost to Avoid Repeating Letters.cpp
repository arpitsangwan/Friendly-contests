//https://leetcode.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int c=0;
        for(int i=0;i<s.length()-1;i++){
            int j=i;
            int tc=0,maxc=cost[i];
            while(j<s.length()&&s[j]==s[i]){
                tc+=cost[j];
                maxc=max(maxc,cost[j]);
                j++;
            }
            c+=tc-maxc;
            if(j!=i){i=j-1;}
        }
        return c;
    }
};