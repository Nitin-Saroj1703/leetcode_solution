class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
        if(n<=8) return n;
        else if(n>8 && n<=16) return (n-8)*2+8;
        else if(n>16 && n<=24) return (n-8*2)*3+8+8*2;
        else return (n-8*3)*4+8+8*2+8*3;
    }
};