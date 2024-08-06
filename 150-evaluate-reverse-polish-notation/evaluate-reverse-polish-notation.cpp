class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for (auto t : tokens)
    {
        if (t != "+" && t != "*" && t != "-" && t != "/") st.push(stoi(t));
        else {
            int second = st.top();
            st.pop();
            int first = st.top();
            st.pop();
            if (t == "+") {
                st.push(first + second);
            }
            else if (t == "-") {
                st.push(first - second);
            }
            else if (t == "/") {
                st.push(first / second);
            }
            else if (t == "*") {
                st.push(first * second);
            }
        }
    }

    return st.top();
}
};