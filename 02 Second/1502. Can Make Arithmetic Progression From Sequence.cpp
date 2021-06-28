//https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        if(arr.size()<2){return true;}
        int dif=arr[1]-arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]-arr[i-1]!=dif){return false;}
        }
        return true;
        
    }
};