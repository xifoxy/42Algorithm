#include <stdio.h>

int arr[4] = {1001, 101, 11, 2};
int arr2[4] = {1026, 117, 18, 0};
int dp[4][11111];
int flag;

int rec(int idx, int n) {
  if (idx == 4) return !!n + 1;
  if (dp[idx][n]) return dp[idx][n];
  int i = 0, m;
  if (n > arr2[idx])
    i = (n - arr2[idx]) / arr[idx] + !!((n - arr2[idx]) % arr[idx]);
  m = i * arr[idx];
  for (; i < 10 && m <= n; i++, m += arr[idx])
    if (rec(idx + 1, n - m) == 1) return dp[idx][n] = 1;
  return dp[idx][n] = 2;
}

int main(void) {
  for (int n = 1; n <= 10000; n++)
    if (rec(0, n) == 2) printf("%d\n", n);
}

// 2231에서 쓴 방식에 dp까지 적용했음