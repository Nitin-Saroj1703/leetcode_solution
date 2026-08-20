class Solution {
public:
    int candy(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n,1);
        //left 
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                ans[i]=ans[i-1]+1;
            }
        }
        //right
        int sum=0;
        for(int j=n-2;j>=0;j--){
            if(arr[j]>arr[j+1]){
                ans[j]=max(ans[j+1]+1,ans[j]);
            }
        }
        for(int i=0;i<n;i++){
            sum+=ans[i];
        }
        return sum;
    }
};