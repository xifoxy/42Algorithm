#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
long long result = -1;
int arr[10][10];
bool visit[10];

void  rec(int depth, int city, long long sum)
{
	if  (depth == n - 1)
	{
		if (arr[city][0] != 0)
		{
			if (result == -1 || sum + arr[city][0] < result)
				result = sum + arr[city][0];
		}
		return ;
	}

	for (int i = 0; i < n; i++)
	{
		if (visit[i] == true || arr[city][i] == 0)
			continue;
		
		visit[i] = true;
		rec(depth + 1, i, sum + arr[city][i]);
		visit[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	int input;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> input;
			arr[i][j] = input;
		}
	}

    visit[0] = true;
	rec(0, 0, 0);
	cout << result;
}