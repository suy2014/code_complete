class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        vector<int> ret;

        while (left < right) {
            if ((numbers[left] + numbers[right]) == target) {
                ret.push_back(left + 1);
                ret.push_back(right + 1);
            }
            if ((numbers[left] + numbers[right]) < target) {
                ++left;
            } else {
                --right;
            }
        }

        return ret;
    }
};
