class Solution {
  public:
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        vector<int> result;

        for(int idx : indices){
            int count = 0;
            for(int j = idx + 1; j < arr.size(); j++){
                if(arr[j] > arr[idx])
                    count++;
            }
            result.push_back(count);
        }

        return result;
    }
};
