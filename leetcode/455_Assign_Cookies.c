/**
 * 时间复杂度 O(mlogm+nlogn)
 * 空间复杂度：O(logm+logn)
 * @param base  [description]
 * @param start [description]
 * @param end   [description]
 */
void quicksort(int * base, int start, int end) {
    int sentry = 0;
    int i = start;
    int j = end;
    if (end <= 0) {
        return;
    }
    //printf("start quicksort\n");

    sentry = base[start];
    while (i < j) {
        while (i < j && base[j] >= sentry ) {
            j--;
            //printf("a i %d , j   %d\n", i, j);
        }
        base[i] = base[j];
        //printf("base[%d]=%d\n",i,base[i]);
        while (i < j && base[i] <= sentry) {
            i++;
            //printf("b i %d , j   %d\n", i, j);
        }
        base[j] = base[i];
        //printf("base[%d]=%d\n",j,base[j]);
    }
    base[j] = sentry;

    if (start < i - 1) {
        quicksort(base, start, i - 1);

    }
    if (i + 1 < end) {
        quicksort(base, i + 1, end);
    }

    return;
}

int findContentChildren(int* g, int gSize, int* s, int sSize){
    quicksort(g, 0, gSize -1);
    quicksort(s, 0, sSize -1);

    int child = 0, cookie = 0;
    while (child < gSize && cookie < sSize) {
        if (g[child] <= s[cookie]) {
            ++child;
        }
        ++cookie;
    }
    return child;
}
