// User function Template for C++

class Solution {
  public:
    void sieve() {}

    vector<int> findPrimeFactors(int N) {
        vector<int> spj(N + 1);

        // Build smallest prime factor (SPF) array
        for (int i = 0; i <= N; i++)
            spj[i] = i;
        
        for (int i = 2; i * i <= N; i++) {
            if (spj[i] == i) {
                for (int j = i * i; j <= N; j += i) {
                    if (spj[j] == j)
                        spj[j] = i;
                }
            }
        }

        // Factorize using SPF array
        vector<int> ans;
        while (N != 1) {
            ans.push_back(spj[N]);
            N /= spj[N];
        }

        return ans;
        
    }
};