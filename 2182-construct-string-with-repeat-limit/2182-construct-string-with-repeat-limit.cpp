class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        priority_queue<pair<char,int>> pq;
        for(auto x: mp){
            pq.push(x);
        }
        string result="";
        while(!pq.empty()){
            auto largest=pq.top();
            pq.pop();
            int len =min(repeatLimit,largest.second);
            for(int i=0;i<len;i++){
                result+=largest.first;
            }
            pair<char,int> second_largest;
            if(largest.second-len>0){
                if(!pq.empty()){
                    second_largest=pq.top();
                    pq.pop();
                    result += second_largest.first;
                }
                else{
                    return result;
                }
                if(second_largest.second-1>0) pq.push({second_largest.first,second_largest.second-1});
                pq.push({largest.first,largest.second-len});
            }
        }
        return result;
    }
};