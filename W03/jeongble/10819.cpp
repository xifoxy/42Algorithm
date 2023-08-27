#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, res = 0;
int arr[11];

void ddd(int mask, int v, int prev) {
  if (mask == (1 << n) - 1) {
    if (v > res) res = v;
    return;
  }
  for (int i = 0; i < n; i++) {
    if (mask & 1 << i) continue;
    if (mask == 0)
      ddd(mask | 1 << i, v, arr[i]);
    else
      ddd(mask | 1 << i, v + abs(prev - arr[i]), arr[i]);
  }
}

int main(void) {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  ddd(0, 0, 0);
  cout << res << endl;
}

// 2주차에 재귀 푼 거랑 똑같이 모든 순서를 구해주고
// 그것들의 차이를 구해서 최대를 구함