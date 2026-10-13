class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for (int& x : nums)
            x = abs(x);
        // sort(nums.begin(), nums.end());
        nth_element(nums.begin(),nums.begin()+n/2,nums.end());
        long long sos = 0;
        int minus = n / 2;
        for (int i = 0; i < n; i++) {
            long long sq = 1LL * nums[i] * nums[i];
            if (i < minus)
                sos -= sq;
            else
                sos += sq;
        }
        return sos;
    }
};