#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int sss = 666;
  vector<int> ssss;
  for (int i = 0; i < 20000; i++)
    for (int j = 1; j < 100000; j *= 10)
      ssss.push_back(i / j * j * 1000 + 666 * j + i % j);

  sort(ssss.begin(), ssss.end());
  unique(ssss.begin(), ssss.end());
  int n;
  cin >> n;
  cout << ssss[n - 1] << endl;
}

// 666을 하나의 숫자라고 생각하고 1~10000에 끼워넣는다고 생각함
// 16에 666을 끼워넣으면 666 16, 1 666 6, 16 666 등의 숫자가 만들어지는데
// 1 666 6, 16 666같이 중복되는 숫자가 있으니 제거해줌