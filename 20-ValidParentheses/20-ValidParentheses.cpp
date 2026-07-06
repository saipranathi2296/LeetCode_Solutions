// Last updated: 7/6/2026, 12:11:43 PM
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c : s) {
            if(c=='(' || c=='{' || c=='[') {
                st.push(c);
            }
            else {
                if(!st.empty() && (
                    (st.top()=='(' && c==')') ||
                    (st.top()=='{' && c=='}') ||
                    (st.top()=='[' && c==']')
                )) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        return st.empty(); // IMPORTANT
    }
};
