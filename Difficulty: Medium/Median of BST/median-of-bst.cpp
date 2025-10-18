/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int>arr;
    void trav(Node* root){
        if(!root) return;
        
        trav(root->left);
        arr.push_back(root->data);
        trav(root->right);
    }
    int findMedian(Node* root) {
        // Code here
        arr = {};
        trav(root);
        int n = arr.size();
        
        if((n&1) == 1) n+=1;
        
        return arr[(n/2)-1];
    }
};