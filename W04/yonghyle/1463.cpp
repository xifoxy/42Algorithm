#include <iostream>
#include <climits>

using namespace std;

int arr[3000001];

int main()
{
	int n;
	cin >> n;

	/*
	
	6(2) 3(1) 1(0)
	6(2) 2(1) 1(0)

	10(4) 5(3) 4(2) 2(1) 1(0)
	10(3) 9(2) 3(1) 1(0)

	*/

	// 1 = 0
	// for - i -> +1 / i + 2 -> +1 / i + 3 -> +1 /

	for (int i = 2; i <=3000000; i++)
		arr[i] = INT_MAX;

	for (int i = 2; i <= n; i++)
	{
		if (arr[i] == INT_MAX || i == 2 || i == 3)
			arr[i] = 1;
		arr[i * 2] = min(arr[i] + 1, arr[i * 2]);
		arr[i * 3] = min(arr[i] + 1, arr[i * 3]);
		arr[i + 1] = min(arr[i] + 1, arr[i + 1]);

	}
	// arr[2] = 1, arr[4] = 2, arr[6] = 2, arr[3] = 2
	// arr[3] = 
	cout << arr[n];
}