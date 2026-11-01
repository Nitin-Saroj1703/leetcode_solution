class Solution {
public:
    typedef long long LL;
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int mn=1e9+1;
        int move=0;
        for(int x:nums){
            mn=min(mn,x);
        }
        for(int x:nums){
            move+=(x-mn);
        }
        return move;
    }
    
};