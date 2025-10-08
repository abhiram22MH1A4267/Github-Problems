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
};
*/

class Solution {
  public:
    int pre_idx = 0;
    unordered_map<int, int> post_map;

    Node* buildTreeHelper(vector<int>& pre, int post_left, int post_right) {
        if (pre_idx >= pre.size() || post_left > post_right) {
            return nullptr;
        }

        int root_val = pre[pre_idx++];
        Node* root = new Node(root_val);

        if (pre_idx >= pre.size() || post_left == post_right) {
            return root;
        }

        int left_root_val = pre[pre_idx];
        int left_root_pos = post_map[left_root_val];

        root->left = buildTreeHelper(pre, post_left, left_root_pos);

        root->right = buildTreeHelper(pre, left_root_pos + 1, post_right - 1);

        return root;
    }
    Node *constructTree(vector<int> &pre, vector<int> &post) {
        // code here
        if (pre.empty() || post.empty()) {
            return nullptr;
        }

        for (int i = 0; i < post.size(); ++i) {
            post_map[post[i]] = i;
        }

        return buildTreeHelper(pre, 0, post.size() - 1);
    }
};