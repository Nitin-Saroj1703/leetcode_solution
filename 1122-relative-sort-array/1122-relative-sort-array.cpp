class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        int n=arr1.size();
        int m=arr2.size();
        unordered_map<int,int> mp;
        for(int x:arr1){
            mp[x]++;
        }
        for(int i=0;i<m;i++){
            int x=arr2[i];
            if(mp.find(x)!=mp.end()){
                while(mp[x]--){
                    ans.push_back(x);
                }
                mp.erase(x);
            }
        }
        vector<int> rem;
        for(auto x:mp){
            while(x.second--)
            rem.push_back(x.first);
        }
        sort(rem.begin(),rem.end());
        ans.insert(ans.end(), rem.begin(), rem.end());
        return ans;
    }
};