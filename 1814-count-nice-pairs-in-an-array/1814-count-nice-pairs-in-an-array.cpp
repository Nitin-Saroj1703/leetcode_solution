class Solution {
public:
    int rev(int n){
        int x=0;
        while(n>0){
            x*=10;
            x+=(n%10);
            n/=10;
        }
        return x;
    }
    int countNicePairs(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> m;
        int pair=0;
        for(int i=0;i<n;i++){
            nums[i]-=rev(nums[i]);
        }
        for(int i=0;i<n;i++){
            if(m.find(nums[i])!=m.end()){
                pair=pair%1000000007;
                pair+=m[nums[i]];
            }
            m[nums[i]]++;
        }
        return pair%1000000007;
    }
};