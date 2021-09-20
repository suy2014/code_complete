class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>  x_num(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            if (i % 2) {
                x_num[i] = x_num[i - 1] + 1;
            } else {
                x_num[i] = x_num[i >> 1];
            }
        }
        return x_num;
    }
};
