#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
long long result = -1;
int arr[10][10];

vector<int> visit_record;

void rec(int depth, long long sum)
{
	cout << "depth: " << depth << "\n";
	
	if (depth == n - 1)
	{
		cout << "now depth: " << depth << "\n";
		if (arr[visit_record[n - 1]][visit_record[0]] == 0)
		{
			cout << "1sum: " << sum << "\n";
			return;
		}

		sum += arr[visit_record[n - 1]][visit_record[0]];
		if (result == -1 || sum < result)
			result = sum;
		cout << "2sum: " << sum << "\n";
		return ;
	}

	cout << "0sum: " << sum << "\n";
	for (int i = 0; i < n; i++)
	{
		if (arr[depth][i] == 0 || find(visit_record.begin(), visit_record.end(), i) != visit_record.end())
			continue;
		
		visit_record.push_back(i);

		rec(depth + 1, sum + arr[depth][i]);

		visit_record.erase(find(visit_record.begin(), visit_record.end(), i));
	}
	// 첫번째 도시를 기억하고 있어야한다
	// 반드시 마지막 도시에서는 첫번째 도시로 오는 길을 택해야 한다 (이때는 중복 상관없음)
}

int main()
{
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
	
	cout << "bye\n";
	rec(0, 0);
	cout << result;
	cout << "hi\n";
}