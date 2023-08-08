#include <cstdio>
#include <cstring>
const int sz = 1e2 + 1;
int n;
char s[sz];
void line(int star) {
  puts(s);
  s[star] = 0;
}

void sol(int loop) {
  if (!loop)
    return;
  line(loop - 1);
  sol(loop - 1);
}

int main() {
  scanf("%d", &n);
  memset(s, '*', n);
  sol(n);
}

// 2339풀이와 비교해보자.