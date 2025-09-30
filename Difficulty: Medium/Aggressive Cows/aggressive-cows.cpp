class Solution {
  public:
    bool solve(vector<int>&arr,int mid,int k){
        int count=1;
        int lastCow=arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]-lastCow>=mid){
                count++;
                lastCow=arr[i];
            }
        }
        return count>=k;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(),stalls.end());
        int left=1;
        int max=*max_element(stalls.begin(),stalls.end());
        int min=*min_element(stalls.begin(),stalls.end());
        int right=max-min;
        int ans=-1;
        while(left <= right ){
            int mid=left+(right-left)/2;
            
            if(solve(stalls,mid,k)){
                ans=mid;
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return ans;
    }
};