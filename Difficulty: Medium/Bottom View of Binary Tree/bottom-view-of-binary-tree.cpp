/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    map<int,vector<int>>mp;
    vector<int>v;
    void BottomView(Node* root, int bf, int level){
        if(root == NULL) return;
        if(mp.find(bf) != mp.end()){
            if(mp[bf][0] < level){
                mp[bf] = {level,root->data};
            }
        }
        else{
            mp[bf] = {level,root->data};
        }
        BottomView(root->right, bf+1, level+1);
        BottomView(root->left, bf-1, level+1);
    }
    vector<int> bottomView(Node *root) {
        // code here
        mp.clear();
        BottomView(root, 0, 1);
        for(auto i : mp){
            v.push_back(i.second[1]);
        }
        return v;
    }
};