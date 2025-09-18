/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
        Node*makeNodetoParentmappingandfindtargetNode(Node*root,
        unordered_map<Node*,Node*>&parentMap,int target){
            Node*targetNode=0;
            queue<Node*>q;
            q.push(root);
            parentMap[root]=0;
            while(!q.empty()){
                auto front=q.front();q.pop();
                if(front->data==target){
                    targetNode=front;
                }
                if(front->left){
                    q.push(front->left);
                    parentMap[front->left]=front;
                }
                if(front->right){
                    q.push(front->right);
                    parentMap[front->right]=front;
                }
            }
            return targetNode;
        }
        int BurningTree(Node*targetNode,unordered_map<Node*,Node*>&parentMap){
            int T=0;
            unordered_map<Node*,bool>isBurnt;
            queue<Node*>q;
            isBurnt[targetNode]=1;
            q.push(targetNode);
            bool isBurning=1;
            while(!q.empty()){
                int size=q.size();
                isBurning=0;
                for(int i=0;i<size;i++){
                    auto front=q.front();q.pop();
                    
                    if(front->left && !isBurnt[front->left]){
                        isBurnt[front->left]=1;
                        q.push(front->left);
                        isBurning=1;
                    }
                    if(front->right && !isBurnt[front->right]){
                        isBurnt[front->right]=1;
                        q.push(front->right);
                        isBurning=1;
                    }
                    if(parentMap[front] && !isBurnt[parentMap[front]]){
                        isBurnt[parentMap[front]]=1;
                        q.push(parentMap[front]);
                        isBurning=1;
                    }
                }
                if(isBurning)   T++;
            }
            return T;
        }
        int minTime(Node* root, int target) {
            unordered_map<Node*,Node*>parentMap;
            Node*targetNode=makeNodetoParentmappingandfindtargetNode(root,parentMap,target);
            
            return BurningTree(targetNode,parentMap);
            
        }
};