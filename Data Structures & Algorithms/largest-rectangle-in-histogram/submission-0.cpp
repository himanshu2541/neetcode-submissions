class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;  // indices

        int n = heights.size();
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int elIdx = st.top();
                st.pop();

                int nseIdx = i;
                int pseIdx = st.empty() ? -1 : st.top();

                int width = nseIdx - pseIdx - 1;
                int area = heights[elIdx] * width;

                maxArea = max(maxArea, area);
            }

            st.push(i);
        }

        // Elements remaining in stack have no NSE
        while (!st.empty()) {
            int elIdx = st.top();
            st.pop();

            int nseIdx = n;  
            int pseIdx = st.empty() ? -1 : st.top();

            int width = nseIdx - pseIdx - 1;
            int area = heights[elIdx] * width;

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
