/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int sum = 0;
    void trav(Node* root, int l, int r){
        if(!root) return;
        
        if(root->data >= l && root->data <= r) sum += root->data;
        trav(root->left, l, r);
        trav(root->right, l, r);
    }
    int nodeSum(Node* root, int l, int r) {
        // code here
        sum = 0;
        trav(root, l, r);
        return sum;
    }
};
