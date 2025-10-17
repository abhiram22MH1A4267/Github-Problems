/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
    int sum = 0;
    vector<int>arr;
    
    void travel(Node* root){
        if(!root) return;
        
        travel(root->left);
        sum += root->data;
        arr[root->data] = sum;
        travel(root->right);
        
    }
    void transform(Node* root){
        if(!root) return;
        root->data = sum - arr[root->data];
        transform(root->left);
        transform(root->right);
    }
    void transformTree(Node *root) {
        // code here
        sum = 0;
        int n = 30000;
        arr.resize(n, 0);
        
        travel(root);
        
        transform(root);
    }
};