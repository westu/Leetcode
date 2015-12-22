class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < static_cast<int>(s.length()); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else if (s[i] == ')') {
                if (st.empty() == true|| st.top() != '(') {
                    return false;
                }
                st.pop();
            } else if (s[i] == ']') {
                if (st.empty() == true || st.top() != '[') {
                    return false;
                }
                st.pop();
            } else if (s[i] == '}') {
                if (st.empty() == true || st.top() != '{') {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
