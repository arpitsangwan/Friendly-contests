//https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/
class Solution {
public:
    vector<int> numOfBurgers(int t, int c) {
        vector<int> ans; 
        if((t-2*c)%2==0 && (t-2*c)/2>=0 && c-(t-2*c)/2>=0 ){
            
                ans.push_back((t-2*c)/2);
                ans.push_back(c-(t-2*c)/2)   ; 
        }
        
        return ans;
    }
};