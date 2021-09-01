/**
 * 时间复杂度 O(nlgn)
 * 空间复杂度 lg(n)
 * @param  a [description]
 * @param  b [description]
 * @return   [description]
 */
int cmp (void* a, void *b) {
    return ((int *)*((int **)a))[1] < ((int *)*((int **)b))[1] ? -1: 1;
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize){
    qsort(points, pointsSize, sizeof(int *), cmp);
    int prev = -1;
    int max_shot = 0;
    if (pointsSize > 0) {
        prev = points[0][1];
        ++max_shot;
    }

    for (int i = 0; i < pointsSize; ++i)
    {
        if (points[i][0] > prev) {
            prev = points[i][1];
            ++max_shot;
        }
    }

    return max_shot;
}
