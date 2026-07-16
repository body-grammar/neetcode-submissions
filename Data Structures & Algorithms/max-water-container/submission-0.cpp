class Solution {
public:
    int maxArea(vector<int>& heights) {
        int start = 0;
        int end = heights.size() - 1;
        int maxArea = 0;

        while(start < end)
        {
            int width = end - start;
            int height = min(heights[start], heights[end]);
            int area = width*height;

            maxArea = max(maxArea, area);

            if(heights[start] < heights[end])
            {
                start++;
            } else
            {
                end--;
            }
        }

        return maxArea;
    }
};
