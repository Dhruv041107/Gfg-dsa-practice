/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
public:
    Node* merge(Node* list1, Node* list2){
        Node dummy(-1);
        Node* res = &dummy;

        while(list1 && list2){
            if(list1->data < list2->data){
                res->bottom = list1;
                res = list1;
                list1 = list1->bottom;
            } else {
                res->bottom = list2;
                res = list2;
                list2 = list2->bottom;
            }
            res->next = nullptr;
        }

        if(list1) res->bottom = list1;
        if(list2) res->bottom = list2;

        return dummy.bottom;
    }

    Node *flatten(Node *root) {
        if(!root || !root->next) return root;

        Node* mergedNode = flatten(root->next);
        return merge(root, mergedNode);
    }
};
