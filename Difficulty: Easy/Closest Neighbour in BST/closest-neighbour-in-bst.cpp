/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    void Trav(Node* root, int &ans, int k){
        if(!root) return;
        if(root->data <= k){
            ans = max(ans, root->data);
        }
        Trav(root->left, ans, k);
        Trav(root->right, ans, k);
    }
    int findMaxFork(Node* root, int k) {
        // code here
        int ans = -1;
        Trav(root, ans, k);
        return ans;
    }
};