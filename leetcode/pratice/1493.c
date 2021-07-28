int longestSubarray(int* nums, int numsSize){
    int num_tem[100000]= {0};
    int index = 0;
    int sum = 0;
    int max = 0;

    for (int i = 0; i < numsSize; ) {
        printf("%d, %d\n", nums[i], i);
        while (nums[i]) {
            ++sum;
            ++i;
            if (i == numsSize) {
                break;
            }
        }

        if (sum) {
            num_tem[index++] = sum;
            sum = 0;
        }

        num_tem[index++] = 0;
        ++i;
    }

    if (index < 3) {
        // if ((num_tem[0] =! 0) || (num_tem[1] =! 0))
        return num_tem[0] + num_tem[1] - 1;
    }
    for (int j = 1; j < index - 1; ++j)
    {
        printf("%d\n", num_tem[j]);
        if (num_tem[j] == 0) {
            int max_tem = num_tem[j - 1] + num_tem[j + 1];
            if (max_tem > max) {
                max = max_tem;
            }
        }
    }
    return max;
}
