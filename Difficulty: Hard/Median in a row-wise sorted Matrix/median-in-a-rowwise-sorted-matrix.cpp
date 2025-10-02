class Solution {
  public:
    int upperBound(vector<int>&mat,int n,int x){
        int low=0;
        int high=n-1;
        int ans=n;
        while(low<=high){
            int mid=(low+high)/2;
            if(mat[mid]>x){
                ans=mid;
                high=mid-1;
            }
            else    low=mid+1;
        }
        return ans;
    }
    int countsmallEqual(vector<vector<int>> &mat,int n,int m ,int mid){
        int count=0;
        for(int i=0;i<n;i++){
            count+=upperBound(mat[i],m,mid);
        }
        return count;
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int low=INT_MAX;
        int high=INT_MIN;
        
        int n= mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            low=min(low,mat[i][0]);
            high=max(high,mat[i][m-1]);
        }
        int req=(n*m)/2;
        while(low<=high){
            int mid=(low+high)/2;
            int smallEqual=countsmallEqual(mat,n,m,mid);
            if(smallEqual<=req) low=mid+1;
            else    high=mid-1;
        }
        return low;
    }
};
