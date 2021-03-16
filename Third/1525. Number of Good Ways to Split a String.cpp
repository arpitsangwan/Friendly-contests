//https://leetcode.com/problems/number-of-good-ways-to-split-a-string/
class Solution {
public:
    int numSplits(string s) {
        if(s.length()==1){return 0;}
        unordered_map<char,int> left;
        unordered_map<char,int> right;

        int distl=0,distr=0;
        int ans=0;
        
        for(int i=0;i<s.length();i++){
            if(right[s[i]]){right[s[i]]++;}
            else{
                right[s[i]]=1;
                distr++;
            }
        }
        
        for(int i=0;i<s.length();i++){
            if(left[s[i]]){
                left[s[i]]++;
                right[s[i]]--;
                if(right[s[i]]==0){distr--;}
                if(distr==distl){ans++;}
            }
            else{
                left[s[i]]=1;
                distl++;
                right[s[i]]--;
                if(right[s[i]]==0){distr--;}
                if(distr==distl){ans++;}
            }
            
            
        }
        return ans;
    
    
    }
};