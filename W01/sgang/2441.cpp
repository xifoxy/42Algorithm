#include <cstdio>
#include <cstring>
const int sz = 1e2 + 1;
int n;
char s[sz];
void line(int star) {
  puts(s);
  s[star] = ' ';
}

void sol(int loop) {
  if (loop == n)
    return;
  line(loop);
  sol(loop + 1);
}

int main() {
  scanf("%d", &n);
  memset(s, '*', n);
  sol(0);
}

// 2440풀이와 비교해보자.