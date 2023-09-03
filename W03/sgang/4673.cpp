#include <iostream>
#include <string>
using namespace std;

const int MAX = 1e4 + 1;
bool dp[MAX];
int temp, conNum;
string ans;

int main() {
  for (int i = 1; i < MAX; ++i) {
    temp = i * 10;
    conNum = i;

    while (temp /= 10)
      conNum += (temp % 10);

    dp[conNum] = true;
  }

  for (int i = 1; i < MAX; ++i) {
    if (!dp[i]) {
      ans += to_string(i);
      ans += '\n';
    }
  }
  cout << ans;
}

// 메모하는 배열을 만들면 비교적 쉽게 답을 도출 할 수 있다.