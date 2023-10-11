#include <iostream>

using namespace std;

long long n, m, arr[1001][1001];

/*

	1  1  1  1  1  1  1  1  1
	1  3  5  7  9 11 13 15
	1  7 15
	1  9 31
	1 11
	1 13
	1 15

*/

int main()
{
	for (int i = 0; i <= 1000; i++)
	{
		arr[i][0] = 1;
		arr[0][i] = 1;
	}

	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 1; j <= 1000; j++)
			arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j] + arr[i][j - 1]) % 1000000007;
	}

	cin >> n >> m;
	cout << arr[n - 1][m - 1] << "\n";
}