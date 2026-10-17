class Solution {
public:
    static int digitsum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> v = nums;

        auto cmp = [](int a, int b) {
            int da = digitsum(a), db = digitsum(b);
            if (da != db) return da < db;
            return a < b;
        }; 
        sort(v.begin(),v.end(),cmp);
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        int swapcount=0;
        for(int i=0;i<n;i++){
            int expectedVal=v[i];
            int currVal=nums[i];
            if(expectedVal!=currVal){
                int idx=mp[expectedVal];
                nums[i]=expectedVal;
                nums[idx]=currVal;
                mp[expectedVal]=i;
                mp[currVal]=idx;
                swapcount++;
            }
        }
        return swapcount;
    }
};