class Solution {
  public:
    void solve(int i,int j,vector<vector<int>>&m,int n,vector<string>&ans,
    string curr,vector<vector<bool>>&vis){
        if(i==n-1 && j==n-1){
            ans.push_back(curr);
            return;
        }
        //downwards
        if(i+1<n && !vis[i+1][j] && m[i+1][j]==1){
            vis[i+1][j]=true;
            solve(i+1,j,m,n,ans,curr+'D',vis);
            vis[i+1][j]=false;
        }
        // leftward
        if(j-1>=0 && !vis[i][j-1] && m[i][j-1]==1){
            vis[i][j-1]=true;
            solve(i,j-1,m,n,ans,curr+'L',vis);
            vis[i][j-1]=false;
        }
        //rightwards
        if(j+1<n && !vis[i][j+1] && m[i][j+1]==1){
            vis[i][j+1]=true;
            solve(i,j+1,m,n,ans,curr+'R',vis);
            vis[i][j+1]=false;
        }
        // upwards
        if(i-1>=0 && !vis[i-1][j] && m[i-1][j]==1){
            vis[i-1][j]=true;
            solve(i-1,j,m,n,ans,curr+'U',vis);
            vis[i-1][j]=false;
        }
        
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string>ans;
        int n=maze.size();
        vector<vector<bool>>vis(n,vector<bool>(n,0));
        if(maze[0][0] != 1 || maze[n-1][n-1] != 1) return ans;
        vis[0][0] = true;
        solve(0, 0, maze, n, ans, "", vis);
        return ans;

    }
};