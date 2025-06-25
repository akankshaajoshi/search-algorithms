#include <stdio.h>
#include <vector>

using namespace std;

class LinearSearch
{

private:
    vector<int> arr;

public:
    LinearSearch(int size)
    {
        arr.resize(size);
    }

    LinearSearch(vector<int> inputArr)
    {
        arr = inputArr;
    }

    LinearSearch(int size, vector<int> inputArr)
    {
        arr.resize(size);
        for (int i = 0; i < size && i < inputArr.size(); i++)
        {
            arr[i] = inputArr[i];
        }
    }

    int search(int target)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == target)
            {
                return i;
            }
        }
        return -1;
    }
};