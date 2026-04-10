class Solution {
public:
    bool isBalanced(string s) {
        stack<char> st;

        for (char ch : s) {
            // If opening bracket
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else {
                // If stack empty
                if (st.empty()) return false;

                char top = st.top();
                st.pop();

                // Check matching
                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    return false;
                }
            }
        }

        // If stack is empty → balanced
        return st.empty();
    }
};
