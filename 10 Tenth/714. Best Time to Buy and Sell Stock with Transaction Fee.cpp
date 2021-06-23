class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> ans(prices.size()+1,0);
        vector<int> seld;
        seld.push_back(prices.size()-1);
        
        for(int i=prices.size()-2;i>=0;i--){
            ans[i]=ans[i+1];
            int temp=-prices[i]-fee;
            int ta=0;
            for(auto j:seld){
                ta=max(ta,temp+prices[j]+ans[j+1]);
            }
            
            ans[i]=max(ans[i],ta);
            while(seld.size() && prices[seld.back()]<=prices[i]){
                seld.pop_back();
            }
            seld.push_back(i);
        }
        return ans[0];
        
    }
};