#include <iostream>

using namespace std;

int n, result;
int input[8];
bool visit[8];

void rec(int depth, int cur_num, int prev_num, int sum)
{
	if (depth == n)
	{
		cout << "depth: " << depth << "\ncur_num: " << cur_num << "\nprev_num: " << prev_num << "\nsum: " << sum << "\n";
		if (sum > result)
			result = sum;
		return;
		// exit(0);
	}

	visit[cur_num] = true;
	for (int i = 0; i < n; i++)
	{
		// if (depth == 0)
			// cout << "depth: " << depth << "\ncur_num: " << cur_num << "\nprev_num: " << prev_num << "\nsum: " << sum << "\n";
		if (visit[i] == true)
			continue;
		
		cout << "depth: " << depth << "\ncur_num: " << cur_num << "\nprev_num: " << prev_num << "\nsum: " << sum << "\n";
		if (prev_num == 8)
			rec(depth + 1, i, cur_num, sum);
		else
			rec(depth + 1, i, cur_num, sum + abs(input[prev_num] - input[cur_num]));
	}
	visit[cur_num] = false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> input[i];
	
	rec(0, 0, 8, 0);
	cout << result;
}