
//https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int t1=0,t2=0;
        int count=0;
        if(s1.length()==0){return true;}
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i] ){
                if(count==0){t1=i;count++;t2=i;}
                else{t2=i;count++;}     
            }
            
        }
        if(count>2){return false;}
        if(s1[t1]==s2[t2] && s1[t2]==s2[t1]){return true;}
        
        return false;
    }
};