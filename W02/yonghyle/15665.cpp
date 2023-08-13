#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int input[8];
int prev_num[8];
int num[8];


void recur(int idx, int depth)
{
	while (1)
	{
		if (depth == m)
		{
			for (int j = 0; j < m; j++)
				cout << num[j] << " ";
			cout << "\n";
			return ;
		}
		else if (idx >= n)
		{
			prev_num[depth] = 0;
			return ;
		}
		if (prev_num[depth] != input[idx])
		{
			num[depth] = input[idx];
			prev_num[depth] = input[idx];

			recur(0, depth + 1);
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

// 같은 자리수에는 중복되는 숫자가 올 수 없다...?