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
		for (int j = 0; j < i; j++)
			cout << "*";
		cout <<"\n";
	}
}