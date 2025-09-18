/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
    pair<int,int> MAXsum(Node*root){
        if(!root)   return {0,0};
        auto lsum=MAXsum(root->left);
        auto rsum=MAXsum(root->right);
        
        int a=root->data + lsum.second+rsum.second;
        int b=max(lsum.second,lsum.first) + max(rsum.first,rsum.second); 
        return {a,b};
    }
    int getMaxSum(Node *root) {
        // code here
        auto ans =MAXsum(root);
        return max(ans.first,ans.second);
    }
};