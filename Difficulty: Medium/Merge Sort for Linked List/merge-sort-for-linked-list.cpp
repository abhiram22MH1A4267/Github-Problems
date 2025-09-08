/*
class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* newHead(vector<int>&arr){
        Node* head = new Node(arr[0]);
        Node* temp = head;
        for(int i = 1; i < arr.size(); i++){
            temp->next = new Node(arr[i]);
            temp = temp->next;
        }
        
        return head;
    }
    Node* mergeSort(Node* head) {
        // code here
        vector<int>arr;
        while(head != NULL){
            arr.push_back(head->data);
            head = head->next;
        }
        
        sort(arr.begin(), arr.end());
        
        head = newHead(arr);
        
        return head;
    }
};