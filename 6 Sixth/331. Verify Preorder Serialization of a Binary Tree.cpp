//https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
class Solution {
public:
    
    bool check(string s){
      
        if(s.length()==1){if(s[0]=='#'){return true;}return false;}
        if(s[0]=='#'){return false;}
              int hall=2;
                int nall=2;
       
        for(int i=2;i<s.length();){
            
          if(s[i]=='#'){hall--;nall--;}
            else{hall+=1;nall++;}
            while(i<s.length() && s[i]!=','){i++;}
            i++;
            if(hall<0||nall<0){return false;}
            if(hall==0||nall==0){if(i<s.length()){return false;}return true;}
            
            
      }
        
        if(hall==0&& nall==0){
        return true;}
        return false;
        
    }
    
    bool isValidSerialization(string preorder) {
         
        return check(preorder);
    }
};