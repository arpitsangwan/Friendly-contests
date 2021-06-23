
//https://leetcode.com/problems/thousand-separator/
class Solution {
public:
    
    string thousandSeparator(int n) {
        string ans="";
        stringstream obj;
        obj<<n;
        string s= obj.str();
        int l=0;
        for(int i=s.length()-1;i>0;i--){
            l++;ans+=s[i];
            if(l==3){ans+='.';l=0;}

            
        }
        ans+=s[0];
        reverse(begin(ans),end(ans));
        return ans;
    }
};