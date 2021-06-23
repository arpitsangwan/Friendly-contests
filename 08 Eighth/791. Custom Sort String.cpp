// https://leetcode.com/problems/custom-sort-string/
     vector<int> ord;

class Solution {
public:
      
    static bool cmp(char &a, char &b){
        
        
        if(ord[a-'a']<ord[b-'a']){return true;}
        return false;
    }
    
    string customSortString(string order, string str) {
        
        ord.assign(26,0);
        for(int i=0;i<order.length();i++){
            ord[order[i]-'a']=i;
        }
       
        sort(str.begin(),str.end(),cmp);
        return str;
    }
};