class Solution {
  public:
    static bool myCmp(vector<int>&a,vector<int>&b){
        return a[2]<b[2];
    }
    int findParent(vector<int>&parent,int node){
        if(parent[node]==node)  return node;
        return parent[node]=findParent(parent,parent[node]);
    }
    
    void unionSet(int u,int v,vector<int>&parent,vector<int>&rank){
        // u=findParent(parent,u);
        // v=findParent(parent,v);
        
        if(rank[u]<rank[v]){
            parent[u]=v;
            rank[v]++;
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
        
    }
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>parent(V);
        vector<int>rank(V,0);
        
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        
        sort(edges.begin(),edges.end(),myCmp);
        int ans=0;
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            
            u=findParent(parent,u);
            v=findParent(parent,v);
            
            if(u!=v){
                unionSet(u,v,parent,rank);
                ans+=wt;
            }
        }
        return ans;
    }
};