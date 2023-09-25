#include <iostream>

using namespace std;

int is_selfnum(int n)
{
	int num = 1;
	while (num < n)
	{
		int result = 0;
		int temp = num;
		while (temp)
		{
			result += temp % 10;
			temp /= 10;
		}
		result += num;
		if (result == n)
			return (0);
		num++;
	}
	return (1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int n = 1; n <= 10000; n++)
		if (is_selfnum(n))
			cout << n << "\n";
}