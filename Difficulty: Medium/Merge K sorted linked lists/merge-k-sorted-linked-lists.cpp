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
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        int n = pow(10, 4), mini = INT_MAX, maxi = INT_MIN;
        vector<int>val(n, 0);
        for(int i = 0; i < arr.size(); i++){
            Node* temp = arr[i];
            while(temp != NULL){
                mini = min(mini, temp->data);
                maxi = max(maxi, temp->data);
                val[temp->data]++;
                temp = temp->next;
            }
        }
        Node* head = new Node(0);
        Node* temp = head;
        for(int i = mini; i <= maxi; i++){
            for(int j = 0; j < val[i]; j++){
                temp->next = new Node(i);
                temp = temp->next;
            }
        }
        return head->next;
    }
};