class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            int fixed = -(nums[i]);
            int start = i + 1;
            int end = nums.size() - 1;

            while(start < end)
            {
                if(nums[start] + nums[end] < fixed)
                {
                    start++;
                } else if(nums[start] + nums[end] > fixed)
                {
                    end--;
                } else 
                {
                    result.push_back({nums[i], nums[start], nums[end]});

                    start++;
                    end--;

                    while(start < end && nums[start] == nums[start - 1])
                    {
                        start++;
                    }
                }
            }
        }

        return result;
    }
};
