class Solution {
public:
    int trap(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int left = height[start];
        int right = height[end];
        int water = 0;

        while(start <= end)
        {
            left = max(left, height[start]);
            right = max(right, height[end]);

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
