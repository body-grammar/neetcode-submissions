class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int left, int right)
    {
        while(left <= right)
        {
            int mid = left + ((right - left) / 2);

            if(nums[mid] == target)
            {
                return mid;
            } else if(nums[mid] < target)
            {
                left = mid + 1;
            } else 
            {
                right = mid - 1;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int lower = 0;
        int upper = nums.size() - 1;

        while(lower < upper)
        {
            int mid = lower + ((upper - lower) / 2);

            if(nums[mid] > nums[upper])
            {
                lower = mid + 1;
            } else 
            {
                upper = mid;
            }
        }

        int pivot = lower;

        int result = binarySearch(nums, target, 0, pivot - 1);
        if(result != -1)
        {
            return result;
        }

        return binarySearch(nums, target, pivot, nums.size() - 1);
    }
};
