//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Structure for the linked list node
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to print nodes in a given circular linked list
void printList(struct Node *head) {
    if (head != NULL) {
        struct Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    } else {
        cout << "empty" << endl;
    }
    cout << endl;
}


// } Driver Code Ends
class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        // code here
        if (head == nullptr || head->next == head) {
        return head;
    }

    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;

    do {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    } while (current != head);

    // Fix the next of the original head
    head->next = prev;
    head = prev;

    return head;
        
    }

    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        // code here
        if (head == nullptr) {
        return nullptr;
    }

    Node* current = head;
    Node* prev = nullptr;

    // Check if the head node is the node to be deleted
    if (head->data == key) {
        // If there's only one node in the list
        if (head->next == head) {
            delete head;
            return nullptr;
        }

        // Find the last node to update its next pointer
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }

        // Update the last node's next pointer and delete the head
        last->next = head->next;
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // Search for the node to delete
    do {
        prev = current;
        current = current->next;
    } while (current != head && current->data != key);

    // If node with the key is found
    if (current->data == key) {
        prev->next = current->next;
        delete current;
    }

    return head;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Reading input into a vector
        while (ss >> number) {
            arr.push_back(number);
        }

        int key;
        cin >> key;
        cin.ignore();

        // Creating the circular linked list
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make the list circular

        Solution ob;

        // Delete the node with the given key
        head = ob.deleteNode(head, key);

        // Reverse the circular linked list
        head = ob.reverse(head);

        // Print the modified list
        printList(head);
    }
    return 0;
}

// } Driver Code Ends