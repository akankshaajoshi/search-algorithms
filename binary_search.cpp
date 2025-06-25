#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class BinarySearch
{

private:
    vector<int> arr;

public:
    BinarySearch(int size)
    {
        arr.resize(size);
    }

    BinarySearch(vector<int> inputArr)
    {
        sort(inputArr.begin(), inputArr.end());
        arr = inputArr;
    }

    BinarySearch(int size, vector<int> inputArr)
    {
        arr.resize(size);
        sort(inputArr.begin(), inputArr.end());
        for (int i = 0; i < size && i < inputArr.size(); i++)
        {
            arr[i] = inputArr[i];
        }
    }

    int search(int target)
    {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target)
            {
                return mid;
            }
            else if (arr[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }
};