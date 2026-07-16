class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size() - 1;

        while(start < end)
        {
            int sums = numbers[start] + numbers[end];

            if(sums == target)
            {
                return {start + 1, end + 1};
            } else if(sums < target)
            {
                start++;
            } else 
            {
                end--;
            }
        }
    }
};
