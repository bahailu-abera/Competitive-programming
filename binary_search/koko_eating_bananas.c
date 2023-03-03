// int min(int *array, int size)
// {
//     int i, m;
//     m = array[0];
//     for (i = 1; i < size; i++)
//         (array[i] < m) && (m = array[i]);
//     return (m);
// }

int max(int *array, int size)
{
    int i, m;

    m = array[0];
    for (i = 1; i < size; i++)
        (array[i] > m) && (m = array[i]);

    return (m);
}

int minEatingSpeed(int* piles, int pilesSize, int h){
    int min_speed, max_speed;
    int i, mid;
    int long hours;

    min_speed = 1;
    max_speed = max(piles, pilesSize);

    while (min_speed <= max_speed)
    {
        mid = min_speed + (max_speed - min_speed) / 2;
        hours = 0;
        for (i = 0; i < pilesSize; i++)
        {
            hours += piles[i] / mid;
            (piles[i] / mid * mid < piles[i]) && (++hours);
        }
        if (hours > h)
            min_speed = mid + 1;
        else
            max_speed = mid - 1;
    }
    return (min_speed);
}
