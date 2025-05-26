/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        Node* temp = head;
        if(head->data > data){
            Node* temp1 = new Node(data);
            temp1->next = temp;
            while(temp->next != head){
                temp = temp->next;
            }
            temp->next = temp1;
            return temp1;
        }
        while(temp->next != head){
            if((temp->next->data >= data) && (temp->data <= data)){
                Node* temp1 = temp->next;
                temp->next = new Node(data);
                temp = temp->next;
                temp->next = temp1;
                return head;
            }
            temp = temp->next;
        }
        temp->next = new Node(data);
        temp = temp->next;
        temp->next = head;
        return head;
    }
};