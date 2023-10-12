/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        int left = 1, right = n - 2;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (mountainArr.get(mid) > mountainArr.get(mid + 1))
                right = mid - 1;
            else
                left = mid + 1;
        }


        int peakIndex = left;

        left = 0, right = peakIndex;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            int value = mountainArr.get(mid);

            if (value == target)
                return mid;

            else if (value < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        left = peakIndex, right = n - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            int value = mountainArr.get(mid);

            if (value == target)
                return mid;

            else if (value < target)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return -1;
    }
};
