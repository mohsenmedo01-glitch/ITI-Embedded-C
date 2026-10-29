#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int arr[] = {1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int K = 2;

    unordered_map<int, int> freq;

    freq[0] = 1;

    int prefix = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        prefix += arr[i];

        count += freq[prefix - K];

        freq[prefix]++;
    }

    cout << "Count = " << count;

    return 0;
}