#include <iostream>
#include <vector>

using namespace std;

int n, m;
char flag[8];
vector<int> num;

void recur(int depth)
{
	for (int i = 0; i < n; i++)
	{
		if (depth == m)
		{
			for (int j : num)
				cout << j<< " ";
			cout << "\n";
			return ;
		}
		if (i < n && flag[i])
			continue;
		flag[i] = 1;
		num.push_back(i + 1);
		recur(depth + 1);
		num.pop_back();
		flag[i] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	recur(0);
}