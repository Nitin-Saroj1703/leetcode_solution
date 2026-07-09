class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp; //ele,freq
        for(int x:nums){
            mp[x]++;
        }
        // freq,ele
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        for(auto x:mp){
            // x.first=ele,x.second=freq;
            pq.push({x.second,x.first});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(pq.size()>0){
            int ele=pq.top().second;
            ans.push_back(ele);
            pq.pop();
        }
        return ans;
    }
};