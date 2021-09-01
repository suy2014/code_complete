
int comp (int **a, int **b) {
    return (*a)[1] - (*b)[1];
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize){

    qsort(intervals, intervalsSize, sizeof(int *), comp);

    int right_pointer;
    right_pointer = intervals[0][1];
    int max_result = 1;
    for (int i = 1; i < intervalsSize; ++i)
    {
        if (intervals[i][0] >= right_pointer) {
            ++max_result;
            right_pointer = intervals[i][1];
        }
    }

    return intervalsSize - max_result;
}
