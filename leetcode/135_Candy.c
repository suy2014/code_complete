
/**
 * 时间复杂度 O（n）, 空间复杂度 O（n）
 * @param  ratings     [description]
 * @param  ratingsSize [description]
 * @return             [description]
 */
int candy(int* ratings, int ratingsSize){
    int i = 0;
    int* candy = (int *)malloc(sizeof(int) * ratingsSize);
    int candy_total = 0;
    for (i = 0; i < ratingsSize; ++i) {
        candy[i] = 1;
    }

    for (i = 0; i < ratingsSize; ++i) {
        if ((i + 1) < ratingsSize) {
            if (ratings[i] < ratings[i + 1]) {
                candy[i + 1] = candy[i] + 1;
            }
        }
    }

    for (i = ratingsSize - 1; i > 0; --i) {
        if ((i - 1) >= 0) {
            if (ratings[i] < ratings[i - 1]) {
                if (candy[i - 1] <= candy[i]) {
                    candy[i - 1] = candy[i] + 1;
                }
            }
        }
    }

    for (i = 0; i < ratingsSize; ++i)
    {
        printf("candy[%d]= %d\n", i, candy[i]);
        candy_total += candy[i];
    }

    return candy_total;
}
