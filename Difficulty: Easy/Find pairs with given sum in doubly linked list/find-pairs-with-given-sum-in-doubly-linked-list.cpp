// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        if(!head)   return {};
        Node*left=head;
        Node*right=head;
        while(right->next!=NULL)    right=right->next;
        vector<pair<int,int>> ans;
        
        while(left!=right && left->prev!=right){
            int sum=left->data+right->data;
            if(sum==target){
                ans.push_back({left->data,right->data});
                left=left->next;
                right=right->prev;
            }
            else if(sum<target) left=left->next;
            else    right=right->prev;
        }
        return ans;
    }
};