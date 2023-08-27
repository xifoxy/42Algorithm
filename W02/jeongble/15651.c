#include <stdio.h>

int n, m;
int arr[8];

void rec(int count) {
  if (count == m) {
    for (int i = 0; i < m; i++) printf("%d ", arr[i]);
    printf("\n");
    return;
  }
  for (int i = 1; i <= n; i++) {
    arr[count] = i;
    rec(count + 1);
  }
}

int main(void) {
  scanf("%d %d", &n, &m);
  rec(0);
}

// 여러번 선택해도 되니까 매번 1~n에서 다시 선택