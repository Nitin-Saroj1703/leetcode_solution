class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for (int& x : nums) x = abs(x);
        sort(nums.begin(), nums.end());

        long long sos = 0;
        int minus = n / 2;               // number of positions that get subtracted
        for (int i = 0; i < n; i++) {
            long long sq = 1LL * nums[i] * nums[i];
            if (i < minus) sos -= sq;    // smallest floor(n/2) elements
            else           sos += sq;    // largest ceil(n/2) elements
        }
        return sos;
    }
};