class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        s2.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (s1.empty()) {
            push_s2_to_s1();
        }
        s1.pop();
    }

    // Get the front element.
    int peek(void) {
        if (s1.empty()) {
            push_s2_to_s1();
        }
        return s1.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return (s1.empty() && s2.empty());
    }

private:
    stack<int> s1;
    stack<int> s2;

    void push_s2_to_s1() {
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
};
