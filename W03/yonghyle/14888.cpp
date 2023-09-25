#include <iostream>
#include <climits>

using namespace std;

int n, mmin = INT_MAX, mmax = INT_MIN;
int input[11];
int opt[4];

void rec(int depth, long long sum)
{
	if (depth == n - 1)
	{
		if (mmin > sum || mmin == INT_MAX)
			mmin = sum;
		if (mmax < sum || mmax == INT_MIN)
			mmax = sum;
	}

	for (int i = 0; i < 4; i++)
	{
		if (opt[i] == 0)
			continue;
		
		opt[i]--;
		switch (i)
		{
			case 0:
				rec(depth + 1, sum + input[depth + 1]);
				break;
			case 1:
				rec(depth + 1, sum - input[depth + 1]);
				break;
			case 2:
				rec(depth + 1, sum * input[depth + 1]);
				break;
			case 3:
				rec(depth + 1, sum / input[depth + 1]);
				break;
		}
		opt[i]++;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> input[i];
	for (int i = 0; i < 4; i++)
		cin >> opt[i];
	
	rec(0, input[0]);
	cout << mmax << "\n" << mmin;
}