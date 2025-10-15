/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void Inorder(Node* root, vector<int>&ans){
        if(!root) return;
        Inorder(root->left, ans);
        ans.push_back(root->data);
        Inorder(root->right, ans);
    }
    int kthSmallest(Node *root, int k) {
        // add code here.
        vector<int>ans;
        Inorder(root, ans);
        if(k > ans.size()) return -1;
        return ans[k-1];
    }
};