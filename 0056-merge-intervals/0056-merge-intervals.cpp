    bool cmp(vector<int>& a,vector<int>& b){
        return a[1]<b[1];
    }
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>> res;
        int n=intervals.size();
        res.push_back(intervals[n-1]);
        for(int i=n-2;i>=0;i--){
            vector<int> curr=intervals[i];
            if(curr[1]>=res[res.size()-1][0]){
                res[res.size()-1][0]=min(res[res.size()-1][0],curr[0]);
                res[res.size()-1][1]=max(res[res.size()-1][1],curr[1]);
            } else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};