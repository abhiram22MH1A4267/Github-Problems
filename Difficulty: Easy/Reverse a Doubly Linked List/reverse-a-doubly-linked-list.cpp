/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node *temp = head, *prevTemp = NULL, *nextTemp = head->next;
        
        while(temp != NULL){
            temp->next = prevTemp;
            temp->prev = nextTemp;
            
            prevTemp = temp;
            
            temp = nextTemp;
            
            if(nextTemp != NULL) nextTemp = nextTemp->next;
            
        }
        
        return prevTemp;
    }
};