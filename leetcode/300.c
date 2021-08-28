int lengthOfLIS(int* nums, int numsSize){
    int i = 0, tem = 0;
    int lenth[2500];
    int max = 0;

    if (numsSize == 0) {
        return 0;
    }

    for ( ; i < numsSize; ++i) {
        lenth[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                tem = lenth[j] + 1;
                printf(" i %d j %d,  %d\n", i, j, lenth[j]);
                if (tem > lenth[i]) {
                    lenth[i] = tem;
                }
            }
        }
        if (lenth[i] > max) {
            max = lenth[i];
        }
    }
    return max;
}

10,9,2,5,3,7,101,18]

 i 3 j 2,  1
2
 i 4 j 2,  1
2
 i 5 j 2,  1
2
 i 5 j 3,  2
3
 i 5 j 4,  2
 i 6 j 0,  1
2
 i 6 j 1,  1
 i 6 j 2,  1
 i 6 j 3,  2
3
 i 6 j 4,  2
 i 6 j 5,  3
4
 i 7 j 0,  1
2
 i 7 j 1,  1
 i 7 j 2,  1
 i 7 j 3,  2
3
 i 7 j 4,  2
 i 7 j 5,  3
4
