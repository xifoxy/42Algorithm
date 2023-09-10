#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, s, cnt = 0;
	vector<int> nums;
	cin >> n >> s;

	int input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		nums.push_back(input);
	}

	for (int i = 0; i < n; i++)
	{
		int result = nums[i];
		if (result == s)
			cnt++;
		for (int j = 0; j < n; j++)
		{
			// if (i == j)
			// {
			// 	cout << "i: " << i << "\n" << "j: " << j << "\n";
			// 	continue;
			// }
			result += nums[j];
			if (result == s)
				cnt++;
		}
	}
	
	cout << cnt;
}
