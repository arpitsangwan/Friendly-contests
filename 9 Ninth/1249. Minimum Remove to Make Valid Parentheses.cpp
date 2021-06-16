//https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int co=0;
        string ans="";
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){co++;}
            if(s[i]==')'){co--;}
            
            if(co>=0){ans+=s[i];}
            if(co<0){co=0;}
            
            
        }
        int i=ans.size()-1;
        while(co>0){
           if(ans[i]=='('){
               co--;
               ans=ans.substr(0,i)+ans.substr(i+1);
           }
            else{i--;}
        }
        return ans;
    }
};