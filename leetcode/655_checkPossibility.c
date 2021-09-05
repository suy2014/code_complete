class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int change_time = 0;
        int second_max = -100000;
        int first_max = -100000;
        int flag = 0;
        int ignore_flag = 1;

        for (int i = 0; i < nums.size() - 1; ++i)
        {
            flag = 0;
            if (nums[i] > nums[i + 1]) {
                if (i == 0) {
                    ignore_flag = 0;
                }
                ++flag;
                if ((nums[i + 1] < first_max) && (nums[i + 1] > second_max)) {
                    second_max = nums[i + 1];
                }
                if (nums[i + 1] > first_max) {
                    second_max = first_max;
                    first_max =nums[i];
                }
            }
            if ((nums[i] < second_max) && ignore_flag) {
                ++flag;
            }
            if (flag) {
                printf("i %d, %d %d, max%d\n", i, flag, nums.size(), first_max);
                ++change_time;
            }
            if ((i == nums.size() - 2) && (nums[i + 1] < second_max) && ignore_flag) {
                ++change_time;
            }

            if (change_time > 1) {
                return false;
            }
        }
        return true;
    }
};

/**
 * case 1: [5,7,1,8]
 * case 2: [3,4,2,3]
 */
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int tmp_num;
        if (nums.size() == 0) {
            return true;
        }

        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                tmp_num = nums[i];
                nums[i] = nums[i + 1];
                if (is_sorted(nums.begin(), nums.end())) {
                    nums[i] = tmp_num;
                    return true;
                } else {
                    nums[i] = tmp_num;
                    nums[i + 1] = tmp_num;
                    return is_sorted(nums.begin(), nums.end());
                }
            }
        }
        return true;
    }
};

/**
 * case 1: [5,7,1,8]
 * case 2: [3,4,2,3]
 */
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        if (nums.size() == 0) {
            return true;
        }

        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                ++count;
                if (count > 1) {
                    return false;
                }
                if (i > 0 && nums[i + 1] < nums[i - 1]) {
                    nums[i + 1] = nums[i];
                }
            }
        }
        return true;
    }
};

