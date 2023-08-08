#include <cstdio>

const int MX = 1e5 + 1;
int n, arr[MX];
int ans = -1111;

int max(int a, int b) { return a > b ? a : b; }

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &arr[i]);
    arr[i] = max(arr[i] + arr[i - 1], arr[i]);
    ans = max(ans, arr[i]);
  }
  printf("%d\n", ans);
}

// 하나 이상의 구간합이 가장 큰 부분을 구하는 문제이다.
// 복잡하게 생각 할것 없이 이전 배열의 값과 더해서 커지는 구간만 구하면 된다.