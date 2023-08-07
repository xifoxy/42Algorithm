#include <stdio.h>

int n, m;
int arr[8];

void rec(int count, int last) {
  if (count == m) {
    for (int i = 0; i < m; i++) printf("%d ", arr[i]);
    printf("\n");
    return;
  }
  for (int i = last; i <= n; i++) {
    arr[count] = i;
    rec(count + 1, i);
  }
}

int main(void) {
  scanf("%d %d", &n, &m);
  rec(0, 1);
}

// 15650이랑 비슷한데, 이번엔 비내림차순이면 돼서 직전 저장한 숫자에서 시작