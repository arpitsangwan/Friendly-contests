//https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){return false;}
        stringstream obj;
        obj<<x;
        string s=obj.str();
        if(s.length()==1){return true;}
        int i=0,j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]){return false;}
            i++;j--;
        }
        return true;
    }
};
