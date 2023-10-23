#include <iostream>

using namespace std;

int arr[1001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	arr[1] = 1;
	arr[2] = 3;

	int n;
	cin >> n;

	for (int i = 3; i <= n; i++)
		arr[i] = (arr[i - 1] + arr[i - 2] * 2) % 10007;
	
	cout << arr[n];
}