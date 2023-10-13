#include <iostream>
#include <algorithm>

using namespace std;

/*

	x번째 계단은 x-1 or x-2 (1칸 올라온 경우, 2칸 올라온 경우) 중 큰값과 현재 계단의 값을 더한다
	계단을 연속해서 3개를 밟을수없다....

	2차원 배열로 만들어서 [x][0] 에는 한칸으로 올라왔을때 [x][1] 에는 두칸으로 올라왔을때로 저장?

*/

int stair[300], score[300];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;

	cin >> t;
	for (int i = 0; i < t; i++)
		cin >> stair[i];
	
	score[0] = stair[0];
	score[1] = stair[0] + stair[1];
	score[2] = max(stair[0] + stair[2], stair[1] + stair[2]);
	for (int i = 3; i < t; i++)
		score[i] = max(score[i - 1] - score[i - 3], score[i - 2]) + stair[i];
	
	cout << score[t - 1];
}