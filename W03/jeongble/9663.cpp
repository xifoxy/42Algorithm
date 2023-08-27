#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, res = 0;

void nqueen(int index, vector<int> &queens) {
  if (index == n) {
    res++;
    return;
  }
  for (int i = 0; i < n; i++) {
    int j = 0;
    for (; j < index && !(queens[j] == i || queens[j] - j == i - index ||
                          queens[j] + j == i + index);
         j++) {
    }
    if (j == index) {
      queens[index] = i;
      nqueen(index + 1, queens);
    }
  }
}

int main(void) {
  cin >> n;
  vector<int> q(n);
  nqueen(0, q);
  cout << res << endl;
}

// 백트래킹인가 뭐시긴가 했습니다
// 피신 때 처음 이 문제를 풀 때, 함수 5개에 엄청 길게 풀었던 거 같은데
// 다시 푸니까 엄청 짧네요 ㅋㅋ