class Solution {
public:
    int longestValidParentheses(string s) {
        int len = static_cast<int>(s.size());
        int last = -1;
        stack<int> st;
        int longest = 0;
        for (int i = 0; i < len; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (st.empty() == true) {
                    last = i;
                } else {
                    st.pop();
                    if (st.empty() == true) {
                        longest = max(longest, i - last);
                    } else {
                        longest = max(longest, i - st.top());
                    }
                }
            }
        }
        return longest;
    }
};
