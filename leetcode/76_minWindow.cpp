class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> flag(256, 0);
        vector<int> counter(256, 0);

        for (int i = 0; i < t.size(); ++i)
        {
            flag[t[i]] = 1;
            ++counter[t[i]];
        }

        int num_for_end_conter = 0, min_left = 0,  left = 0, min_length = s.size() + 1;
        for (int right = 0; right < s.size(); ++right)
        {
            printf(" \n");
            if (flag[s[right]]) {
                --counter[s[right]];
                if (counter[s[right]] >= 0) {
                    ++num_for_end_conter;
                }
                printf(" num_for_end_conter%d \n" , num_for_end_conter);

                while (num_for_end_conter == t.size()) {
                    printf("== %d  %d, \n", flag[s[left]], counter[s[left]], num_for_end_conter );
                    if ((flag[s[left]]) && ++counter[s[left]] > 0) {
                        // (min_length < right - left + 1) ? min_length : (right - left + 1);
                        // ++left;
                        --num_for_end_conter;
                    }

                    if (min_length > right - left + 1) {
                        min_left = left;
                        min_length = right - left + 1;
                    }
                    ++left;
                }

            }
        }

        return min_length < (s.size() + 1) ? s.substr(min_left, min_length) : "";
    }
};
