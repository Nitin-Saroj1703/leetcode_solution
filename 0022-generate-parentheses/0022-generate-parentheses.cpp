class Solution {
public:
    void sol(int op,int cp,string str,vector<string>& v){
        if(op ==0  && cp ==0) {
            v.push_back(str);
            return;
        }
        if(op>0){
            sol(op-1,cp,str+'(',v);
        }
        if(cp>op){
            sol(op,cp-1,str+')',v);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        sol(n,n,"",v);
        return  v;
    }
};