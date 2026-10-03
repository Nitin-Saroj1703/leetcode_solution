class Solution {
public:
    int longestValidParentheses(string s) {
        int op=0;
        int cl=0;
        int result=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') op++;
            if(s[i]==')') cl++;
            if(cl>op){
                op=0;
                cl=0;
            }
            if(cl==op){
                result=max(result,op+cl);
            }
        }
        op=0,cl=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='(') op++;
            if(s[i]==')') cl++;
            if(cl<op){
                op=0;
                cl=0;
            }
            if(cl==op){
                result=max(result,op+cl);
            }
        }
        return result;
    }
};