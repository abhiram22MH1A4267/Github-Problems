/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int solve(Node* root, int &ans){
        if(!root) return 0;
        int leftSum = solve(root->left, ans);
        int rightSum = solve(root->right, ans);
        if(leftSum > 0 && rightSum > 0) ans = max(ans, leftSum+rightSum+root->data);
        else if(leftSum < 0 && rightSum < 0) ans = max(ans, root->data);
        else ans = max(ans, root->data + max(leftSum, rightSum));
        return max(0, root->data + max(leftSum, rightSum));
    }
    int findMaxSum(Node *root) {
        // code here
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};