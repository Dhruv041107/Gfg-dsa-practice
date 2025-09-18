/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    void insertAtTail(Node*temp,Node*&head,Node*&tail){
        if(head==NULL && tail== NULL){
            head=temp;
            tail=temp;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }
    Node* segregate(Node* head) {
        Node* oneHead=NULL;
        Node* onetail=NULL;
        Node* twoHead=NULL;
        Node* twotail=NULL;
        Node* zeroHead=NULL;
        Node* zerotail=NULL;
        
        Node*temp=head;
        
        while(temp!=NULL){
            Node*moveNode=temp;
            temp=temp->next;
            
            moveNode->next=NULL;
            
            if(moveNode->data==0){
                insertAtTail(moveNode,zeroHead,zerotail);
            }
            else if(moveNode->data==1){
                insertAtTail(moveNode,oneHead,onetail);
            }
            else{
                insertAtTail(moveNode,twoHead,twotail);
            }
        }
        
        if(zeroHead!=NULL){
            if(oneHead!=NULL){
                zerotail->next=oneHead;
                
                onetail->next=twoHead;
            }else
            {
                zerotail->next=twoHead;
                
            }
            return zeroHead;
        }
        else
        {
            if(oneHead!=NULL){
                onetail->next=twoHead;
                return oneHead;
            }
            else
            {
                return twoHead;
            }
        }
        
        
        
        
    }
};