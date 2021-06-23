//https://leetcode.com/problems/car-pooling/
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        int time[1001];
        for(int i=0;i<1001;i++){
            time[i]=0;
        }
        int cp=0;
        for(int i=0;i<trips.size();i++){
            time[trips[i][1]]+=trips[i][0];
            time[trips[i][2]]-=trips[i][0];
        }
        for(int i=0;i<1001;i++){
            cp+=time[i];
            if(cp>capacity){return false;}
        }
        return true;
        
    }
};