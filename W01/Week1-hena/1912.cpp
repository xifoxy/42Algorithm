#include <iostream>
using namespace std;

int arr[100000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int maxValue = -100000000;
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; ++i)
        cin >> arr[i];

    int sum = 0;
    for (int i = 0 ; i < n ; ++i)
    {
        sum += arr[i];
        if (sum > maxValue)
            maxValue = sum;
        if (sum < 0)
            sum = 0;
    }
    cout << maxValue;
}