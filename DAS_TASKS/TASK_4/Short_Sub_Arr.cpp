#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int arr[] = {2, 3, 1, 2, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int K = 7;

    int left = 0;
    int sum = 0;
    int minLength = INT_MAX;

    for (int right = 0; right < n; right++)
    {
        sum += arr[right];

        while (sum >= K)
        {
            int length = right - left + 1;

            if (length < minLength)
            {
                minLength = length;
            }

            sum -= arr[left];
            left++;
        }
    }

    if (minLength == INT_MAX)
    {
        cout << "No valid subarray";
    }
    else
    {
        cout << "Shortest Length = " << minLength;
    }

    return 0;
}