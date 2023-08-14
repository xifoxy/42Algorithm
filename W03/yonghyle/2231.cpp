#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	int num = 1;
	while (1)
	{
		int temp = num;
		int result = 0;
		while (temp)
		{
			result += temp % 10;
			temp /= 10;
		}
		result += num;
		if (num >= n)
		{
			cout << 0 << "\n";
			return 0;
		}
		else if (result == n)
		{
			cout << num << "\n";
			return 0;
		}
		else
			num++;
	}
}