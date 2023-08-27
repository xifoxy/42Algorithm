#include <iostream>
#include <string>
using namespace std;

int n, cmp, ans;
string num;

void sol() {
  for (int i = 100; i <= n; ++i) {
    num = to_string(i);
    cmp = num[0] - num[1];
    bool flag = true;

    for (int j = 0; j < num.length() - 1 && flag; ++j)
      if (num[j] - num[j + 1] != cmp)
        flag = false;

    ans += flag;
  }
}

int main() {
  cin >> n;
  sol();
  cout << (n < 100 ? n : 99 + ans) << '\n';
}

// 100이하가 한수인것은 의도적인것인지 모르겠다..?
// 비교를 쉽게 하기 위해 스트링으로 파싱하여 등차를 비교하는 식으로 구현했다.