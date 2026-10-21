class Solution {
public:
    int minOperations(string s) {
        int n=s.length();
        if(is_sorted(s.begin(),s.end())) return 0;
        char mn,mx;
        mn=*min_element(s.begin(),s.end());
        mx=*max_element(s.begin(),s.end());
        if(n==2) return -1;
        if(mn==s[0] || mx==s[n-1]) return 1;
        for(int i=1;i<n-1;i++){
            if(s[i]==mx || s[i]==mn){
                return 2;
            }
        }
        return 3;
    }
};