bool cmp(vector<int>& a,vector<int>& b){
    return a[1]<b[1];
}
bool cmp1(vector<int>& a,vector<int>& b){
    return a[0]<b[0];
}
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(),logs.end(),cmp);
        vector<vector<int>> q;
        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end(),cmp1);
        unordered_map<int,int> mp;
        int k=0;
        int j=0;
        vector<int> result(queries.size());
        for(int i=0;i<queries.size();i++){
            int s=q[i][0]-x;
            int e=q[i][0];
            while(j<logs.size() && logs[j][1]<=e){
                mp[logs[j][0]]++;
                j++;
            }
            while(k<logs.size() && logs[k][1]<s){
                mp[logs[k][0]]--;
                if(mp[logs[k][0]]==0){
                    mp.erase(logs[k][0]);
                }
                k++;
            }
            result[q[i][1]]=n-mp.size();
        }
        return result;
    }
};