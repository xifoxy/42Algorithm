#include <iostream>
#include <algorithm>

using namespace std;

long long input[10001], score[10001][3], result = 0;

int main()
{
	int n;

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >>input[i];
	
	score[1][1] = input[1];
	score[2][1] = input[2];
	score[2][2] = input[1] + input[2];
	for (int i = 3; i <= n + 2; i++) // - 3 에 맞춰서 범위 확장...어째서??
	{
		score[i][1] = max(max(score[i - 2][1], score[i - 2][2]), max(score[i - 3][1], score[i - 3][2])) + input[i];
		score[i][2] = score[i - 1][1] + input[i];
		result = max(result, max(score[i][1], score[i][2]));
	}
	
	// cout << max(score[n][1], score[n][2]);
	cout << result;
}