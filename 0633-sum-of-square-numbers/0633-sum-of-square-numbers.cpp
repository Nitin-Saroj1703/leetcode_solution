class Solution {
public:
    bool isPerfectSqrt(int x){
            int root=sqrt(x);
            if(root*root==x) return true;
            else return false;
        }
    bool judgeSquareSum(int c) {
        // O(c)
        int x=0;
        int y=c;
        while(x<=y){
            if(isPerfectSqrt(x) && isPerfectSqrt(y) && x+y==c){
                return true;
            }
            else if(! isPerfectSqrt(y)){
                int y1=sqrt(y);
                y=y1*y1;
                x=c-y;
            }
            else{
                int x1=sqrt(x)+1;
                x=x1*x1;
                y=c-x;
            }
        }
        return false;
    }
};