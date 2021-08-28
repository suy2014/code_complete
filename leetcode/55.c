bool canJump(int* nums, int numsSize){
    int max = nums[0];
    for (int i = 0; i < numsSize; ++i) {
        if (max < i) {
            return false;
        }
        if ( (i + nums[i]) > max) {
            max = i + nums[i];
        }
        if (max >= numsSize - 1) {
            return true;
        }
    }
    return false;
}
