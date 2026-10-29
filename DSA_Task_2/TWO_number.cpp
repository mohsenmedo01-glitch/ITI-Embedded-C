#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6};
    int k = 7;

    int left = 0;
    int right = v.size() - 1;

    while (left < right)
    {
        int sum = v[left] + v[right];

        if (sum == k)
        {
            cout << v[left] << " + " << v[right] << " = " << k << '\n';
            left++;
            right--;
        }
        else if (sum < k)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return 0;
}