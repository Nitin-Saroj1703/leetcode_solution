class Solution {
public:
    // left = max-heap, holds the smaller half (can have at most 1 more element than right)
    // right = min-heap, holds the larger half
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    unordered_map<int,int> mp; // value -> count of pending lazy deletions
    int x = 0, y = 0; // sizes

    double get_median(){
        if((x+y) % 2 == 1){
            return left.top();      // left always holds the extra element when odd
        }
        return (left.top() + (double)right.top()) / 2.0;
    }

    // returns true if sizes need fixing
    bool isBalance(){
        return (x == y) || (x == y+1);
    }

    void rebalance(){
        if(x > y+1){
            int val = left.top(); left.pop();
            right.push(val);
            x--; y++;
        } else if(y > x){
            int val = right.top(); right.pop();
            left.push(val);
            y--; x++;
        }
    }

    // remove any lazily-deleted values sitting on top of either heap
    void prune(){
        while(!left.empty() && mp.count(left.top()) && mp[left.top()] > 0){
            int v = left.top(); left.pop();
            if(--mp[v] == 0) mp.erase(v);
        }
        while(!right.empty() && mp.count(right.top()) && mp[right.top()] > 0){
            int v = right.top(); right.pop();
            if(--mp[v] == 0) mp.erase(v);
        }
    }

    void addNum(int curr){
        if(left.empty() || curr <= left.top()){
            left.push(curr); x++;
        } else {
            right.push(curr); y++;
        }
        rebalance();
        prune(); // in case rebalance exposed a stale top
    }

    void removeNum(int val){
        mp[val]++;
        // figure out which side it logically belongs to, to keep x/y correct
        if(!left.empty() && val <= left.top()){
            x--;
        } else {
            y--;
        }
        prune();
        rebalance();
        prune();
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            addNum(nums[i]);
            if(i >= k) removeNum(nums[i-k]);
            if(i >= k-1) result.push_back(get_median());
        }
        return result;
    }
};