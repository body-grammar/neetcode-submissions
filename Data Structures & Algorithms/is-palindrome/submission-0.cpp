class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        int k = 0;

        for(char c : s)
        {
            if(isalnum(c))
            {
                str.push_back(c);
                k++;
            }
        }

        for(char& c : str)
        {
            c = tolower(c);
        }

        int start = 0;
        int end = k - 1;
        string rev = str;

        while(start < end)
        {
            swap(rev[start], rev[end]);

            start++;
            end--;
        }

        if(rev == str)
        {
            return true;
        } else 
        {
            return false;
        }
    }
};
