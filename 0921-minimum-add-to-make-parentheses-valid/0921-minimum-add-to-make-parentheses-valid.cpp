class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        st.push(s[0]);
        for(int i=1;i<s.length();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else{
                if(st.size()>0 && st.top()=='(') st.pop();
                else st.push(s[i]);
            }
        }
        return st.size();
    }
};