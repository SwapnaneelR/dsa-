QUICK SORT : class Solution
{
public:
    int Partition(vector<int> &nums, int start, int end)
    {
        int pos = start;
        while (start <= end)
        {
            if (nums[start] <= nums[end])
                swap(nums[start], nums[pos++]);
            start++;
        }
        // cout << start << end << pos - 1<<endl;
        return pos - 1;
    }
    void quicksort(vector<int> &nums, int start, int end)
    {
        if (start >= end)
            return;

        int pivot = Partition(nums, start, end);
        // cout << pivot << endl;

        quicksort(nums, start, pivot - 1);
        quicksort(nums, pivot + 1, end);
    }
    vector<int> sortArray(vector<int> &nums)
    {
        quicksort(nums, 0, nums.size() - 1);

        return nums;
    }
};
MERGE SORT:
