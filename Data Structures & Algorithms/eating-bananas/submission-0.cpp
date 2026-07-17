class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lower = 1;
        int upper = *max_element(piles.begin(), piles.end());
        int result = upper;

        while(lower <= upper)
        {
            int mid = lower + ((upper - lower) / 2);
            long long time = 0;

            for(int p : piles)
            {
                time += ceil((static_cast<double>(p) / mid));
            }

            if(time <= h)
            {
                result = mid;
                upper = mid - 1;
            } else 
            {
                lower = mid + 1;
            }
        }

        return result;
    }
};
