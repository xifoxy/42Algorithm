#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> dwarfs(9);
vector<int> select(7);

void recur(int cnt, int idx, int sum)
{
	while (1)
	{
		if (idx > 8)
			return;
		if (cnt == 7)
		{
			if (sum == 100)
			{
				for (int x : select)
					select[x] = dwarfs[x];
				sort(select.begin(), select.end());
				for (int x : select)
					cout << x << "\n";
			}
			else
				return;
		}
		select[cnt] = idx;
		cout << "cnt: " << cnt << " idx: " << idx << " sum: " << sum << endl;
		recur(cnt + 1, idx + 1, sum + dwarfs[select[cnt]]);
		idx++;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int input;
	for (int i = 0; i < 9; i++)
	{
		cin >> input;
		dwarfs[i] = input;
	}
	recur(0, 0, 0);
}