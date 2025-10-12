class Solution {
  public:
    int findMin(int n) {
        vector<int>arr={10,5,2,1};
        
        int ans=0;
        int i=0;
        int count=0;
        while(i<arr.size() && ans!=n){
            while(ans+arr[i]<=n){
                ans+=arr[i];
                count++;
            }
            i++;
        }
        return count;
    }
};