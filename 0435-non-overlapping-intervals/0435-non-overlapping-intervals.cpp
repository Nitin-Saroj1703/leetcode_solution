bool cmp(vector<int>& a,vector<int>& b){
        return a[0]<b[0];
    }
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=0;
        sort(intervals.begin(),intervals.end(),cmp);
        int lastEndTime = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<lastEndTime){
                ans++;
                lastEndTime=min(lastEndTime,intervals[i][1]);
            }
            else{
                lastEndTime=intervals[i][1];
            }
        }
        return ans;
    }
};