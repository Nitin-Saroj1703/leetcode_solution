    bool cmp(vector<int>& a,vector<int>& b){
        return a[0]<b[0];
    }
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>> res;
        int n=intervals.size();
        res.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            vector<int> curr=intervals[i];
            if(curr[0]<=res[res.size()-1][1]){
                res[res.size()-1][0]=min(res[res.size()-1][0],curr[0]);
                res[res.size()-1][1]=max(res[res.size()-1][1],curr[1]);
            } else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};