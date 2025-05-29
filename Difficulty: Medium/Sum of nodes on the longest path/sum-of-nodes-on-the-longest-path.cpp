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
    map<int,int>mp;
    void fun(Node* root, int sum , int level){
        if(root == NULL) return;
        if(root->left == NULL and root->right == NULL){
            sum += root->data;
            mp[level] = max(mp[level], sum);
            return;
        }
        sum += root->data;
        fun(root->left, sum, level+1);
        fun(root->right, sum, level+1);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        mp = {};
        fun(root, 0, 1);
        auto it = mp.end();
        it--;
        return it->second;
    }
};