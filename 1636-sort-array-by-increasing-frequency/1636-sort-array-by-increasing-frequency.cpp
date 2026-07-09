class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp; //ele,freq
        for(int x:nums){
            mp[x]++;
        }
        // freq,ele
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        for(auto x:mp){
            // x.first=ele,x.second=freq;
            pq.push({x.second,-x.first});
        }
        vector<int> ans;
        while(pq.size()>0){
            int freq=pq.top().first;
            int ele=-pq.top().second;
            while(freq--){
                ans.push_back(ele);
            }
            pq.pop();
        }
        return ans;
    }
};