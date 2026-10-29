#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 12, -5, -6, 50, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int K = 4;

    if (K <= 0 || K > n)
    {
        cout << "Invalid K";
        return 1;
    }

    int sum = 0;

    for (int i = 0; i < K; i++)
    {
        sum += arr[i];
    }

    int maxSum = sum;

    for (int right = K; right < n; right++)
    {
        sum = sum - arr[right - K] + arr[right];

        if (sum > maxSum)
        {
            maxSum = sum;
        }
    }

    double maxAverage = (double)maxSum / K;

    cout << "Maximum Average = " << maxAverage;

    return 0;
}