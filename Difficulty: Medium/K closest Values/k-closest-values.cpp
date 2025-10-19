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
    vector<int>arr;
    void trav(Node* root, int target, int &closest, int &diff){
        if(!root) return;
        trav(root->left, target, closest, diff);
        
        arr.push_back(root->data);
        if(diff > abs(root->data - target)){
            closest = root->data;
            diff = abs(root->data - target);
        }
        
        trav(root->right, target, closest, diff);
    }
    vector<int> getKClosest(Node* root, int target, int k) {
        // code here
        arr = {};
        int closest = 0, diff = INT_MAX;
        trav(root, target, closest, diff);
        
        int i = 0, j = 0, n = arr.size();
        while(arr[i] != closest){
            i++;
        }
        vector<int>res;
        res.push_back(arr[i]);
        
        j = i+1;
        i -= 1;
        k--;
        
        // cout<<res[0]<<" "<<j<<" "<<i<<endl;
        
        while(k--){
            if(i < 0){
                k++;
                while(k--){
                    res.push_back(arr[j]);
                    j++;
                }
                break;
            }
            else if(j >= n){
                k++;
                while(k--){
                    res.push_back(arr[i]);
                    i--;
                }
                break;
            }
            
            
            if(abs(arr[i] - target) <= abs(arr[j] - target)){
                res.push_back(arr[i]);
                i--;
            }
            else{
                res.push_back(arr[j]);
                j++;
            }
        }
        
        
        
        return res;
    }
};