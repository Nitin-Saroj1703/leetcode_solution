class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> m;
        int pre=nums[0];
        for(int i=1;i<n;i++){
            nums[i]+=pre;
            pre=nums[i];
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==k){
                count++;
            }
            if(m.find(nums[i]-k)!=m.end()) count+=m[nums[i]-k];
            m[nums[i]]++;
        }
        return count;
    }
};