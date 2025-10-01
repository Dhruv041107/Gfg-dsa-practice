class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        
        int n1=a.size();
        int n2=b.size();
        if(n1>n2)   return kthElement(b,a,k);
        int low = max(0, k - n2);
        int high = min(k, n1);
        int left=k;
        while(low<=high){
            int mid1=(low+high)/2;
            int mid2=left-mid1;
            int r1= mid1<n1 ? a[mid1]: INT_MAX;
            int r2= mid2<n2 ? b[mid2]: INT_MAX; 
            int l1=mid1-1>=0? a[mid1-1]:INT_MIN;
            int l2=mid2-1>=0? b[mid2-1]:INT_MIN;
            if(l1<=r2 && l2<=r1){
                return max(l1,l2);
            }
            if(l1>r2)   high=mid1-1;
            else    low=mid1+1;
        }
        return -1;
    }
};