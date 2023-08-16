#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, cnt = 0;
	cin >> n;

	long long temp, num = 666;
	while (1)
	{
		temp = num;
		int check = 3;
		while (temp)
		{
			if (temp % 10 == 6)
				check--;
			else if (check != 3)
				check = 3;
			if (check == 0)
			{
				cnt++;
				break;
			}
			temp /= 10;
		}
		if (cnt == n)
		{
			cout << num << "\n";
			return 0;
		}
		num++;
	}
}