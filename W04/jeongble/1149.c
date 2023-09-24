#include <stdio.h>

int main(void) {
  int n;
  scanf("%d", &n);
  int a = 0, b = 0, c = 0;
  for (int i = 0; i < n; i++) {
    int p, q, r;
    scanf("%d %d %d", &p, &q, &r);
    int tmp_a = a, tmp_b = b, tmp_c = c;
    a = p + (tmp_b < tmp_c ? tmp_b : tmp_c);
    b = q + (tmp_a < tmp_c ? tmp_a : tmp_c);
    c = r + (tmp_a < tmp_b ? tmp_a : tmp_b);
  }
  printf("%d\n", a < b ? (a < c ? a : c) : (b < c ? b : c));
}