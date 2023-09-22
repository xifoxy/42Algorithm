#include <iostream>

using namespace std;

int n, result;
int input[8];
bool visit[8];

void rec(int depth, int cur_num, int prev_num, int sum)
{
	cout << "depth: " << depth << "\n";
	cout << "prev_num: " << input[prev_num] << "\n";
	cout << "cur_num: " << input[cur_num] << "\n";
	cout << "selected: ";
	for (int i = 0; i < n; i++)
		if (visit[i] == true)
			cout << input[i] << " ";
	cout << "\n";
	cout << "sum: " << sum << "\n";
	cout << "-------------------------\n";

	if (depth == n)
	{
		// sum += abs(input[prev_num] - input[cur_num]);
		// cout << "depth: " << depth << "\ncur_num: " << cur_num << "\nprev_num: " << prev_num << "\nsum: " << sum << "\n";
		
		if (sum > result)
			result = sum;
		return;
	}

	
	for (int i = 0; i < n; i++)
	{
		if (visit[i] == true)
			continue;
		
		visit[i] = true;	
		if (depth == 0)
			rec(depth + 1, i, cur_num, sum);
		else
			rec(depth + 1, i, cur_num, sum + abs(input[prev_num] - input[cur_num]));
		visit[i] = false;
	}
}

// void rec(int depth, int sum)
// {
// 	cout << "depth: " << depth << "\n";
// 	cout << "selected: ";
// 	for (int i = 0; i < n; i++)
// 		if (visit[i] == true)
// 			cout << i << " ";
// 	cout << "\n";
// 	cout << "sum: " << sum << "\n";
// 	cout << "-------------------------\n";

// 	if (depth == n)
// 		return;

// 	for (int i = 0; i < n; i++)
// 	{
// 		if (visit[i])
// 			continue;
		
// 		visit[i] = true;
// 		rec(depth + 1, sum + i);
// 		visit[i] = false;
// 	}
// }

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> input[i];
	
	rec(0, 0, 0, 0);
	// rec(0, 0);
	cout << result;
}