// User function template for C++

class Solution {
  public:
    vector<int> factorial(int n) {
        vector<int>ans;
        ans.push_back(1);
        long long carry=0;
        for(long long i=2;i<=n;i++){
            for(long long j=0;j<ans.size();j++){
                long long x=ans[j]*i+carry;
                ans[j]=x%10;
                carry=x/10;
            }        
            while (carry) {
            ans.push_back(carry % 10);
            carry /= 10;
            }
            carry=0;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};