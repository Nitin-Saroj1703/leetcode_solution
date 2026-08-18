class Solution {
public:
    bool checkValidString(string s) {
        int mn=0,mx=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                mn+=1;
                mx+=1;
            }
            else if(s[i]==')'){
                mn-=1;
                mx-=1;
            }
            else{
                mn-=1;
                mx+=1;
            }
            if(mn<0) mn=0;
            if(mx<0) return false;
        }
        return (mn==0);
    }
};