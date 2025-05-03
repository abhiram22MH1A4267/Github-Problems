//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution {
  public:
    vector<bool> sieve;
    vector<int> primes;
    
    void generatePrimes(int maxLimit) {
        sieve.assign(maxLimit + 1, true);
        sieve[0] = sieve[1] = false;

        for (int i = 2; i * i <= maxLimit; ++i) {
            if (sieve[i]) {
                for (int j = i * i; j <= maxLimit; j += i) {
                    sieve[j] = false;
                }
            }
        }

        for (int i = 2; i <= maxLimit; ++i) {
            if (sieve[i]) {
                primes.push_back(i);
            }
        }
    }
    
    int nearestPrime(int num) {
        if (sieve[num]) return num;

        int idx = lower_bound(primes.begin(), primes.end(), num) - primes.begin();

        int lower = (idx > 0) ? primes[idx - 1] : INT_MAX;
        int upper = (idx < primes.size()) ? primes[idx] : INT_MAX;

        if (abs(num - lower) <= abs(upper - num))
            return lower;
        else
            return upper;
    }
    
    Node *primeList(Node *head) {
        // code here
        generatePrimes(20000);

        Node* temp = head;
        while (temp != nullptr) {
            temp->val = nearestPrime(temp->val);
            temp = temp->next;
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
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.primeList(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends