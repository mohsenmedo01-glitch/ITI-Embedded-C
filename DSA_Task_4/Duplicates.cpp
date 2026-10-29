#include <iostream>
using namespace std;

int main()
{
    int arr[] = {3, 1, 2, 3, 1, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int uniqueArr[n];
    int size = 0;

    for (int i = 0; i < n; i++)
    {
        bool found = false;

        for (int j = 0; j < size; j++)
        {
            if (arr[i] == uniqueArr[j])
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            uniqueArr[size] = arr[i];
            size++;
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << uniqueArr[i] << " ";
    }

    return 0;
}