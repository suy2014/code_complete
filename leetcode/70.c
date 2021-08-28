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
