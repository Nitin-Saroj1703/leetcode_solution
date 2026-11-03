class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx=INT_MIN;
        for(auto x:nums){
            mx=max(mx,x);
        }
        int moves=0;
        for(auto x:nums){
            moves+=(mx-x);
        }
        return moves;
    }
};