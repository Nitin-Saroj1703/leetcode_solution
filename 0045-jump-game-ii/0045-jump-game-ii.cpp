class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int mx_jump = 0;      // farthest index reachable
        int mn_jump = 0;      // start of current level
        int count = 0;
        
        while(mx_jump < n - 1){
            int far = 0;
            for(int i = mn_jump; i <= mx_jump; i++){  // ✅ Use <=
                far = max(far, i + nums[i]);
            }
            mn_jump = mx_jump + 1;
            mx_jump = far;
            count++;
        }
        return count;
    }
};