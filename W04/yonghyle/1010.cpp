#include <iostream>

using namespace std;

int n, m, arr[30][30];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 30; i++)
		arr[i][i] = 1;

	arr[0][0] = 1;
	for (int i = 0; i < 30; i++)
	{
		for (int j = i + 1; j < 30; j++)
			arr[i][j] = arr[i][j - 1] + (i + 1);
	}

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		
		cin >> n >> m;	
		cout << arr[n - 1][m - 1] << "\n";
	}
}
