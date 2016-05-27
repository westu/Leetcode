public class MinStack {
    private Stack<Integer> st;
    private Stack<Integer> minSt;

    /** initialize your data structure here. */
    public MinStack() {
        st = new Stack<Integer>();
        minSt = new Stack<Integer>();
    }
    
    public void push(int x) {
        st.push(x);
        if (minSt.empty()) {
            minSt.push(x);
        } else {
            minSt.push(Math.min(x, minSt.peek()));
        }
    }
    
    public void pop() {
        st.pop();
        minSt.pop();
    }
    
    public int top() {
        return st.peek();
    }
    
    public int getMin() {
        return minSt.peek();
    }
}
