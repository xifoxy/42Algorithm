#include <iostream>

using namespace std;

int n, result;
int input[8];
bool visit[8];

void rec(int depth, int prev_idx, int sum)
{
	if (depth == n)
	{
		if (result < sum)
			result = sum;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (visit[i] == true)
			continue;
		
		visit[i] = true;
		if (depth == 0)
			rec(depth + 1, i, 0);
		else
			rec(depth + 1, i, sum + abs(input[prev_idx] - input[i]));
		visit[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> input[i];
	
	rec(0, 0, 0);
	cout << result;
}