#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, input_q, input_s, input_b;
	cin >> n;

	vector<int> question, strike, ball, ball_list;

	for(int i = 0; i < n; i++)
	{
		cin >> input_q >> input_s >> input_b;
		if (find(question.begin(), question.end(), input_q) == question.end())
		{
			question.push_back(input_q);
			strike.push_back(input_s);
			ball.push_back(input_b);
		}
	}

	int result = 0;
	for (int a = 1; a <= 9; a++)
	{
		for (int b = 1; b <= 9; b++)
		{
			if (b == a)
				continue;
			for (int c = 1; c <= 9; c++)
			{
				if (c == a || c == b)
					continue;
				int fail = 0;
				for (int i = 0; i < question.size(); i++)
				{
					int stk_cnt = 0, ball_cnt = 0;

					if (question[i] / 100 == a)
						stk_cnt++;
					else if (question[i] / 10 % 10 == a || question[i] % 10 == a)
						ball_cnt++;
					
					if (question[i] / 10 % 10 == b)
						stk_cnt++;
					else if (question[i] / 100 == b || question[i] % 10 == b)
						ball_cnt++;
					
					if (question[i] % 10 == c)
						stk_cnt++;
					else if (question[i] / 100 == c || question[i] / 10 % 10 == c)
						ball_cnt++;
					
					if (!((stk_cnt == strike[i] && ball_cnt == ball[i])))
					{
						fail = 1;
						break;
					}
				}
				result += (fail == 0);
			}
		}
	}
	cout << result << "\n";
}
/*

	(1) 2 3 4(5)(6)7(8)(9)
	스트라이크가 확정되면 볼은 스트라이크 자리에 있는 숫자들임

	스트라이크가 있는 각 숫자들을 비교해서 같은자리수의 같은수를 찾는다
	볼이 있는 숫자들에서 스트라이크에 들어가는 숫자들은 뺀다
	나머지를 조합한다...?

	2
	123 0 3
	123 0 3
	-> 이 예시에서 ball count 가 3 이므로 모든 숫자는 유효하나 자리가 유효하지 않다
	-> 이 숫자들로 만들수있는 조합은 123 132 213 231 321 312 이다
	-> 이 입력에서 모두 ball이니 해당 자리에 속하지 않는 조합만 살펴본다면
	   231 312 이렇게 두개가 된다

	숫자를 비교할때 값이 같으면 1. 자리까지 같으면 스트라이크, 2. 아니라면 볼

*/