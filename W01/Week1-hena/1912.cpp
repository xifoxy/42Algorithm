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

// 하나씩 읽으면서, 0보다 크거나 같은 수 일 경우는 계속 진행하고, 합이 0보다 작은 경우 다시 셈.