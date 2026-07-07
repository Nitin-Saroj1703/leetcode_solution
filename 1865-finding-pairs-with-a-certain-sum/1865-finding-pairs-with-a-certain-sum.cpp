class FindSumPairs {
public:
    vector<int>v1,v2;
    map<int,int>mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v1 = nums1;
        v2 = nums2;
    for(auto val: v2)
        mp[val]++;
    }
    void add(int index, int val) {
    if(index>=v2.size()){
        mp[val]++;
        return v2.push_back(val);
    }
    mp[v2[index]]--;
    v2[index]+=val;
    mp[v2[index]]++;
    }
    int count(int tot) {
    int cnt=0;
    for(auto val: v1){
    if(mp.find(tot-val)!=mp.end())
                    cnt+=mp[tot-val];
            }
    return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */