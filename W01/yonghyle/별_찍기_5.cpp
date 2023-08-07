#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int cnt;
	cin >> cnt;

	for (int i = 1; i <= cnt; i++)
	{
		for (int j = 1; j <= cnt * 2; j++)
		{
			if (j >= cnt - (i - 1) && j <= cnt + (i - 1))
				cout << "*";
			else if (j < cnt - (i - 1))
				cout << " ";
		}
		cout << "\n";
	}
}