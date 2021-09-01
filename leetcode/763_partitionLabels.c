class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> result;
        unordered_map<char, int> char_map;
        int end = 0, start = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            char_map[s[i]] = i;
        }

        for (int i = 0; i < s.size(); ++i)
        {
            if (char_map[s[i]] > end) {
                end = char_map[s[i]];
            }
            if (i == end) {
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return result;
    }
};
