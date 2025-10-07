class Solution {
public:
    string infixToPostfix(string& s) {
        stack<char> st;
        string ans = "";
        unordered_map<char, int> priority = {
            {'+', 1}, {'-', 1},
            {'*', 2}, {'/', 2},
            {'^', 3}
        };

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (isalnum(c)) {
                ans += c;
            } 
            else if (c == '(') {
                st.push(c);
            } 
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            } 
            else {
                while (!st.empty() && st.top() != '(' &&
                      ((c == '^' && priority[c] < priority[st.top()]) ||
                       (c != '^' && priority[c] <= priority[st.top()]))) {
                    ans += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};
