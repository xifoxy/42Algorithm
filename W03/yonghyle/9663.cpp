#include <iostream>

using namespace std;

int n, ans;
int board[15];

bool is_valid(int depth, int i)
{
	for (int check = 1; check <= depth; check++)
	{
		if (board[depth - check] == i) // 가로 공격범위에 해당된다
			return false;
		if (board[depth - check] == i + check || board[depth - check] == i - check) // 대각선 공격범위에 해당된다
			return false;
	}
	return true;
}

void rec(int depth)
{
	if (depth == n)
	{
		ans++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (is_valid(depth, i) == false)
			continue;
		
		board[depth] = i;
		rec(depth + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	rec(0);

	cout << ans << "\n";
}