#include <iostream>
#include <vector>

using namespace std;

int searchOrdered(vector<int> &nums, int target, int first, int last)
{
    if (nums[first] == target)
        return first;
    while (first != last)
    {
        const int mid = (first + last) / 2;
        if (nums[mid] == target)
            return mid;
        if (target < nums[mid])
            last = mid;
        else
            first = mid + 1;
    }
    return -1;
}

int search(vector<int> &nums, int target)
{
    int first = 0;
    int last = nums.size();
    while (first != last)
    {
        const int mid = (first + last) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[first] < nums[mid])
        {
            if (nums[first] <= target && target < nums[mid])
                // last = mid;
                return searchOrdered(nums, target, first, mid);
            else
                first = mid + 1;
        }
        else
        {
            if (nums[mid] < target && target <= nums[last - 1])
                // first = mid + 1;
                return searchOrdered(nums, target, mid + 1, last);
            else
                last = mid;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    vector<int> num = {1, 3};
    int target = 2;
    int index = search(num, target);
    cout << index << endl;
    return 0;
}
