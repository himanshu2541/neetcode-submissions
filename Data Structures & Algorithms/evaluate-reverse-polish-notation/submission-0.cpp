class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (auto token : tokens) {
            if (token != "+" && token != "-" && token != "*" && token != "/")
                st.push(stoi(token));

            else {
                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                int ans;

                if(token == "+"){
                    ans = a + b;
                } else if (token == "-"){
                    ans = a - b;
                } else if (token == "*"){
                    ans = a * b;
                } else {
                    ans = a / b;
                }

                st.push(ans);
            }
        }

        return st.top();
    }
};
