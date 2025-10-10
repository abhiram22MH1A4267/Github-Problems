/*
class Node {
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
    map<int, vector<int>>mp;
    
    void Traversal(Node* root, int level){
        if(!root) return;
        
        mp[level].push_back(root->data);
        Traversal(root->left, level+1);
        Traversal(root->right, level+1);
    }
    vector<int> zigZagTraversal(Node* root) {
        // code here
        mp = {};
        Traversal(root, 0);
        
        vector<int>result;
        
        for(auto it : mp){
            if((it.first&1) == 0){
                for(int i : it.second) result.push_back(i);
            }
            else{
                for(int i = it.second.size()-1; i >= 0; i--){
                    result.push_back(it.second[i]);
                }
            }
        }
        
        return result;
    }
};