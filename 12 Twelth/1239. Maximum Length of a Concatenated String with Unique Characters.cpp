//https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

class Solution {
public:
    
    int maxlength(vector<string> &ar,int i,vector<int> av){
        if(i==ar.size()){return 0;}

        int nt=maxlength(ar,i+1,av);
        
        for(auto ch:ar[i]){
            if(!av[ch-'a']){return nt;}
            av[ch-'a']=0;
        }
        int taken=ar[i].length()+maxlength(ar,i+1,av);
        return max(taken,nt);
        
    }
    
    int maxLength(vector<string>& arr) {
            vector<int> av(26,1);
        return maxlength(arr,0,av);
    }
};
