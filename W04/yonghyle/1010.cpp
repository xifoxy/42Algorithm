#include <iostream>

using namespace std;

int n, m, result;
bool visit[30];

void rec(int depth, int cur_m) // 매개변수로 n차 배열을 만들수있다
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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, m, arr[30][30];
		cin >> n >> m;

		for (int depth = 0; depth < n; depth++)
		{
			for (int cur_m = 0; cur_m < m; m++)
			{
				if (cur_m) // 각 남은 다리의 수에 따라 경우의 수를 저장한다 ex) 2 : 3 일때의 경우의 수 - [2][3] 이런 느낌으로...
			}
		}
	}
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

	hint - 2차원 배열을 사용해야 함
	n = 1 일때를 기준으로 점화식을 세우기...?
	2차원 배열로 어떻게...? [x][y] x와 y를 연결하는 다리를 지었을때 나머지 포함 경우의 수...?
	끝까지 다 놓아야 경우의 수를 구할수 있는게 아닌건지??
	x번째 사이트를 y번째 사이트에 연결 하였을때의 경우의 수, 무슨 경우의 수...?

	2 2
	[0][0] = 1
	[0][1] = [1][n] 은 더이상 연결할곳이 없음
	[1][0] = 다리가 교차됨
	[1][1] = 1

	[0][0] = 2
	[0][1] = 1
	[1][0] = 1
	[1][1] = 1

	1 5
	[0][0] = 5
	[0][1] = 4
	[0][2] = 3
	[0][3] = 2
	[0][4] = 1

	↑↑↑ 반대로 맨 마지막 케이스에서 첫번째 케이스까지 올라가면서 +1 하는 방식으로?
	[x][y] = x, y 까지 오면서 지었던 다리의 수
	이전 경웅의 수를 어떻게 누적해서 불러올것인지? - 점화식의 부재

	2 4
	[0][0] = 1
	[0][1] = 1
	[0][2] = 1
	[0][3] = 0
	[1][0] = 0
	[1][1] = 1
	[1][2] = 1
	[1][3] = 1

*/