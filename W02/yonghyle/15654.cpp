#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
int input[8];
int flag[8];

void recur(int idx, int depth)
{
	while (1)
	{
		if (depth == m)
		{
			for (int i = 0; i < m; i++)
			{
				if (flag[i])
				{
					cout << "i: " << i << "\n";
					cout << input[i] << " ";
				}
			}
			cout << "\n";
			return ;
		}
		else if (idx >= n)
		{
			cout << "over\n";
			return ;
		}
		if (flag[idx] == 0)
		{
			flag[idx] = 1;
			recur(0, depth + 1);
			flag[idx] = 0;
		}
		idx++;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	memset(input, 9, sizeof(int) * 8);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> input[i];
	sort(input, input + 8);

	recur(0, 0);
}