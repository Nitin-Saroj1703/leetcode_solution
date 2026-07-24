bool cmd(vector<int> &a, vector<int> &b){
        return a[1]>b[1];
    }
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n=boxTypes.size();
        sort(boxTypes.begin(),boxTypes.end(),cmd);
        int result=0;
        for(int i=0;i<n;i++){
            if(boxTypes[i][0]<=truckSize){
                result+=boxTypes[i][0]*boxTypes[i][1];
                truckSize-=boxTypes[i][0];
            }
            else{
                result+=truckSize*boxTypes[i][1];
                truckSize=0;
                break;
            }
        }
        return result;
    }
};