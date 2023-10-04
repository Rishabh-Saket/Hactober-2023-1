class Solution {
public:
    int longestValidParentheses(std::string s) {
        int maxCount = 0;
        std::stack<int> st;
        st.push(-1);

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                st.push(i);  // Push the index of the opening parenthesis onto the stack
            } else {
                st.pop();  // Pop the index of the matching opening parenthesis
                if (st.empty()) {
                    st.push(i);  // If stack is empty, push the current index (unmatched closing parenthesis)
                } else {
                    maxCount = std::max(maxCount, i - st.top());  // Calculate the length of valid parentheses substring
                }
            }
        }

        return maxCount;
    }
};
