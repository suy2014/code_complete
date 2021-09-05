class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int max_long = 0;
        vector<int> d_num(nums.size(), 1);

        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i]) {
                    if (d_num[i] < d_num[j] + 1) {
                        d_num[i] = d_num[j] + 1;
                    }
                }
            }
            if (d_num[i] > max_long) {
                max_long = d_num[i];
            }
        }
        return max_long;
    }
};

/**
 * 优化 Onlgn
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int max_long = 0;
        vector<int> d_num(nums.size(), -10000);
        if (nums.size() == 0) {
            return 0;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (d_num[max_long] < nums[i]) {
                // ++max_long;
                // printf("%d %d %d\n", i, max_long, d_num[max_long]);
                d_num[++max_long] = nums[i];
                printf("%d %d %d\n", i, max_long, d_num[max_long]);
            } else {
                int l = 0, r = max_long, point = 0;
                while (l <= r) {
                    int mid = (l + r ) >> 1;
                    if (d_num[mid] < nums[i]) {
                        point = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                    // printf("mid%d, l %d, r %d, point %d\n", mid, l, r,point);
                }
                d_num[point + 1] = nums[i];
            }
        }
        return max_long;
    }
};

