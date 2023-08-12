#include <iostream>
#include <vector>

using namespace std;

int n, m;
char flag[8];

void recur(int idx, int depth)
{
	while (1)
	{
		if (depth == m)
		{
			for (int i = 0; i < n; i++)
			{
				if (flag[i])
					cout << i + 1 << " ";
			}
			cout << "\n";
			return ;
		}
		else if (idx >= n)
			return ;
		if (!flag[idx])
		{
			flag[idx] = 1;
			recur(idx + 1, depth + 1);
			flag[idx] = 0;
		}
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