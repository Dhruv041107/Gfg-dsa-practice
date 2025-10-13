class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int i=0,j=0,cnt=0,maxCnt=0;
        int n=arr.size();
        while(i<n){
            if(arr[i]<=dep[j]){
                i++,cnt++;
            }
            else    j++,cnt--;
            maxCnt=max(maxCnt,cnt);
        }
        return maxCnt;
    }
};
