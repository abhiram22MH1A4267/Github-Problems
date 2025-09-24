class SpecialQueue {

  public:
    queue<int> q1;
    deque<int> q2, q3;

    void enqueue(int x) {
        // Insert element into the queue
        q1.push(x);
        while (!q2.empty() && q2.back() > x) {
            q2.pop_back();
        }
        q2.push_back(x);
        
        while (!q3.empty() && q3.back() < x) {
            q3.pop_back();
        }
        q3.push_back(x);
    }

    void dequeue() {
        // Remove element from the queue
        if (q1.empty()) {
            return;
        }
        int frontVal = q1.front();

        if (frontVal == q2.front()) {
            q2.pop_front();
        }
        if (frontVal == q3.front()) {
            q3.pop_front();
        }

        q1.pop();
    }

    int getFront() {
        // Get front element
        if (q1.empty()) {
            return -1;
        }
        return q1.front();
    }

    int getMin() {
        // Get minimum element
        if (q1.empty()) {
            return -1;
        }
        return q2.front();
    }

    int getMax() {
        // Get maximum element
        if (q1.empty()) {
            return -1;
        }
        return q3.front();
    }
};