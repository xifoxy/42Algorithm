#include <iostream>
#include <cstring>

using namespace std;

int k;
bool visit[10];
char input[9];
char num[11];
char mmin[11]; // null 포함
char mmax[11];

int check(char num1, int num2, char opt)
{
	if (opt == '>')
		return (num1 > '0' + num2);
	else
		return (num1 < '0' + num2);
}

void rec(int depth)
{
	if (depth == k + 1)
	{
		if (atoi(mmin) == 0 || !strcmp(mmin, num)) // 왜 거꾸로?
			strcpy(mmin, num);
		if (atoi(mmax) == 0 || strcmp(mmax, num))
			strcpy(mmax, num);
		return;
	}

	for (int i = 0; i <= 9; i++)
	{
		if (depth > 0 && (visit[i] || !check(num[depth - 1], i, input[depth - 1])))
			continue;
		
		num[depth] = '0' + i;
		visit[i] = true;
		rec(depth + 1);
		visit[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> k;
	for (int i = 0; i < k; i++)
		cin >> input[i];
	
	rec(0);
	cout << mmax << "\n" << mmin;
}