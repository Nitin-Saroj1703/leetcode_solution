class Solution {
public:
    int minAddToMakeValid(string s) {
       int ans=0, count = 0;
       for(auto c : s){
        if( c =='('){
           count += 1;
        }else{
            count -= 1;
        }
        if( count == -1){
            ans += 1;
            count = 0;
        }
       }
       return ans + count; 
    }
};