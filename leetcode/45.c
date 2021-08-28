int jump(int* nums, int numsSize){
    int max_len = 0;
    int max_time = 0;
    int end = 0;

    for(int i = 0; i < numsSize - 1; ++i) {
        if (max_len < i + nums[i]) {
            max_len = i + nums[i];

        }
        if (end == i) {
            end = max_len;
            max_time++;
        }

    }
    return max_time;
}

int climbStairs(int n){
    int index_first = 1;
    int index_second = 1;
    int tmp;

    for (int i = 2; i <= n; ++i) {
        tmp = index_first + index_second;
        index_second = index_first;
        index_first = tmp;
    }

    return index_first;
}
