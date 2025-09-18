class Solution {
  public:
    int solve(vector<int> &val, vector<int> &wt,int capacity,int index){
        //Base case
        
        if(index==val.size()-1){
            if(wt[index]<=capacity){
                return val[index];
            }
            else{
                return 0;
            }
        }
        // if(index==0){
        //     if(wt[index]<=capacity){
        //         return val[index];
        //     }
        //     else{
        //         return 0;
        //     }
        // }
        //inc /exc
        int inc=0;
        if(wt[index]<=capacity){
            inc=val[index]+solve(val,wt,capacity-wt[index],index+1);
        }
        int exc=0+solve(val,wt,capacity,index+1);
        int finalans=max(inc,exc);
        
        return finalans;
    }
    
    int solveusingMEM(vector<int> &val, vector<int> &wt,int capacity,int index,vector<vector<int>>&dp){
        //Base case
        
        if(index==0){
            if(wt[index]<=capacity){
                return val[index];
            }
            else{
                return 0;
            }
        }
        if(dp[capacity][index]!=-1){
            return dp[capacity][index];
        }

        //inc /exc
        int inc=0;
        if(wt[index]<=capacity){
            inc=val[index]+solveusingMEM(val,wt,capacity-wt[index],index-1,dp);
        }
        int exc=0+solveusingMEM(val,wt,capacity,index-1,dp);
        dp[capacity][index]=max(inc,exc);
        
        return dp[capacity][index];
    }
    
    int solveusingBottomUp(vector<int> &val, vector<int> &wt,int capacity){
        int n=val.size();
        vector<vector<int>>dp(capacity+1,vector<int>(n+1,-1));
        
        
    }
    
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int capacity=W;
        int n=val.size();
        // int index=0;
        int index=n-1;
        vector<vector<int>>dp(capacity+1,vector<int>(n,-1));
        return solveusingMEM(val,wt,capacity,index,dp);
        
    }
};