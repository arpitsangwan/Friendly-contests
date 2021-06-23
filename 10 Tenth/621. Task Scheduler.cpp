//https://leetcode.com/problems/task-scheduler/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
     unordered_map<char,int> umap;

        for(auto it:tasks){
            if(umap.find(it)==umap.end()){umap[it]=0;}
            umap[it]++;
        }
        
        vector<int> freq;
        
        for(auto it:umap){
            freq.push_back(it.second);
        }
        sort(begin(freq),end(freq));
        int ans=0,batches=0;
        for(int i=0;i<freq.size()-1;i++){
            if(freq[i]==0){continue;}
            batches++;
            int temp=freq[i];freq[i]=0;ans+=temp;
            for(int j=i+i;j<freq.size();j++){
                freq[j]-=temp;ans+=temp;
            }
        }
        int left=freq.back();
        if(left==0){return ans;}
        
        if(umap.size()>=3){
            left-=(umap.size()-2)*batches;
            if(left<=0){ans+=freq.back();return ans;}
            else{
                ans+=(umap.size()-2)*batches;
            }
        }
        ans+=left*n;
        return ans;
    }
};