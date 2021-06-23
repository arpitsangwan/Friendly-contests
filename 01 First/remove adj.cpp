// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

class Solution {
public:
    string removeDuplicates(string s, int k) {
    string ans=s.substr(0,1);
       int dc=1;
        for(int i=1;i<s.size();i++){
            
            if(ans.size()>0 && s[i]==ans[ans.size()-1]){
                if(dc==k-1){
                    ans=ans.substr(0,ans.size()-k+1);
                    ///update dc
                    dc=1;
                   
                    int temp=ans.size()-k+2;
                    if(temp<1){temp=1;}
                    
                    while(temp>0 && temp<ans.size()){
                        if(ans[temp]==ans[temp-1]){
                            dc++;
                            temp++;
                        }
                        else{dc=1;temp++;}
                    }
                
                   
                
                }
                else{
                dc++;
                ans+=s[i];}
            }
            else{ans+=s[i];
            dc=1;}
        }
        
     return ans;   
    }
};