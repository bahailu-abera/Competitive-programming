#define MIN(a, b) ((a) > (b) ? (b): (a))

int maxArea(int* height, int heightSize){
    int maxVolume = 0;
    int volume;
    int l, r;

    l = 0;
    r = heightSize - 1;

    while (l < r)
    {
        volume = MIN(height[l], height[r]) * (r - l);
       ( maxVolume < volume) && (maxVolume = volume);
       if (height[l] < height[r])
            l++;
        else
            r--;
    }
    return (maxVolume);
}
