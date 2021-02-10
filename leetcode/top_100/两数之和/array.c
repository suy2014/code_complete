/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int first_index, secend_index;
    int *two_sum_id;

    *returnSize = 0;
    two_sum_id = calloc(1, sizeof(int) * 2);
    for (first_index = 0; first_index < numsSize; ++first_index) {
        secend_index = first_index + 1;
        for (; secend_index < numsSize; ++secend_index) {
            if (( nums[first_index] + nums[secend_index]) == target) {
                two_sum_id[0] = first_index;
                two_sum_id[1] = secend_index;
                *returnSize = 2;
            }
        }
    }

    return two_sum_id;
}
