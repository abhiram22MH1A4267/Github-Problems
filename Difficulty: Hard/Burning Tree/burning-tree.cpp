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
    unordered_map<int,vector<int>>mp;
    vector<int>v;
    int cnt = 0;
    void fun(Node* root, Node* node){
        if(root == NULL) return;
        if(root->left != NULL){
            mp[root->data].push_back(root->left->data);
        }
        if(root->right != NULL){
            mp[root->data].push_back(root->right->data);
        }
        if(node != NULL){
            mp[root->data].push_back(node->data);
        }
        fun(root->left, root);
        fun(root->right, root);
    }
    
    void fun2(unordered_map<int,int>&ok, int c, int target){
        if(ok.find(target) != ok.end()){
            return;
        }
        if(ok.size() == mp.size()){
            return;
        }
        ok[target] = 1;
        
        cnt = max(cnt, c);
        
        for(int i = 0; i < mp[target].size(); i++){
            fun2(ok, c+1, mp[target][i]);
        }
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        mp = {};
        v = {};
        if(root == NULL){
            return 0;
        }
        fun(root, NULL);
        unordered_map<int,int>ok;
        fun2(ok, 0, target);
        return cnt;
    }
};