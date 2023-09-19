#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
long long result = -1;
int arr[10][10];

vector<int> visit_record;

void  rec(int depth, int city, long long sum)
{
	if (city >= n)
		return ;

	if  (depth == n - 1 && arr[city][visit_record[0]] != 0)
	{
		if (result == -1 || sum + arr[city][visit_record[0]] < result)
			result = sum + arr[city][visit_record[0]];
		return ;
	}

	visit_record.push_back(city);
	for (int i = 0; i < n; i++)
	{
		if (find(visit_record.begin(), visit_record.end(), i) == visit_record.end() && arr[city][i] != 0) // vector에 없고 갈 수 있는 길이 있을 때
			rec(depth + 1, i, sum + arr[city][i]);
	}
	visit_record.erase(find(visit_record.begin(), visit_record.end(), city));

	if (depth == 0 && city < n)
		rec(0, city + 1, 0);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	int input;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> input;
			arr[i][j] = input;
		}
	}

	rec(0, 0, 0);
	cout << result;
}