/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void post(vector<int>&res, Node* root){
        if(!root) return;
        post(res, root->left);
        post(res, root->right);
        res.push_back(root->data);
    }
    vector<int> postOrder(Node* root) {
        // code here
        vector<int>res;
        post(res, root);
        return res;
    }
};