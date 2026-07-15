class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        long long mn = 0;                     
        int nsi[n];
        int psi[n];
        psi[0]=-1;
        st.push(0);
        for(int i=1;i<n;i++){
            while(st.size()>0 && nums[st.top()]>=nums[i]) st.pop();
            if(st.size()==0) psi[i]=-1;
            else psi[i]=st.top();
            st.push(i);
        }
        while(st.size()>0) st.pop();
        nsi[n-1]=n;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(st.size()>0 && nums[st.top()]>nums[i]) st.pop();
            if(st.size()==0) nsi[i]=n;
            else nsi[i]=st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++){
            mn=(mn +(long long)nums[i]*(nsi[i]-i)*(i-psi[i]));
        }
        while(st.size()>0) st.pop();
        long long mx = 0;                     
        int ngi[n];
        int pgi[n];
        pgi[0]=-1;
        st.push(0);
        for(int i=1;i<n;i++){
            while(st.size()>0 && nums[st.top()]<=nums[i]) st.pop();
            if(st.size()==0) pgi[i]=-1;
            else pgi[i]=st.top();
            st.push(i);
        }
        while(st.size()>0) st.pop();
        ngi[n-1]=n;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(st.size()>0 && nums[st.top()]<nums[i]) st.pop();
            if(st.size()==0) ngi[i]=n;
            else ngi[i]=st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++){
            mx=(mx +(long long)nums[i]*(ngi[i]-i)*(i-pgi[i]));
        }
        return mx-mn;
    }
};