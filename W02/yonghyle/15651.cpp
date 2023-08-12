#include <iostream>

using namespace std;

int n, m;
int num[7];

void recur(int idx, int depth)
{
	while (1)
	{
		if (depth == m)
		{
			for (int i = 0; i < m; i++)
				cout << num[i] + 1 << " ";
			cout << "\n";
			return ;
		}
		else if (idx >= n)
			return ;
		num[depth] = idx;
		recur(0, depth + 1);
		idx++;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	recur(0, 0);
}