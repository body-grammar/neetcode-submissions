class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;

        for(int i = 0; i < heights.size(); i++)
        {
            while(!st.empty() && heights[i] <= heights[st.top()])
            {
                int height = heights[st.top()];
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;

                int width = right - left - 1;

                int area = width*height;

                maxArea = max(maxArea, area);
            }

            st.push(i);
        }

        while(!st.empty())
        {
            int height = heights[st.top()];
            st.pop();

            int left = st.empty() ? -1 : st.top();
            int right = heights.size();

            int width = right - left - 1;

            int area = width*height;

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
