#include <stdio.h>

int n, m;
int arr[8];

void rec(int count, int last) {
  if (count == m) {
    for (int i = 0; i < m; i++) printf("%d ", arr[i]);
    printf("\n");
    return;
  }
  for (int i = last + 1; i <= n  - m + count + 1; i++) {
    arr[count] = i;
    rec(count + 1, i);
  }
}

int main(void) {
  scanf("%d %d", &n, &m);
  rec(0, 0);
}

// 오름차순이므로 직전 저장한 숫자 다음에서부터 시작