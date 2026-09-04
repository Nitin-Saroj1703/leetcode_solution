class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> suff(n);
        int op=nums[n-1];
        for(int i=n-1;i>=0;i--){
            op=min(op,nums[i]);
            suff[i]=op;
        }
        for(int i=0;i<n;i++){
            op=max(op,nums[i]);
            int score=abs(op-suff[i]);
            if(score<=k) return i;
        }
        return -1;
    }
};