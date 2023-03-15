bool scores(int *nums, int left, int right, int score, bool player)
{
    if (left > right)
        return (score >= 0);

    if (player)
    {
        if (scores(nums, left + 1, right, score + nums[left], !player))
            return (true);
        return (scores(nums, left, right - 1, score + nums[right], !player));
    }

    return (scores(nums, left + 1, right, score - nums[left], !player) &&
	    scores(nums, left, right - 1, score - nums[right], !player));
}
bool PredictTheWinner(int* nums, int numsSize){
    return (scores(nums, 0, numsSize - 1, 0, true));
}
