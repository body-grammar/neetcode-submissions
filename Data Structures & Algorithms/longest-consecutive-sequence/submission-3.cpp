class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us(nums.begin(), nums.end());

        int result = 0;

        for(int x : nums)
        {
            if(!us.count(x - 1))
            {
                int current = x;
                int count = 1;

                while(us.count(current + 1))
                {
                    count++;
                    current++;
                }

                result = max(result, count);
            }
        }

        return result;
    }
};
