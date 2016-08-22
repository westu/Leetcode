class Stack {
 public:
    // Push element x onto stack.
    void push(int x) {
        st.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        while (st.size() > 1) {
          st_helper.push(st.front());
          st.pop();
        }
        st.pop();
        while (!st_helper.empty()) {
          st.push(st_helper.front());
          st_helper.pop();
        }
    }

    // Get the top element.
    int top() {
        int x;
        while (!st.empty()) {
          st_helper.push(st.front());
          x = st.front();
          st.pop();
        }
        while (!st_helper.empty()) {
          st.push(st_helper.front());
          st_helper.pop();
        }
        return x;
    }

    // Return whether the stack is empty.
    bool empty() {
        return st.empty();
    }

 private:
  queue<int> st, st_helper;
};
