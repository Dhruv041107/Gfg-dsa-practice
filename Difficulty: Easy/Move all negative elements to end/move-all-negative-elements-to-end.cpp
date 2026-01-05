class Solution {
  public:
    void segregateElements(vector<int>& arr) {
        vector<int>temp;
        
        for(auto i:arr){
            if(i>=0)    temp.push_back(i);
        }
        for(auto i:arr){
            if(i<0)    temp.push_back(i);
        }
        arr=temp;
    }
};