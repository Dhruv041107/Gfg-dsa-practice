class Solution {
  public:
    int solve(vector<int> &arr, int mid) {
        int pagecount = 0;
        int stu = 1;
        for (int i = 0; i < arr.size(); i++) {
            if (pagecount + arr[i] <= mid) {
                pagecount += arr[i];
            } else {
                stu++;
                pagecount = arr[i];
            }
        }
        return stu;
    }

    int findPages(vector<int> &arr, int k) {
        if (k > arr.size()) return -1;

        int left = *max_element(arr.begin(), arr.end()); 
        int right = accumulate(arr.begin(), arr.end(), 0); 

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int noofstu = solve(arr, mid);

            if (noofstu > k) { 
                left = mid + 1;
            } else {           
                right = mid - 1;
            }
        }
        return left;  
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        return findPages(arr,k);
    }
};