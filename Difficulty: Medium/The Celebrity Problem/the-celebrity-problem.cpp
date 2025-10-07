class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int up=0;
        int down=mat.size()-1;
        while(up<down){
            if(mat[up][down]==1)    up++;
            else down--;
        }
        for(int i=0;i<mat.size();i++){
            if(i==up)  continue;
            if(mat[up][i]==1 || mat[i][up]==0)  return -1;
        }
        return up;
    }
};