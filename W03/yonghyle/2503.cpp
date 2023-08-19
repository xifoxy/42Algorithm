#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, input, num1 = 0, num2 = 0, num3 = 0;
	cin >> n;

	vector<int> question, strike, ball, ball_list;
	for(int i = 0; i < n; i++)
	{
		cin >> input;
		question.push_back(input);
		cin >> input;
		strike.push_back(input);
		cin >> input;
		ball.push_back(input);
	}

	for(int i = 0; i < n; i++)
	{
		if (strike[i] > 0)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j)
					continue;
				if (strike[j] > 0)
				{
					if (question[i] / 100 == question[j] / 100)
						num1 = question[i] / 100;
					if (question[i] / 10 % 10 == question[j] / 10 % 10)
						num2 = question[i] / 10 % 10;
					if (question[i] % 10 == question[j] % 10)
						num3 = question[i] % 10;
				}
			}
		}
	}

	for(int i = 0; i < n; i++)
	{
		if (ball[i] > 0)
		{
			int stk = strike[i];

			if (stk && (question[i] / 100 == num1))
				;
			else if (ball_list.size() == 0 || find(ball_list.begin(), ball_list.end(), ball_list.size()) != ball_list.end())
				ball_list.push_back(question[i] / 100);

			if (stk && (question[i] / 10 % 10 == num2))
				;
			else if (ball_list.size() == 0 || find(ball_list.begin(), ball_list.end(), ball_list.size()) != ball_list.end())
				ball_list.push_back(question[i] / 10 % 10);
			
			if (stk && (question[i] % 10 == num3))
				;
			else if (ball_list.size() == 0 || find(ball_list.begin(), ball_list.end(), ball_list.size()) != ball_list.end())
				ball_list.push_back(question[i] % 10);
		}
	}

	int empty_cnt = (num1 == 0) + (num2 == 0) + (num3 == 0);
	int result;
	if (empty_cnt == 0)
		result = 1;
	else
		result = empty_cnt * ball_list.size();
	
	cout << result << "\n";
}
/*

	(1) 2 3 4(5)(6)7(8)(9)
	스트라이크가 확정되면 볼은 스트라이크 자리에 있는 숫자들임

	스트라이크가 있는 각 숫자들을 비교해서 같은자리수의 같은수를 찾는다
	볼이 있는 숫자들에서 스트라이크에 들어가는 숫자들은 뺀다
	나머지를 조합한다...?

*/