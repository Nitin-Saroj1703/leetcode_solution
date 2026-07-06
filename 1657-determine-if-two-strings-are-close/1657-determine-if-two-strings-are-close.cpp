class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        if(n!=m) return false;
        unordered_map<char,int> mp1,mp2; 
        for(int i=0;i<n;i++){
                mp1[word1[i]]++;
                mp2[word2[i]]++;
        }
        for(auto x:mp1){
            char ch=x.first;
            if(mp2.find(ch)==mp2.end()) return false;
        }
        unordered_map<int,int> h1,h2; //helper
        for(auto x:mp1){
            int freq=x.second;
            h1[freq]++;
        }
        for(auto x:mp2){
            int freq=x.second;
            h2[freq]++;
        }
        for(auto x:h1){
            int key=x.first;
            if(h2.find(key)==h2.end()) return false;
            if(h1[key]!=h2[key]) return false;
        }
        return true;
    }
};