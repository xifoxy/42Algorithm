#include <stdio.h>

int n, m;
int arr[8];

void rec(int count, int mask) {
  if (count == m) {
    for (int i = 0; i < m; i++) printf("%d ", arr[i]);
    printf("\n");
    return;
  }
  for (int i = 0; i < n; i++) {
    if (!(mask & (1 << i))) {
      arr[count] = i + 1;
      rec(count + 1, mask | (1 << i));
    }
  }
}

int main(void) {
  scanf("%d %d", &n, &m);
  rec(0, 0);
}

// 마스킹을 통해 안 나온 숫자를 출력