class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> m;
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            s.insert(m[arr[i]]);
        }
        if(s.size()==m.size()) return true;
        else return false;
    }
};