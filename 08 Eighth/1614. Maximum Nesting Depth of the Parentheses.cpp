// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

class Solution {
public:
    int maxDepth(string s) {
        int mo=0,co=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){co++;}
            if(s[i]==')'){co--;}
            
            mo=max(mo,co);
        }
        return mo;
    }
};