//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverseList(Node* head){
        Node* temp = NULL;
        Node* p1 = head;
        while(p1 != NULL){
            Node* p2 = p1->next;
            p1->next = temp;
            temp = p1;
            p1 = p2;
        }
        return temp;
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        Node* first = reverseList(num1);
        Node* second = reverseList(num2);
        
        Node* head = new Node(0);
        Node* temp = head;
        while(first != NULL && second != NULL){
            int carry = (temp->data+first->data+second->data) / 10;
            temp->data = (temp->data+first->data+second->data) % 10;
            temp->next = new Node(carry);
            temp = temp->next;
            first = first->next;
            second = second->next;
        }
        while(first != NULL){
            int carry = (temp->data + first->data) / 10;
            temp->data = (temp->data + first->data) % 10;
            temp->next = new Node(carry);
            temp = temp->next;
            first = first->next;
        }
        while(second != NULL){
            int carry = (temp->data + second->data) / 10;
            temp->data = (temp->data + second->data) % 10;
            temp->next = new Node(carry);
            temp = temp->next;
            second = second->next;
        }
        head = reverseList(head);
        while(head->data == 0){
            head = head->next;
        }
        return head;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends