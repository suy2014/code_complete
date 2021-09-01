bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    int max_flowed = 0;
    int prev = -1;

    for (int i = 0; i < flowerbedSize; ++i)
    {
        if (flowerbed[i] == 1) {
            if (prev < 0) {
                max_flowed += i / 2;
            } else {
                max_flowed += (i - prev - 2) / 2;
            }
            prev = i;
        }
    }

    if (prev < 0) {
        max_flowed = (flowerbedSize + 1) / 2;
    } else {
        max_flowed += (flowerbedSize - prev - 1) / 2;
    }

    return max_flowed >= n;
}
