
//https://leetcode.com/problems/student-attendance-record-i/

class Solution {
public:
    bool checkRecord(string s) {
        int a=0,lc=0;
        for(auto ch:s){
            if(ch=='A'){a++;}
            if(ch=='L'){
                lc++;
                if(lc==3){return false;}
            }
            else{lc=0;}
            if(a==2){return false;}
        }
        return true;
    }
};