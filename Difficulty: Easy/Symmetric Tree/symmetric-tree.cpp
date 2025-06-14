/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    string Trav1(Node* root, string &s1){
        if(!root) {
            s1 += " " ;
            return "";
            
        }
        s1 += root->data;
        Trav1(root->left, s1);
        Trav1(root->right, s1);
        return s1;
    }
    string Trav2(Node* root, string &s1){
        if(!root) {
            s1 += " " ;
            return "";
            
        }
        s1 += root->data;
        Trav2(root->right, s1);
        Trav2(root->left, s1);
        return s1;
    }
    bool isSymmetric(Node* root) {
        // Code here
        string s1, s2;
        Trav1(root, s1);
        Trav2(root, s2);
        return (s1 == s2);
    }
};