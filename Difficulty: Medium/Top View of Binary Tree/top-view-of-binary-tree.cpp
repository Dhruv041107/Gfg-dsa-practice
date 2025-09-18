/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        queue<pair<Node*,int>>q;
        q.push({root,0});
        unordered_map<int,Node*>mp;
        int mindist=INT_MAX;
        int maxdist=INT_MIN;
        
        while(!q.empty()){
            auto front=q.front();q.pop();
            
            Node*frontNode=front.first;
            int hd=front.second;
            
            mindist=min(mindist,hd);
            maxdist=max(maxdist,hd);
            
            if(mp.find(hd)==mp.end()){
                mp[hd]=frontNode;
            }
            
            if(frontNode->left){
                q.push({frontNode->left,hd-1});
            }
            if(frontNode->right){
                q.push({frontNode->right,hd+1});
            }
        }
        vector<int>ans;
        for(int i=mindist;i<=maxdist;i++){
            Node* temp=mp[i];
            ans.push_back(temp->data);
        }
        return ans;
    }
};