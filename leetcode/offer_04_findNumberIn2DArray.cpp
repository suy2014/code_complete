class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) {
            return false;
        }
        int col_lenth = matrix[0].size(), raw_lenth = matrix.size();
        int index_col = col_lenth - 1;
        int index_raw = 0;

        while ((index_raw < raw_lenth) && (index_col >= 0)) {
            if (matrix[index_raw][index_col] == target) {
                return true;
            }
            if (matrix[index_raw][index_col] > target) {
                --index_col;
            } else {
                ++index_raw;
            }
        }
        return false;
    }
};
