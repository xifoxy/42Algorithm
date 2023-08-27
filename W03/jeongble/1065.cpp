#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int arr[1111], n, res;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 1; i < 10; i++) {
    for (int j = -9; j < 10; j++) {
      int m = 0, a = i;
      for (int k = 0; k < 3 && a >= 0 && a < 10; k++) {
        m = m * 10 + a;
        arr[m] = 1;
        a += j;
      }
    }
  }
  cin >> n;
  for (int i = 0; i <= n; i++)
    if (arr[i]) res++;
  cout << res << endl;
}

// 하나하나 탐색하는 거보다
// 등차수열이 되는 경우들만 구하는 게 더 빠름