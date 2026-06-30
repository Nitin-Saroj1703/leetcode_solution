class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int> map;
        for(int i=0;i<s.length();i++){
            map[s[i]]++;
        }
        for(int i=0;i<s.length();i++){
            char ch=t[i];
            if(map.find(ch)!=map.end()){
                map[ch]--;
                if(map[ch]==0) map.erase(ch);
            }
            else return false;
        }
        if(map.size()>0) return false;
        return true;
    }
};