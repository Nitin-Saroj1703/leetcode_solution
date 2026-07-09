class Solution {
public:
    typedef pair<int,vector<int>> pi;
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
        priority_queue<pi> pq;
        for(auto x:arr){
            int dist=x[0]*x[0]+x[1]*x[1];
            pq.push({dist,x});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>> ans;
        while(pq.size()>0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};