#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, s, cnt = 0;
vector<int> nums;

void rec(int idx, int result)
{
	if (idx == n && result == s)
	{
		cnt++;
		return;
	}

	rec(idx + 1, result);
	rec(idx + 1, result + nums[idx]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	
	cin >> n >> s;

	int input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		nums.push_back(input);
	}

	rec(0, 0);
	if (s == 0)
		cnt --; // 공집합은 빼고 셈
	
	cout << cnt;
}
