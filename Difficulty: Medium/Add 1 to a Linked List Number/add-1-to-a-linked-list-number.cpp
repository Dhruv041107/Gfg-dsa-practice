/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverseList(Node*&head){
        Node*prev=NULL;
        Node*curr=head;
        
        while(curr!=NULL){
            Node*forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev; 
    }
    
    Node* addOne(Node* head) {
        // Your Code here
        head=reverseList(head);
        
        Node*temp=head;
        int carry=1;
        
        while(temp!=NULL){
            int sum=carry+temp->data;
            
            int digit=sum%10;
            carry=sum/10;
            
            temp->data=digit;
            if(temp->next==NULL && carry!=0){
                Node*newNode=new Node(carry);
                temp->next=newNode;
                temp=newNode;
            }
            
            
            
            temp=temp->next;
            
        }
        
        
        
        
        
        
        
        head=reverseList(head);
        return head;
    }
};