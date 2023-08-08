#include <cstdio>

int a, b, s, t, d = 1;
int main() {
  scanf("%d %d", &a, &b);
  while (b) {
    s += (t = a * (b % 10)) * d;
    printf("%d\n", t);
    b /= 10;
    d *= 10;
  }
  printf("%d\n", s);
}

// 너무나 어려운 문제다.