#include <iostream>

using namespace std;

int is_hansu(int n)
{
	int dif = -1;
	int temp;
	temp = n;
	
	while (temp)
	{
		if (dif == -1)
			dif = temp % 10 - temp / 10 % 10;
		else if (dif != temp % 10 - temp / 10 % 10)
			return (0);
		temp /= 10;
	}
	return (1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, result;
	cin >> n;

	if (n < 100)
	{
		cout << n << "\n";
		return (0);
	}
	
	result = 99;
	for (int i = 100; i <= n; i++)
		result += is_hansu(i);
	cout << result << "\n";
}