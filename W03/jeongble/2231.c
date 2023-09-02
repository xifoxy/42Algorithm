#include <stdio.h>

int arr[6] = {100001, 10001, 1001, 101, 11, 2};
int arr2[6] = {100044, 10035, 1026, 117, 18, 0};
int res[6];
int flag;

void rec(int idx, int n) {
  if (flag) return;
  if (idx == 6) {
    if (n == 0) {
      int j = 0;
      while (!res[j]) j++;
      while (j < 6) printf("%d", res[j++]);
      flag = 1;
    }
    return;
  }
  int i = 0, m;
  if (n > arr2[idx])
    i = (n - arr2[idx]) / arr[idx] + !!((n - arr2[idx]) % arr[idx]);
  m = i * arr[idx];
  for (; i < 10 && m <= n; i++, m += arr[idx]) {
    res[idx] = i;
    rec(idx + 1, n - m);
  }
}

int main(void) {
  int n;
  scanf("%d", &n);
  rec(0, n);
  if (!flag) printf("0\n");
}

// 뒷자리부터 늘려가며 생성자를 구하는 것이 아니라,
// 앞자리부터 늘려가며 구하면 6자리니까
// 2^6 = 64번만에 가장 작은 생성자를 구할 수 있음