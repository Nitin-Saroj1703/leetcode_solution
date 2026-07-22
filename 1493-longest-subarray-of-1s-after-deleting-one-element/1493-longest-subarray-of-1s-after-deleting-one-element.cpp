class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        int flips=0;
        int len=0;
        int maxlen=0;
        while(j<n){
            if(nums[j]==1) j++;
            else{
                if(flips<1){
                    flips++;
                    j++;
                }
                else{
                    len=j-i;
                    maxlen=max(maxlen,len);
                    while(nums[i]==1) i++;
                    i++;
                    j++;
                }
            }
        }
        len=j-i;
        maxlen=max(maxlen,len);
        return maxlen-1;
    }
};