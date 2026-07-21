class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq(nums.begin(),nums.end()); // O(n);
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        while(k--){
            int el=pq.top();
            if(el==0) break;
            sum-=el;
            sum+=(-el);
            pq.pop();
            pq.push(-1*el);
        }
        return sum;
    }
};