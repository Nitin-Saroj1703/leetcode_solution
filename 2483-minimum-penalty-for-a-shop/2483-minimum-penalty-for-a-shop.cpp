class Solution {
public:
    int bestClosingTime(string customers) {
        // YYNY
        int n=customers.length();
        vector<int> pre(n+1); // no of n before k th hour
        vector<int> suff(n+1); // no of y after k th and including the k th hour
        // prefix arr 
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+((customers[i]=='N')? 1:0);
        }
        for(int i=n-1;i>=0;i--){
            suff[i]=suff[i+1] +((customers[i]=='Y')? 1:0);
        }
        int mnPen=n;
        for(int i=0;i<=n;i++){
            pre[i]+=suff[i];
            mnPen=min(pre[i],mnPen);
        }
        for(int i=0;i<=n;i++){
            int pen=pre[i];
            if(pen==mnPen) return i;
        }
        return n;
    }
};