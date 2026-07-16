class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";

        string result = "";
        vector<int> sizes;

        for(string& s : strs)
        {
            result.append(to_string(s.size()));
            result.push_back('#');
            result.append(s);
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;

        int i = 0;
        while(i != s.size())
        {
            int j = i;
            while(s[j] != '#')
            {
                j++;
            }
            int len = stoi(s.substr(i, j - i));

            string word = s.substr(j + 1, len);

            result.push_back(word);
            i = j + 1 + len;
        }

        return result;
    }
};
