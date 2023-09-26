#include <iostream>

using namespace std;

int n, m, result;
bool visit[30];

void rec(int depth, int cur_m)
{
	if (depth == n)
	{
		result++;
		return;
	}

	for (int i = cur_m; i < m; i++)
	{
		if (visit[cur_m])
			continue;
		
		cur_m = true;
		rec(depth + 1, i + 1);
		cur_m = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		result = 0;
		cin >> n >> m;
		rec(0, 0);
		cout << result << "\n";
	}
	return 0;
}

/*

	n과 m이 주어졌다
	n < m 이며
	각자 하나의 사이트에 다리 하나씩밖에 연결하지 못한다
	모든 경우의 수를 세시오

	n을 depth로 두고 m을 visit 배열로 확인한다

	다리끼리는 겹쳐질수없다 - 다리가 교차되면 안된다...?
	m은 매번 0부터 시작하는게 아니라 이전 depth의 m 이후부터 시작한다

	depth마다 m을 저장하고 매번 이전 depth의 m을 보는식으로 풀어야하나?
*/