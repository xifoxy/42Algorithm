#include <iostream>

using namespace std;

int n, m, arr[31][31];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	for (int i = 1; i <= 30; i++)
		arr[1][i] = i;
	
	for (int i = 1; i <= 30; i++)
		arr[i][i] = 1;
	
	for (int i = 2; i <= 30; i++)
	{
		for (int j = i + 1; j <= 30; j++)
		{
			for (int y = j - 1; y >= i - 1; y--)
				arr[i][j] += arr[i - 1][y];
		}
	}

	// for (int i = 0; i <= 30; i++)
	// 	arr[0][i] = 1;
	
	// for (int i = 1; i <= 30; i++)
	// {
	// 	for (int j = 1; j <= 30; j++)
	// 		arr[i][j] = arr[i - 1][j - 1] + arr[i][j - 1];
	// }

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		
		cin >> n >> m;	
		cout << arr[n][m] << "\n";
	}
}
