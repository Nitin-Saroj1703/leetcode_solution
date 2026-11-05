class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n=arr1.size();
        int m=arr2.size();
        int result=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(abs(arr1[i] - arr2[j]) <= d && arr1[i]!= -1001){
                    arr1[i]=-1001;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(arr1[i]!=-1001) result++;
        }
        return result;
    }
};