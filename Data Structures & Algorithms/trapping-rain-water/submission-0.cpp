class Solution {
public:
    int trap(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int left = height[0];
        int right = height[height.size() - 1];
        int water = 0;

        while(start <= end)
        {
            left = max(height[start], left);
            right = max(height[end], right);

            if(left <= right)
            {
                water += left - height[start];
                start++;
            } else 
            {
                water += right - height[end];
                end--;
            }
        }

        return water;
    }
};
